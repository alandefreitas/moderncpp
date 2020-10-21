#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <vector>

using namespace std;

void sort_vector(vector<int> &v);
void sort_selection(vector<int> &v);
void sort_selection_std(vector<int> &v);
void sort_insertion(vector<int> &v);
void sort_insertion_std(vector<int> &v);
void sort_merge_sort_std(vector<int> &v);
void sort_quicksort_std(vector<int> &v);
int sort_vector_operations(vector<int> &v);

int search_sequential(const vector<int> &v, const int key);
int search_binary(const vector<int> &v, const int key);

pair<int, int> search_sequential_operations(const vector<int> &v,
                                            const int key);
pair<int, int> search_binary_operations(const vector<int> &v, const int key);

int sort_selection_operations(vector<int> &v);
int sort_insertion_operations(vector<int> &v);

int random_number(int low, int high);
void shuffle_vector(vector<int> &v);
vector<int> create_vector(int n);

int main() {
    std::ofstream fout("results.csv");
    constexpr bool use_std = true;
    // Measure real time
    cout << "n\t\tstd\t\tselection_std\t\tinsertion_std\tmerge_sort_std\tquick_"
            "sort_std"
         << endl;
    fout << "n,std,seletion,insertion,mergesort,quicksort" << endl;

    auto increment = [](int i) {
        return pow(10, std::max(int(0), int(ceil(log10(i)) - 2)));
    };

    std::cout << "increment: " << increment(1) << std::endl;
    for (int i = 2; i < 100000000; i += increment(i + 1)) {
        cout << "n=" << i << "\t";
        fout << i << ",";
        if (i < 10) {
            cout << "\t";
        }

        vector<int> v = create_vector(i);

        vector<int> v1 = v;
        auto start = chrono::high_resolution_clock::now();
        sort_vector(v1);
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            chrono::high_resolution_clock::now() - start);
        cout << duration.count() << "μs\t\t";
        fout << duration.count() << ",";

        vector<int> v4 = v;
        start = chrono::high_resolution_clock::now();
        if constexpr (use_std) {
            sort_selection_std(v4);
        } else {
            sort_selection(v4);
        }
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
            chrono::high_resolution_clock::now() - start);
        cout << duration.count() << "μs\t\t";
        fout << duration.count() << ",";

        vector<int> v5 = v;
        start = chrono::high_resolution_clock::now();
        if constexpr (use_std) {
            sort_insertion_std(v5);
        } else {
            sort_insertion(v5);
        }
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
            chrono::high_resolution_clock::now() - start);
        cout << duration.count() << "μs\t\t";
        fout << duration.count() << ",";

        vector<int> v6 = v;
        start = chrono::high_resolution_clock::now();
        sort_merge_sort_std(v6);
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
            chrono::high_resolution_clock::now() - start);
        cout << duration.count() << "μs\t\t";
        fout << duration.count() << ",";

        vector<int> v7 = v;
        start = chrono::high_resolution_clock::now();
        sort_quicksort_std(v7);
        duration = std::chrono::duration_cast<std::chrono::microseconds>(
            chrono::high_resolution_clock::now() - start);
        cout << duration.count() << "μs\t\t";
        fout << duration.count() << ",";

        cout << endl;
        fout << endl;
    }

    cout << "n\t\tstd\t\tselection\t\tinsertion" << endl;
    for (int i = 2; i < 100000000; i *= 2) {
        cout << "n=" << i << "\t";
        if (i < 10) {
            cout << "\t";
        }

        vector<int> v = create_vector(i);

        vector<int> v1 = v;
        int operations = sort_vector_operations(v1);
        cout << operations << "\t\t";

        vector<int> v2 = v;
        operations = sort_selection_operations(v2);
        cout << operations << "\t\t";

        vector<int> v3 = v;
        operations = sort_insertion_operations(v3);
        cout << operations << "\t\t";

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

void sort_selection(vector<int> &v) {
    // índices para loops
    size_t i, j, min;
    // elemento para trocas
    int x;
    // para cada posição
    for (i = 0; i < v.size() - 1; i++) {
        // procuramos o menor entre i + 1 e n e colocamos em i
        // mínimo é o i
        min = i;
        for (j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                // mínimo é o j
                min = j;
            }
        }
        //  troca a[i]  com a[min]
        x = v[min];
        v[min] = v[i];
        v[i] = x;
    }
}

