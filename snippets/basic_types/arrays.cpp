#include <array>
#include <iostream>
#include <string>

int main() {
    using namespace std;

    constexpr int n = 3;

    // Fixed size array
    array<int, n> a = {1, 2, 3};
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "a[" << i << "]: " << a[i] << endl;
    }
    cout << "a.size(): " << a.size() << endl;
    cout << "a.empty(): " << a.empty() << endl;
    cout << "a.front(): " << a.front() << endl;
    cout << "a.back(): " << a.back() << endl;
    cout << "&a: " << &a << endl;
    cout << "&a[0]: " << &a[0] << endl;
    cout << "&a[1]: " << &a[1] << endl;
    cout << "&a[2]: " << &a[2] << endl;

    // We might still need the underlying raw array
    // to interact with old code
    cout << "Underlying raw array - a.data(): " << a.data() << endl;

    // array<T,N> has a fixed size in bytes
    cout << "sizeof(a): " << sizeof(a) << endl;

    // Multidimensional array
    array<array<double, 3>, 10> matrix;
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
