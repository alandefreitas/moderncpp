#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

/// Min and max elements from a vector
/// \param v Vector
/// \return Min
/// \return Max
std::pair<int, int> minmax(std::vector<int> &v);

/// Mean, variance, and std deviation
/// \param v Vector
/// \return Total
/// \return Mean
/// \return Variance
/// \return Deviation
std::tuple<int, double, double, double> stats(std::vector<int> &v) {
    int total = accumulate(v.begin(), v.end(), 0);
    double mean = static_cast<double>(total) / v.size();
    double variance =
        accumulate(v.begin(), v.end(), 0.0,
                   [mean](double sum, int elem) {
                       return sum + (static_cast<double>(elem) - mean) *
                                        (static_cast<double>(elem) - mean);
                   }) /
        (v.size() - 1);
    double stddev = sqrt(variance);
    return std::make_tuple(total, mean, variance, stddev);
}

int main() {
    //[pairs Unpacking pairs
    std::vector<int> v = {7, 3, 9, 3, 1, 7, 4, 9};
    auto [min_value, max_value] = minmax(v);
    std::cout << "min_value: " << min_value << '\n';
    std::cout << "max_value: " << max_value << '\n';
    //]

    //[tuples Unpacking tuples
    // `stats` returns `std::tuple<int, double, double, double>`
    auto [total, mean, variance, stddev] = stats(v);
    std::cout << "total: " << total << '\n';
    std::cout << "mean: " << mean << '\n';
    std::cout << "variance: " << variance << '\n';
    std::cout << "stddev: " << stddev << '\n';
    //]

    //[declstruct Declare struct
    struct Foo {
        int i;
        char c;
        double d;
    };
    //]

    //[struct Unpacking structs
    Foo f{1, 'a', 2.3};
    auto [i, c, d] = f;
    std::cout << "f.i: " << i << '\n';
    std::cout << "f.c: " << c << '\n';
    std::cout << "f.d: " << d << '\n';
    //]

    //[references Creating references
    auto &[i2, c2, d2] = f;
    std::cout << "i2: " << i2 << '\n';
    std::cout << "c2: " << c2 << '\n';
    std::cout << "d2: " << d2 << '\n';
    //]

    //[arrays Unpacking raw arrays
    int a[2] = {1, 2};
    auto [x, y] = a;
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    //]

    //[map range-based loop
    std::map<std::string, int> my_map = {
        {"hello", 1},
        {"world", 2},
        {"it's", 3},
        {"me", 4},
    };
    for (auto &&[key, value] : my_map) {
        std::cout << "key=" << key << " value=" << value << '\n';
    }
    //]

    //[iter_insert Getting iterator from the insert function
    if (auto [iter, success] = my_map.insert(std::make_pair("Bye", 5)); success) {
        auto &[key, value] = *iter;
        std::cout << "insert is successful. The value is " << quoted(key) << '\n';
    } else {
        auto &[key, value] = *iter;
        std::cout << "The value " << quoted(key) << " already exists in the set\n";
    }
    //]

    return 0;
}

//[minmax Get min and max elements from a vector
std::pair<int, int> minmax(std::vector<int> &v) {
    // unpack tuple of iterators with min and max
    auto [min_iter, max_iter] = std::minmax_element(v.begin(), v.end());
    return std::make_pair(*min_iter, *max_iter);
}
//]