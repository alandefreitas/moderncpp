#include <iostream>
#include <vector>
#include <numeric>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution(1,30) ;

    std::cout << "Non-modifying sequence operations:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Counting
        std::cout << "There are " << std::count(v.begin(),v.end(),10) << " tens" << std::endl;

        // Comparing sequences
        auto v2 = v;
        if (std::equal(v.begin(), v.end(), v2.begin())){
            std::cout << "v and v2 are the same" << std::endl;
        }

        // Finding elements
        std::vector<int>::iterator position = std::find(v.begin(), v.end(), 10);
        if (position != v.end()){
            std::cout << "A ten was found in position " << position - v.begin() << std::endl;
        } else {
            std::cout << "A ten was not found in any position" << std::endl;
        }

        // Finding elements from a set
        std::vector<int> set = {16, 15, 14};
        std::vector<int>::iterator position2 = std::find_first_of(v.begin(), v.end(), set.begin(), set.end());
        if (position2 != v.end()){
            std::cout << "An element from the set was found in position " << position2 - v.begin() << std::endl;
        } else {
            std::cout << "An element from the set was not found in any position" << std::endl;
        }

        // Finding mismatches
        v2[v2.size()/3]++;
        auto mpair = std::mismatch(v.begin(), v.end(), v2.begin());
        std::cout << "Elements " << *mpair.first << " and " << *mpair.second << " mismatched at position " << mpair.first - v.begin() << std::endl;

        // Adjacent elements
        auto i1 = std::adjacent_find(v.begin(), v.end());
        if (i1 == v.end()) {
            std::cout << "No matching adjacent elements" << std::endl;
        } else {
            std::cout << "The first adjacent pair of equal elements at: " << std::distance(v.begin(), i1) << std::endl;
        }

        // Find subsequence
        std::vector<int> target = {v[30],v[31],v[32]};
        auto result = std::search(v.begin(), v.end(), target.begin(), target.end());
        if (result == v.end()) {
            std::cout << "Subsequence not found" << std::endl;
        } else {
            std::cout << "First subsequence is at: " << std::distance(v.begin(), result) << std::endl;
        }

        std::vector<int> v3 = {v[30],v[31],v[32]};
        auto result2 = std::find_end(v.begin(), v.end(), v3.begin(), v3.end());
        if (result2 == v.end()) {
            std::cout << "Subsequence not found" << std::endl;
        } else {
            std::cout << "Last subsequence is at: " << std::distance(v.begin(), result2) << std::endl;
        }
    }

    std::cout << "Modifying sequence operations:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        std::vector<int> v2(100);
        std::generate(v2.begin(), v2.end(), [&]{ return distribution(generator);});
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Copying
        std::copy(v.begin(), v.end(), v2.begin());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Filling
        std::fill(v2.begin(), v2.end(), 0);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Removing elements
        v2 = v;
        auto last_removed = std::remove(v2.begin(), v2.end(), 10);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;
        v2.erase(last_removed,v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;
        v2.resize(100);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Replacing elements
        std::replace(v2.begin(), v2.end(), 0,100);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Swapping
        std::swap(v,v2);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Swapping ranges
        std::swap_ranges(v.begin(),v.end(),v2.begin());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Reverse
        std::reverse(v2.begin(),v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Rotate left
        std::rotate(v2.begin(),v2.begin()+5,v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Rotate right
        std::rotate(v2.rbegin(),v2.rbegin()+5,v2.rend());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Shuffle
        std::shuffle(v2.begin(),v2.end(),generator);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Sample
        std::sample(v.begin(),v.end(),v2.begin(),v.size(),generator);
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Remove duplicates
        std::sort(v2.begin(),v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        auto last_unique = std::unique(v2.begin(),v2.end());
        v2.erase(last_unique, v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

    }

    std::cout << "Sorting:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        std::vector<int> v2(100);
        std::generate(v2.begin(), v2.end(), [&]{ return distribution(generator);});
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Sorting (Usually Introsort = Quicksort + Heapsort)
        std::sort(v2.begin(),v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Checking if sorted
        if (std::is_sorted(v2.begin(),v2.end())){
            std::cout << "The vector is sorted" << std::endl;
        }

        // Sorting partially
        v2 = v;
        std::partial_sort(v2.begin(), v2.begin() + 15, v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Sorting (stable)
        std::stable_sort(v2.begin(), v2.end());
        std::for_each(v2.begin(),v2.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << "(" << v2.size() << ")" << std::endl;

        // Median and percentiles
        v2 = v;
        std::nth_element(v2.begin(), v2.begin() + v2.size()/2, v.end());
        std::cout << "The median is " << v[v.size()/2] << '\n';

        std::nth_element(v2.begin(), v2.begin()+1, v2.end());
        std::cout << "The second smallest element is " << v2[1] << '\n';
    }

    std::cout << "Binary search:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::sort(v.begin(),v.end());
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Binary search
        if (std::binary_search(v.begin(),v.end(),15)){
            std::cout << "Element 15 found" << std::endl;
        } else {
            std::cout << "Element 15 not found" << std::endl;
        }

        // Lower bound
        auto lower = std::lower_bound(v.begin(), v.end(), 15);
        if (lower != v.end()) {
            std::cout << "First 15 at position " << lower - v.begin() << std::endl;
        } else {
            std::cout << "15 not found" << std::endl;
        }

        // Upper bound
        auto upper = std::upper_bound(v.begin(), v.end(), 15);
        if (upper != v.end()) {
            std::cout << "Last 15 at position " << upper - v.begin() << std::endl;
        } else {
            std::cout << "Last 15 not found" << std::endl;
        }

        // Equal range
        auto range = std::equal_range(v.begin(), v.end(), 15);
        if (range.first != v.end()){
            std::cout << "15 from positions " << range.first - v.begin() << " to " << range.second - v.begin() << std::endl;
        }
    }

    std::cout << "Heap:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Creating heaps
        std::make_heap(v.begin(), v.end());
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;
        std::cout << "The largest element is " << v.front() << std::endl;

        // Pushing elements to heap
        v.push_back(31);
        std::push_heap(v.begin(),v.end());
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Popping elements from heap
        std::pop_heap(v.begin(),v.end());
        v.pop_back();
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Sorting heap
        std::sort_heap(v.begin(), v.end());
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;
    }

    std::cout << "Minimum/maximum operations:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Max/min
        std::cout << "min: " << std::min(9,3) << ", max = " << std::max(9,3) << std::endl;

        std::pair<int, int> bounds = std::minmax(std::rand() % v.size(), std::rand() % v.size());
        std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
        for (int i = bounds.first; i < bounds.second; ++i) {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;

        // Max/min elements
        auto max_i = std::max_element(v.begin(), v.end());
        std::cout << "Max element at: " << std::distance(v.begin(), max_i) << std::endl;

        auto min_i = std::min_element(v.begin(), v.end());
        std::cout << "Min element at: " << std::distance(v.begin(), min_i) << std::endl;

        auto result = std::minmax_element(v.begin(), v.end());
        std::cout << "min element at: " << (result.first - v.begin()) << '\n';
        std::cout << "max element at: " << (result.second - v.begin()) << '\n';
    }

    std::cout << "Permutations:" << std::endl;
    {
        std::vector<int> v1{1,2,3,4,5};
        std::vector<int> v2{3,5,4,1,2};
        std::cout << "3,5,4,1,2 is a permutation of 1,2,3,4,5? " << std::boolalpha << std::is_permutation(v1.begin(), v1.end(), v2.begin()) << '\n';

        std::vector<int> v3{1,2,3};
        do {
            std::for_each(v3.begin(),v3.end(),[] (const int c) {std::cout << c << " ";});
            std::cout << std::endl;
        } while(std::next_permutation(v3.begin(), v3.end()));
    }

    std::cout << "Numeric:" << std::endl;
    {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&]{ return distribution(generator);});
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Sequentially increasing values
        std::iota(v.begin(), v.end(), 0);
        std::for_each(v.begin(),v.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Accumulating
        std::cout << "Total " << std::accumulate(v.begin(), v.end(), 0) << std::endl;

        // Inner product
        std::vector<int> a{0, 1, 2, 3, 4};
        std::vector<int> b{5, 4, 2, 3, 1};
        int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
        std::cout << "Inner product of a and b: " << r1 << '\n';

        // Adjacent difference
        std::vector<int> x{1, 4, 7, 8, 11, 11, 14, 15, 19, 22};
        std::adjacent_difference(x.begin(), x.end(), x.begin());
        std::for_each(x.begin(),x.end(),[] (const int c) {std::cout << c << " ";});
        std::cout << std::endl;

        // Partial sum
        std::partial_sum(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }


    return 0;
}