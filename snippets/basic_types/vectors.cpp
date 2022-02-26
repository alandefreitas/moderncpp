#include <iostream>
#include <string>
//[headers Headers
#include <vector>
//]
#include <list>

int main() {
    //[declare Dynamic size vector
    std::vector<int> v = {1, 2, 3};
    //]

    //[iter Iterate vector elements
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "v[" << i << "]: " << v[i] << '\n';
    }
    //]

    //[member Member functions
    std::cout << "v.size(): " << v.size() << '\n';
    std::cout << "v.empty(): " << v.empty() << '\n';
    std::cout << "v.front(): " << v.front() << '\n';
    std::cout << "v.back(): " << v.back() << '\n';
    //]

    //[addresses Access addresses
    std::cout << "&v: " << &v << '\n';
    std::cout << "&v[0]: " << &v[0] << '\n';
    std::cout << "&v[1]: " << &v[1] << '\n';
    std::cout << "&v[2]: " << &v[2] << '\n';
    //]

    //[iter Iterators
    auto it = v.begin();
    std::cout << *it << '\n';
    //]

    //[modify Modify vector
    v.push_back(5);
    //]

    //[get Underlying array
    // We might still need the underlying raw array to interact with old code
    std::cout << "Underlying raw vector: " << v.data() << '\n';
    //]

    //[sizeof Vector inline size
    // vector<T,N> has no fixed size in bytes
    // sizeof(v) has only the size of the pointers to manage v
    std::cout << "sizeof(v): " << sizeof(v) << '\n';
    //]

    //[multidim Multidimensional vector
    std::vector<std::vector<double>> matrix(10, std::vector<double>(3, 0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = 0.5 * i + 0.8 * j;
        }
    }
    //]

    //[multidim_range Multidimensional range-based loops
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
