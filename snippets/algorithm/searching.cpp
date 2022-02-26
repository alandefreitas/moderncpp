#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

void call_sequential(const std::vector<int> &v);
void call_binary(const std::vector<int> &v);

int main() {


    //[construct Create vector for searching
    std::vector v = {5, 4, 9, 8, 6, 3};
    //]

    //[find Sequential search from the standard library
    // - std::find is what you would use daily
    // - don't implement your own version unless you're studying the algorithms
    auto i1 = std::find(v.begin(), v.end(), 6);
    if (i1 != v.end()) {
        std::cout << "*i1: " << *i1 << '\n';
    }
    std::cout << "position: " << i1 - v.begin() << '\n';
    //]

    //[sort_vec Prepare vector for binary search
    sort(v.begin(), v.end());
    //]

    //[lower_bound Binary search from the standard library
    // - std::lower_bound is what you would use daily
    // - don't implement your own version unless you're studying the algorithms
    auto i2 = lower_bound(v.begin(), v.end(), 6);
    if (i2 != v.end()) {
        std::cout << "*i2: " << *i2 << '\n';
    }
    std::cout << "position: " << i2 - v.begin() << '\n';
    //]

    call_sequential(v);
    call_binary(v);

    return 0;
}

//[find_subscript Textbook sequential search based on subscripts
// This is what you would probably learn in college
// Example only. Use std::find instead.
size_t sequential_find(const std::vector<int> &v, const int key) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            return i;
        }
    }
    // return a sentinel
    return v.size();
}
//]

//[find_iterators C++ sequential search based on iterators
// This is what works in C++ for most container types.
// Example only. Use std::find instead.
template <class It, class T>
constexpr It sequential_find(It first, It last, const T &value) {
    for (; first != last; ++first) {
        // Best: O(1)
        // Worst: O(n)
        // Average: O(n)
        if (*first == value) {
            return first;
        }
    }
    // return a sentinel
    return last;
}
//]

void call_sequential(const std::vector<int> &v) {
    //[call_sequential Call sequential search (vector + the textbook convention)
    size_t pos1 = sequential_find(v, 6);
    if (pos1 != v.size()) {
        std::cout << "value: " << v[pos1] << '\n';
    }
    std::cout << "position: " << pos1 << '\n';
    //]

    //[call_seq_iter Sequential search (iterators + the C++ convention)
    auto it1 = sequential_find(v.begin(), v.end(), 6);
    if (it1 != v.end()) {
        std::cout << "*it1: " << *it1 << '\n';
    }
    std::cout << "position: " << it1 - v.begin() << '\n';
    //]
}

//[binary_find_subscript Textbook binary search based on subscripts
// This is what you would probably learn in college
// Example only. Use std::lower_bound instead.
size_t binary_find(const std::vector<int> &v, const int key) {
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
//]

//[binary_find_iterators C++ binary search based on iterators
// This is what works in C++ for most container types.
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
//]

void call_binary(const std::vector<int> &v) {
    //[call_binary Binary search (vector + the textbook convention)
    size_t pos2 = binary_find(v, 6);
    if (pos2 != v.size()) {
        std::cout << "value: " << v[pos2] << '\n';
    }
    std::cout << "position: " << pos2 << '\n';
    //]

    //[call_iter_binary Binary search (iterators + the C++ convention)
    auto it2 = binary_find(v.begin(), v.end(), 6);
    if (it2 != v.end()) {
        std::cout << "*it2: " << *it2 << '\n';
    }
    std::cout << "position: " << it2 - v.begin() << '\n';
    //]
}