#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
//[headers Headers
#include <utility>
//]

int main() {
    //[copy Copying a vector
    std::vector<double> v1(30, 1.0);
    std::vector<double> v2 = v1;
    //]

    //[iterate_1 Both vectors are valid
    std::cout << "v1: ";
    for (double x: v1) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::cout << "v2: ";
    for (double x: v2) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    //]

    //[copy Moving a vector
    std::vector<double> v3 = std::move(v1);
    //]

    //[iterate_2 The vector moved-from is invalidated
    std::cout << "v1: ";
    // NOLINTNEXTLINE(bugprone-use-after-move): making a point
    for (double x: v1) {
        std::cout << x << " "; // prints nothing
    }
    std::cout << '\n';

    std::cout << "v3: ";
    for (double x: v3) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    //]

    return 0;
}