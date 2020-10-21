#include <array>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void shuffle_vector(vector<int> &v);
void sort_vector(vector<int> &v);
int random_number(int low, int high);
vector<int> generate_vector(int n);
int sequential_search(const vector<int> &v, const int key);
int binary_search(const vector<int> &v, const int key);
pair<int, int> sequential_search_operations(const vector<int> &v,
                                            const int key);
pair<int, int> binary_search_operations(const vector<int> &v, const int key);

int main() {
    // alias to "now" function
    const auto &now = chrono::high_resolution_clock::now;

    // Real time experiment
    cout << "n\t\tpos\t\t\tsequential\tsorting\tbinary" << endl;
    for (int i = 2; i < 100000000; i *= 2) {
        // header
        cout << "n=" << i << "\t";
        if (i < 10) {
            cout << "\t";
        }

        // create vector and key
        vector<int> v = generate_vector(i);
        int key = random_number(0, i - 1);

        // measure time with sequential search
        auto start_time = now();
        int pos = sequential_search(v, key);
        auto duration = now() - start_time;
        cout << "pos=" << pos << "\t\t";
        cout << duration.count() << "ms\t\t";

        // measure time to sort
        start_time = now();
        sort_vector(v);
        duration = now() - start_time;
        cout << duration.count() << "ms\t\t";

        // measure time with binary search
        start_time = now();
        pos = binary_search(v, key);
        duration = now() - start_time;
        cout << duration.count() << "ms\t";

        cout << endl;
    }

    // Count operations
    cout << "n\t\tpos\t\t\tsequential\tsorting\tbinary" << endl;
    for (int i = 2; i < 100000000; i *= 2) {
        // header
        cout << "n=" << i << "\t";
        if (i < 10) {
            cout << "\t";
        }

        // create vector
        vector<int> v = generate_vector(i);
        int key = random_number(0, i - 1);

        // count operations with sequential search
        auto [pos, operations] = sequential_search_operations(v, key);
        cout << "pos=" << pos << "\t\t";
        cout << operations << "\t\t";

        // estimate operations to sort
        sort_vector(v);
        cout << v.size() * log2(v.size()) << "\t\t";

        // count operations with binary search
        auto [pos2, operations2] = binary_search_operations(v, key);
        cout << operations2 << "\t";

        cout << endl;
    }

    return 0;
}

void shuffle_vector(vector<int> &v) {
    static random_device r;
    static default_random_engine generator(r());
    shuffle(v.begin(), v.end(), generator);
}

void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }

int random_number(int low, int high) {
    static random_device r;
    static default_random_engine generator(r());
    uniform_int_distribution<int> ud(low, high);
    return ud(generator);
}

vector<int> generate_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    shuffle_vector(v);
    return v;
}

int sequential_search(const vector<int> &v, const int key) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(const vector<int> &v, const int key) {
    int esq = 0;
    int dir = v.size() - 1;
    int i;
    do {
        i = (esq + dir) / 2;
        if (v[i] < key) {
            esq = i + 1;
        } else {
            dir = i - 1;
        }
    } while (v[i] != key && esq <= dir);
    if (v[i] == key) {
        return i;
    } else {
        return -1;
    }
}

pair<int, int> sequential_search_operations(const vector<int> &v,
                                            const int key) {
    int operations = 0;
    for (int i = 0; i < v.size(); ++i) {
        operations++;
        if (v[i] == key) {
            return {i, operations};
        }
        operations++;
    }
    return {-1, operations};
}

pair<int, int> binary_search_operations(const vector<int> &v, const int key) {
    int esq = 0;
    int dir = v.size() - 1;
    int i;
    int operations = 0;
    do {
        i = (esq + dir) / 2;
        operations++;
        if (v[i] < key) {
            esq = i + 1;
        } else {
            dir = i - 1;
        }
        operations++;
    } while (v[i] != key && esq <= dir);
    operations++;
    if (v[i] == key) {
        return {i, operations};
    } else {
        return {-1, operations};
    }
}
