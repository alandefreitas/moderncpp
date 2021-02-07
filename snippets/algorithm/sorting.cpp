#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

using namespace std;

// Selection sort
template <class It, class C> void selection_sort(It first, It last, C comp) {
    for (auto it = first; it != last - 1; ++it) {
        iter_swap(it, min_element(it, last, comp));
    }
}

template <class It> void selection_sort(It first, It last) {
    selection_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}

// Insertion sort
template <class It, class C> void insertion_sort(It first, It last, C comp) {
    for (auto i = first; i != last; ++i) {
        rotate(upper_bound(first, i, *i, comp), i, i + 1);
    }
}

template <class It> void insertion_sort(It first, It last) {
    insertion_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}

// Mergesort
template <class It, class C> void merge_sort(It first, It last, C comp) {
    if (last - first > 1) {
        It middle = first + (last - first) / 2;
        merge_sort(first, middle, comp);
        merge_sort(middle, last, comp);
        inplace_merge(first, middle, last, comp);
    }
}

template <class It> void merge_sort(It first, It last) {
    merge_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}

// Helper function for median of three values
template <typename T, class C> constexpr T median(T t1, T t2, T t3, C comp) {
    return (comp(t1, t2)) ? ((comp(t2, t3)) ? t2 : ((comp(t1, t3)) ? t3 : t1))
                          : ((comp(t1, t3)) ? t1 : ((comp(t2, t3)) ? t3 : t2));
}

template <class It> void median(It first, It last) {
    median(first, last, std::less<std::decay_t<decltype(*first)>>());
}

// Quicksort
template <class It, class C> void quick_sort(It first, It last, C comp) {
    if (first != last && std::next(first) != last) {
        It middle = first + (last - first) / 2;
        auto pivot = median(*first, *middle, *std::prev(last), comp);
        It split1 = partition(first, last, [&](auto x) { return comp(x, pivot); });
        It split2 = partition(split1, last, [&](auto x) { return !comp(pivot, x); });
        quick_sort(first, split1, comp);
        quick_sort(split2, last, comp);
    }
}

template <class It> void quick_sort(It first, It last) {
    quick_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}

int main() {
    // Create vector for searching
    vector v = {5, 4, 9, 8, 6, 3};

    // Sort
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    v = {5, 4, 9, 8, 6, 3};
    // Selection sort
    selection_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    v = {5, 4, 9, 8, 6, 3};
    // Insertion sort
    insertion_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    v = {5, 4, 9, 8, 6, 3};
    // Mergesort
    merge_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    v = {5, 4, 9, 8, 6, 3};
    // Quicksort
    quick_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    return 0;
}