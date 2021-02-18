#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

struct Foo {
    int i;
    char c;
    double d;
};

/// Min and max elements from a vector
/// \param v Vector
/// \return Min
/// \return Max
std::pair<int, int> minmax(std::vector<int> &v) {
    // unpack tuple of iterators with min and max
    auto [min_iter, max_iter] = minmax_element(v.begin(), v.end());
    return std::make_pair(*min_iter, *max_iter);
}

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
    using namespace std;

    // Unpacking pairs
    vector<int> v = {7, 3, 9, 3, 1, 7, 4, 9};
    auto [min_value, max_value] = minmax(v);
    cout << "min_value: " << min_value << endl;
    cout << "max_value: " << max_value << endl;

    // Unpacking tuples
    auto [total, mean, variance, stddev] = stats(v);
    cout << "total: " << total << endl;
    cout << "mean: " << mean << endl;
    cout << "variance: " << variance << endl;
    cout << "stddev: " << stddev << endl;

    // Unpacking structs
    Foo f{1, 'a', 2.3};
    auto [i, c, d] = f;
    cout << "f.i: " << i << endl;
    cout << "f.c: " << c << endl;
    cout << "f.d: " << d << endl;

    // Creating references
    auto &[i2, c2, d2] = f;
    cout << "i2: " << i2 << endl;
    cout << "c2: " << c2 << endl;
    cout << "d2: " << d2 << endl;

    // Unpacking native arrays
    int a[2] = {1, 2};
    auto [x, y] = a;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    // rvalue reference in range based loop
    map<string, int> my_map = {
        {"hello", 1},
        {"world", 2},
        {"it's", 3},
        {"me", 4},
    };
    for (auto &&[key, value] : my_map) {
        cout << "key=" << key << " value=" << value << endl;
    }

    // Getting iterator from the insert function
    if (auto [iter, success] = my_map.insert(make_pair("Bye", 5)); success) {
        auto &[key, value] = *iter;
        cout << "insert is successful. The value is " << quoted(key) << '\n';
    } else {
        auto &[key, value] = *iter;
        cout << "The value " << quoted(key) << " already exists in the set\n";
    }

    return 0;
}
