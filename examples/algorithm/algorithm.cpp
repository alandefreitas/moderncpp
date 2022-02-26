#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric>
#include <random>
#include <matplot/matplot.h>

// Algorithm calculates max value
template <class T>
int max_value(const std::vector<T>& a) {
    if (a.empty()) {
        return std::numeric_limits<T>::min();
    }
    T m = a[0];
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    return m;
}

// Algorithm calculates index of max value
template <class T>
size_t max_element_idx(const std::vector<T>& a) {
    if (a.empty()) {
        return a.size();
    }
    size_t m = 0;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] > a[m]) {
            m = i;
        }
    }
    return m;
}

// Algorithm calculates pointer to max value in pointer interval
template <class T>
T* max_element_ptr(T* first, T* last) {
    if (first == last) {
        return last;
    }
    T* m = first;
    for (T* i = m + 1; i < last; ++i) {
        if (*i > *m) {
            m = i;
        }
    }
    return m;
}

// Algorithm calculates iterator to max value in iterator interval
template <class T>
T max_element_iter(T first, T last) {
    if (first == last) {
        return last;
    }
    T largest = first;
    ++first;
    while (first != last) {
        if (*first > *largest) {
            largest = first;
        }
        ++first;
    }
    return largest;
}

// Algorithm calculates iterator to max value in iterator interval
template <class T>
std::pair<T,size_t> max_element_iter_count_ops(T first, T last) {
    size_t count_ops = 0;
    if (first == last) {
        return std::make_pair(last, count_ops);
    }
    T largest = first;
    ++first;
    while (first != last) {
        ++count_ops;
        if (*first > *largest) {
            largest = first;
        }
        ++first;
    }
    return std::make_pair(largest, count_ops);
}

template <class T, class IT>
IT max_element_iter(const T& range) {
    return max_element_iter(range.begin(), range.end());
}

template <class GENERATOR>
std::vector<int> generate_vector(size_t n, GENERATOR& g) {
    std::vector<int> result(n);
    std::iota(result.begin(), result.end(), 0);
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

int main() {
    // Max in v
    std::vector<int> v = {7,3,5,8,9,3,2,6,7};
    std::cout << "max_value(v): " << max_value(v) << "\n";

    // Max in v
    std::cout << "max_element_idx(v): " << max_element_idx(v) << "\n";
    std::cout << "v[max_element_idx(v)]: " << v[max_element_idx(v)] << "\n";

    // Max in v
    int* p = max_element_ptr(&v[0], &v[v.size()]);
    std::cout << "p: " << p << '\n';
    std::cout << "*p: " << *p << '\n';

    // Max in {v[0], ..., v[4]}
    p = max_element_ptr(&v[0], &v[v.size()/2]);
    std::cout << "p: " << p << '\n';
    std::cout << "*p: " << *p << '\n';

    // Max in a
    std::array<int,5> a = {7,5,2,6,3};
    p = max_element_ptr(&a[0], &a[a.size()]);
    std::cout << "p: " << p << '\n';
    std::cout << "*p: " << *p << '\n';

    // Max in s
    std::unordered_set<int> s = {6,5,6,7,8,3,4};
    auto it = max_element_iter(s.begin(), s.end());
    std::cout << "*it: " << *it << '\n';

    // Random generator
    std::random_device r;
    unsigned int seed = r();
    std::default_random_engine g(seed);
    v = generate_vector(1000, g);
    auto it2 = max_element_iter(v.begin(), v.end());
    std::cout << "*it2: " << *it2 << '\n';
    
    // Measure time
    std::vector<size_t> sizes = {2,4,8,16,32,64,128,256,512,1024};
    std::vector<std::vector<std::chrono::nanoseconds>> duration;
    constexpr size_t replicates = 300;
    for (const auto &n : sizes) {
        duration.emplace_back(0);
        for (size_t i = 0; i < replicates; ++i) {
            auto tmp = generate_vector(n, g);
            auto start_time = std::chrono::system_clock::now();
            auto max_it = max_element_iter(tmp.begin(), tmp.end());
            auto end_time = std::chrono::system_clock::now();
            auto duration_algorithm = end_time - start_time;
            std::cout << "*max_it: " << *max_it << '\n';
            duration.back().emplace_back(duration_algorithm);
        }
    }

    // Print results
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_duration = std::accumulate(duration[i].begin(), duration[i].end(), std::chrono::nanoseconds(0));
        std::cout << "Size: " << sizes[i]  << ", " << " Time: " << total_duration.count() / replicates << '\n';
    }

    // Plot results
    std::vector<std::chrono::nanoseconds::rep> avg_duration;
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_duration = std::accumulate(duration[i].begin(), duration[i].end(), std::chrono::nanoseconds(0));
        avg_duration.emplace_back(total_duration.count() / replicates);
    }
    matplot::plot(sizes, avg_duration);
    matplot::xlabel("Problem size");
    matplot::ylabel("Time (nanoseconds)");
    matplot::show();

    // Measure time
    std::vector<std::vector<size_t>> count_ops_table;
    for (const auto &n : sizes) {
        count_ops_table.emplace_back(0);
        for (size_t i = 0; i < replicates; ++i) {
            auto tmp = generate_vector(n, g);
            auto [max_it, count_ops] = max_element_iter_count_ops(tmp.begin(), tmp.end());
            count_ops_table.back().emplace_back(count_ops);
        }
    }

    // Print results
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_operations = std::accumulate(count_ops_table[i].begin(), count_ops_table[i].end(), size_t(0));
        std::cout << "Size: " << sizes[i]  << ", " << " Operations: " << total_operations / replicates << '\n';
    }

    // Plot results
    std::vector<double> avg_ops;
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_operations = std::accumulate(count_ops_table[i].begin(), count_ops_table[i].end(), size_t(0));
        avg_ops.emplace_back(static_cast<double>(total_operations) / replicates);
    }
    matplot::plot(sizes, avg_ops);
    matplot::xlabel("Problem size");
    matplot::ylabel("Operations");
    matplot::show();

    return 0;
}