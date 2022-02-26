//[headers Headers
#include <array>
//]
#include <iostream>
#include <string>

int main() {
    //[fixed Fixed size array
    constexpr int n = 3;
    std::array<int, n> a = {1, 2, 3};
    //]

    //[iter Iterate arrays
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << "a[" << i << "]: " << a[i] << '\n';
    }
    //]

    //[member Member functions
    std::cout << "a.size(): " << a.size() << '\n';
    std::cout << "a.empty(): " << a.empty() << '\n';
    std::cout << "a.front(): " << a.front() << '\n';
    std::cout << "a.back(): " << a.back() << '\n';
    //]

    //[access Accessing elements
    std::cout << "a[0]: " << a[0] << '\n';
    std::cout << "a[1]: " << a[1] << '\n';
    std::cout << "a[2]: " << a[2] << '\n';
    //]

    //[access Accessing addresses
    std::cout << "&a: " << &a << '\n';
    std::cout << "&a[0]: " << &a[0] << '\n';
    std::cout << "&a[1]: " << &a[1] << '\n';
    std::cout << "&a[2]: " << &a[2] << '\n';
    //]

    //[get Underlying raw array
    // We might still need the underlying raw array
    // to interact with old code
    std::cout << "Underlying raw array - a.data(): " << a.data() << '\n';
    //]

    //[size Array size
    // array<T,N> has a fixed size in bytes
    std::cout << "sizeof(a): " << sizeof(a) << '\n';
    //]

    //[multidim Multidimensional array
    std::array<std::array<double, 3>, 10> matrix;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = 0.5 * i + 0.8 * j;
        }
    }
    //]

    //[forrange Range-based loop
    for (const auto &row : matrix) {
        double sum = 0.;
        for (const auto &col : row) {
            sum += col;
        }
        std::cout << "Row average " << sum / row.size() << '\n';
    }
    //]

    return 0;
}
