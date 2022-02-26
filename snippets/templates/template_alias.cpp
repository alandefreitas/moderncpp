#include <array>
#include <iostream>
#include <string>

//[alias Template alias for two-dimensional arrays
template <class T, size_t N_ROWS, size_t N_COLUMNS>
using matrix = std::array<std::array<T, N_COLUMNS>, N_ROWS>;
//]

int main() {
    //[use_alias Using a template alias
    matrix<double, 10, 3> m;
    double i = 5.6;
    for (auto &row : m) {
        for (auto &xij : row) {
            xij = i++;
        }
    }
    //]

    //[use_matrix Iterating the matrix
    for (auto &row : m) {
        for (auto &xij : row) {
            std::cout << "xij: " << xij << '\n';
        }
    }
    //]

    return 0;
}