void sort_insertion(vector<int> &v) {
    // índices para loops
    size_t i;
    int j;
    // elemento
    int x;
    // para cada posição a partir de i = 1
    for (i = 1; i < v.size(); i++) {
        // coloca o elemento a[i] na posição correta
        x = v[i];
        j = static_cast<int>(i) - 1;
        // enquanto há posições válidas e
        //    elemento a colocar é menor que o corrente
        while ((j >= 0) && (x < v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        // pega elemento guardado e coloca na posição dele
        v[j + 1] = x;
    }
}

int sort_vector_operations(vector<int> &v) {
    int operations = 0;
    auto comp = [&operations](int a, int b) {
        ++operations;
        return a < b;
    };
    sort(v.begin(), v.end(), comp);
    return operations;
}

int sort_selection_operations(vector<int> &v) {
    int operations = 0;
    // índices para loops
    size_t i, j, min;
    // elemento para trocas
    int x;
    // para cada posição
    for (i = 0; i < v.size() - 1; i++) {
        // procuramos o menor entre i + 1 e n e colocamos em i
        // mínimo é o i
        min = i;
        for (j = i + 1; j < v.size(); j++) {
            ++operations;
            if (v[j] < v[min]) {
                // mínimo é o j
                min = j;
            }
        }
        //  troca a[i]  com a[min]
        x = v[min];
        v[min] = v[i];
        v[i] = x;
    }
    return operations;
}

int sort_insertion_operations(vector<int> &v) {
    int operations = 0;
    // índices para loops
    size_t i;
    int j;
    // elemento
    int x;
    // para cada posição a partir de i = 1
    for (i = 1; i < v.size(); i++) {
        // coloca o elemento a[i] na posição correta
        x = v[i];
        j = static_cast<int>(i) - 1;
        // enquanto há posições válidas e
        //    elemento a colocar é menor que o corrente
        ++operations;
        while ((j >= 0) && (x < v[j])) {
            v[j + 1] = v[j];
            j--;
            ++operations;
        }
        // pega elemento guardado e coloca na posição dele
        v[j + 1] = x;
    }
    return operations;
}

void sort_selection_std(vector<int> &v) {
    for (auto i = v.begin(); i != v.end() - 1; ++i) {
        iter_swap(i, min_element(i, v.end()));
    }
}

void sort_insertion_std(vector<int> &v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        rotate(upper_bound(v.begin(), i, *i), i, i + 1);
    }
}

template <typename Iterador> void merge_sort(Iterador start, Iterador fim) {
    if (fim - start > 1) {
        Iterador meio = start + (fim - start) / 2;
        merge_sort(start, meio);
        merge_sort(meio, fim);
        std::vector<int> intercalado(fim - start);
        merge(start, meio, meio, fim, intercalado.begin());
        std::copy(intercalado.begin(), intercalado.end(), start);
    }
}

void sort_merge_sort_std(vector<int> &v) { merge_sort(v.begin(), v.end()); }

template <typename Iterador>
void in_place_merge_sort(Iterador start, Iterador fim) {
    if (fim - start > 1) {
        Iterador meio = start + (fim - start) / 2;
        in_place_merge_sort(start, meio);
        in_place_merge_sort(meio, fim);
        inplace_merge(start, meio, fim);
    }
}

void sort_in_place_merge_sort_std(vector<int> &v) {
    in_place_merge_sort(v.begin(), v.end());
}

// helper function for median of three
template <typename T> T median(T t1, T t2, T t3) {
    if (t1 < t2) {
        if (t2 < t3)
            return t2;
        else if (t1 < t3)
            return t3;
        else
            return t1;
    } else {
        if (t1 < t3)
            return t1;
        else if (t2 < t3)
            return t3;
        else
            return t2;
    }
}

// Helper object to get <= from <
template <typename Order>
struct non_strict_op
    : public std::binary_function<typename Order::second_argument_type,
                                  typename Order::first_argument_type, bool> {
    non_strict_op(Order o) : order(o) {}
    bool operator()(typename Order::second_argument_type arg1,
                    typename Order::first_argument_type arg2) const {
        return !order(arg2, arg1);
    }

  private:
    Order order;
};

template <typename Order> non_strict_op<Order> non_strict(Order o) {
    return non_strict_op<Order>(o);
}

template <typename RandomAccessIterator, typename Order>
void quicksort(RandomAccessIterator first, RandomAccessIterator last,
               Order order) {
    if (first != last && first + 1 != last) {
        typedef typename std::iterator_traits<RandomAccessIterator>::value_type
            value_type;
        RandomAccessIterator mid = first + (last - first) / 2;
        value_type pivot = median(*first, *mid, *(last - 1));
        RandomAccessIterator split1 = std::partition(
            first, last, std::bind(order, std::placeholders::_1, pivot));
        RandomAccessIterator split2 = std::partition(
            split1, last,
            std::bind(non_strict(order), std::placeholders::_1, pivot));
        quicksort(first, split1, order);
        quicksort(split2, last, order);
    }
}

template <typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last) {
    quicksort(
        first, last,
        std::less<
            typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

void sort_quicksort_std(vector<int> &v) { quicksort(v.begin(), v.end()); }

int random_number(int low, int high) {
    static random_device r;
    static default_random_engine generator(r());
    uniform_int_distribution<int> ud(low, high);
    return ud(generator);
}

vector<int> create_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    shuffle_vector(v);
    return v;
}

int search_sequential(const vector<int> &v, const int key) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

int search_binary(const vector<int> &v, const int key) {
    int left = 0;
    int right = v.size() - 1;
    int i;
    do {
        i = (left + right) / 2;
        if (v[i] < key) {
            left = i + 1;
        } else {
            right = i - 1;
        }
    } while (v[i] != key && left <= right);
    if (v[i] == key) {
        return i;
    } else {
        return -1;
    }
}

pair<int, int> search_sequential_operations(const vector<int> &v,
                                            const int key) {
    int operations = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        operations++;
        if (v[i] == key) {
            return {i, operations};
        }
        operations++;
    }
    return {-1, operations};
}

pair<int, int> search_binary_operations(const vector<int> &v, const int key) {
    int left = 0;
    int right = v.size() - 1;
    int i;
    int operations = 0;
    do {
        i = (left + right) / 2;
        operations++;
        if (v[i] < key) {
            left = i + 1;
        } else {
            right = i - 1;
        }
        operations++;
    } while (v[i] != key && left <= right);
    operations++;
    if (v[i] == key) {
        return {i, operations};
    } else {
        return {-1, operations};
    }
}
