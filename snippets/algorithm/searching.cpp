#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

using namespace std;

// Usual implementation based on subscripts
// - What you would probably learn in school
size_t sequential_find(const vector<int> &v, const int key) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            return i;
        }
    }
    // return a sentinel
    return v.size();
}

// Implementation based on iterators
// - Example only. Use std::find instead.
// - What works for more container types.
template <class It, class T>
constexpr It sequential_find(It first, It last, const T &value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    // return a sentinel
    return last;
}

// Usual implementation based on subscripts
// - What you would probably learn in school
size_t binary_find(const vector<int> &v, const int key) {
    size_t left_idx = 0;
    size_t right_idx = v.size() - 1;
    size_t i;
    do {
        i = (left_idx + right_idx) / 2;
        if (v[i] < key) {
            left_idx = i + 1;
        } else {
            right_idx = i - 1;
        }
    } while (v[i] != key && left_idx <= right_idx);
    return v[i] == key ? i : v.size();
}

// Example only. Use std::lower_bound instead.
template <class It, class T>
It binary_find(It first, It last, const T &value) {
    typename std::iterator_traits<It>::difference_type count, step;
    It it;
    count = std::distance(first, last);
    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (*it < value) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

int main() {
    // Create vector for searching
    vector v = {5, 4, 9, 8, 6, 3};

    // Sequential search (std library)
    auto i1 = find(v.begin(), v.end(), 6);
    if (i1 != v.end()) {
        cout << "*i1: " << *i1 << '\n';
    }
    cout << "position: " << i1 - v.begin() << '\n';

    // Sequential search (vector / the textbook convention)
    size_t pos1 = sequential_find(v, 6);
    if (pos1 != v.size()) {
        cout << "value: " << v[pos1] << '\n';
    }
    cout << "position: " << pos1 << '\n';

    // Sequential search (iterators / the C++ convention)
    auto it1 = sequential_find(v.begin(), v.end(), 6);
    if (it1 != v.end()) {
        cout << "*it1: " << *it1 << '\n';
    }
    cout << "position: " << it1 - v.begin() << '\n';

    // Prepare vector for binary search
    sort(v.begin(), v.end());

    // Binary search (std library)
    auto i2 = lower_bound(v.begin(), v.end(), 6);
    if (i2 != v.end()) {
        cout << "*i2: " << *i2 << '\n';
    }
    cout << "position: " << i2 - v.begin() << '\n';

    // Binary search (vector / the textbook convention)
    size_t pos2 = binary_find(v, 6);
    if (pos2 != v.size()) {
        cout << "value: " << v[pos2] << '\n';
    }
    cout << "position: " << pos2 << '\n';

    // Binary search (iterators / the C++ convention)
    auto it2 = binary_find(v.begin(), v.end(), 6);
    if (it2 != v.end()) {
        cout << "*it2: " << *it2 << '\n';
    }
    cout << "position: " << it2 - v.begin() << '\n';

    return 0;
}
