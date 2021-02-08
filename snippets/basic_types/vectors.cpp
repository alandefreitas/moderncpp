#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Dynamic size vector
    vector<int> v = {1, 2, 3};
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "v[" << i << "]: " << v[i] << endl;
    }
    cout << "v.size(): " << v.size() << endl;
    cout << "v.empty(): " << v.empty() << endl;
    cout << "v.front(): " << v.front() << endl;
    cout << "v.back(): " << v.back() << endl;
    cout << "&v: " << &v << endl;
    cout << "&v[0]: " << &v[0] << endl;
    cout << "&v[1]: " << &v[1] << endl;
    cout << "&v[2]: " << &v[2] << endl;

    // We might still need the underlying raw vector
    // to interact with old code
    cout << "Underlying raw vector - v.data(): " << v.data() << endl;

    // vector<T,N> has no fixed size in bytes
    // sizeof(v) has only the size of the pointers to manage v
    cout << "sizeof(v): " << sizeof(v) << endl;

    // Multidimensional vector
    vector<vector<double>> matrix(10, vector<double>(3, 0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = 0.5 * i + 0.8 * j;
        }
    }

    for (const auto &row : matrix) {
        double sum = 0.;
        for (const auto &col : row) {
            sum += col;
        }
        cout << "Row average " << sum / row.size() << endl;
    }

    return 0;
}
