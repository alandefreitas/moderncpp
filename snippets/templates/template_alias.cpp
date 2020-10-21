#include <array>
#include <iostream>
#include <string>

using namespace std;

// Template alias for two-dimensional arrays
// - This is only an example
// - We would't really do that in practice
template <class T, size_t N_ROWS, size_t N_COLUMNS>
using matrix = array<array<T, N_COLUMNS>, N_ROWS>;

int main() {
    matrix<double, 10, 3> m;
    double i = 5.6;
    for (auto &row : m) {
        for (auto &xij : row) {
            xij = i++;
        }
    }

    for (auto &row : m) {
        for (auto &xij : row) {
            cout << "xij: " << xij << endl;
        }
    }

    return 0;
}
