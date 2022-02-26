#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

void call_custom_sort();

int main() {
    //[vec Create vector for sorting
    std::vector<int> v = {5, 4, 9, 8, 6, 3};
    //]

    //[sort Sorting
    // - std::sort is what you would use daily
    // - don't implement your own version unless you're studying the algorithms
    std::sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    v = {5, 4, 9, 8, 6, 3};
    //[stable_sort Stable sorting
    // Elements that compare equal don't change their relative positions
    std::stable_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    v = {5, 4, 9, 8, 6, 3};
    //[stable_sort Partial sorting
    // Sort first two elements
    std::partial_sort(v.begin(), v.begin() + 2, v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    call_custom_sort();

    return 0;
}

//[selection Selection sort: O(n^2)
template <class It, class C> void selection_sort(It first, It last, C comp) {
    // For each position
    for (auto it = first; it != std::prev(last); ++it) {
        // Swap the current with the min_element
        std::iter_swap(it, std::min_element(it, last, comp));
    }
}

template <class It> void selection_sort(It first, It last) {
    // If no comparison function is provided, use `std::less`
    selection_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}
//]

//[insertion Insertion sort: O(n^2)
template <class It, class C> void insertion_sort(It first, It last, C comp) {
    // For each position
    for (auto i = std::next(first); i != last; ++i) {
        // Push the element to the sorted subarray to the left
        rotate(upper_bound(first, i, *i, comp), i, i + 1);
    }
}

template <class It> void insertion_sort(It first, It last) {
    // If no comparison function is provided, use `std::less`
    insertion_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}
//]

//[merge Mergesort: O(n log n)
template <class It, class C> void merge_sort(It first, It last, C comp) {
    // While more than 1 element
    if (last - first > 1) {
        It middle = first + (last - first) / 2;
        // Sort left-hand side
        merge_sort(first, middle, comp);
        // Sort right-hand side
        merge_sort(middle, last, comp);
        // Merge left and right-hand sides
        inplace_merge(first, middle, last, comp);
    }
}

template <class It> void merge_sort(It first, It last) {
    // If no comparison function is provided, use `std::less`
    merge_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}
//]

//[median Helper function for median of three values
template <typename T, class C> constexpr T median(T t1, T t2, T t3, C comp) {
    return (comp(t1, t2)) ? ((comp(t2, t3)) ? t2 : ((comp(t1, t3)) ? t3 : t1))
                          : ((comp(t1, t3)) ? t1 : ((comp(t2, t3)) ? t3 : t2));
}

template <class It> void median(It first, It last) {
    // If no comparison function is provided, use `std::less`
    median(first, last, std::less<std::decay_t<decltype(*first)>>());
}
//]

//[quicksort Quicksort: O(n log n)
template <class It, class C> void quick_sort(It first, It last, C comp) {
    // If there is more than 1 element to sort
    if (first != last && std::next(first) != last) {
        It middle = first + (last - first) / 2;
        // Choose a pivot based on the median element
        auto pivot = median(*first, *middle, *std::prev(last), comp);
        // Partition the vector based on the pivot
        It split1 =
            partition(first, last, [&](auto x) { return comp(x, pivot); });
        It split2 =
            partition(split1, last, [&](auto x) { return !comp(pivot, x); });
        // Sort left-hand side
        quick_sort(first, split1, comp);
        // Sort right-hand side
        quick_sort(split2, last, comp);
    }
}

template <class It> void quick_sort(It first, It last) {
    // If no comparison function is provided, use `std::less`
    quick_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}
//]

void call_custom_sort() {
    std::vector<int> v = {5, 4, 9, 8, 6, 3};
    //[call_selection Call selection sort
    selection_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    v = {5, 4, 9, 8, 6, 3};
    //[call_insertion Call insertion sort
    insertion_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    v = {5, 4, 9, 8, 6, 3};
    //[call_mergesort Call mergesort
    merge_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    v = {5, 4, 9, 8, 6, 3};
    //[call_quicksort Call quicksort
    quick_sort(v.begin(), v.end());
    copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
    //]

    // Comparison:
    // Simple methods:
    // - Selection sort: O(n^2)
    // - Insertion sort: O(n^2)
    // - Bubble sort: O(n^2)
    // - Shell sort: Generalized insertion sort
    // Efficient:
    // - Merge sort: O(n log n)
    // - Quicksort: O(n log n)
    // - Heapsort: O(n log n)
    // - Introsort: Quicksort + Heapsort

    // Counting:
    // - Counting sort: O(n + k)
    // - Radix Sort: O(n k)
}