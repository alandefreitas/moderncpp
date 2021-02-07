#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> v(30, 1.0);

    // Copying v
    std::vector<double> v2 = v;

    std::cout << "v1: ";
    std::for_each(v.begin(), v.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << std::endl;

    std::cout << "v2: ";
    std::for_each(v.begin(), v.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << std::endl;

    // Moving v
    // - std::move casts v to an rvalue
    std::vector<double> v3 = std::move(v);

    std::cout << "v1: ";
    // NOLINTNEXTLINE(bugprone-use-after-move): making a point
    std::for_each(v.begin(), v.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << std::endl;

    std::cout << "v3: ";
    std::for_each(v3.begin(), v3.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << std::endl;

    return 0;
}