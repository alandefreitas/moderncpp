#include <chrono>
#include <iostream>
#include <tabulate/table.hpp>

using namespace std;

// Iterative function
int fibonacci_iterative(int n);

// Recursive function
int fibonacci_recursive(int n);

int main() {
    // Comparing time
    // - This is a classic case where:
    // - Iterative algorithms are more efficient
    // - Recursive algorithms are easier to write
    tabulate::Table results;
    results.add_row({"i", "fib(i)", "Iterative Time (ns)",
                     "Recursive Time (ns)"});
    for (int i = 3; i < 60; ++i) {
        auto start1 = chrono::steady_clock::now();
        int result1 = fibonacci_iterative(i);
        auto duration1 = chrono::duration_cast<chrono::nanoseconds>(std::chrono::steady_clock::now() - start1);

        auto start2 = chrono::steady_clock::now();
        int result2 = fibonacci_recursive(i);
        auto duration2 = chrono::duration_cast<chrono::nanoseconds>(std::chrono::steady_clock::now() - start2);

        if (result1 == result2) {
            results.add_row({"i = " + to_string(i),
                             "fib(i) = " + to_string(result1),
                             to_string(duration1.count()) + "ns",
                             to_string(duration2.count()) + "ns"});
        } else {
            cerr << "The results don't match\n";
            return 0;
        }

        std::cout << results << std::endl;
    }

    return 0;
}

int fibonacci_iterative(int n) {
    if (n <= 2) {
        return 1;
    }
    int fn;
    int fn_1 = 1;
    int fn_2 = 1;
    for (int i = 3; i <= n; ++i) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}

// NOLINTNEXTLINE(misc-no-recursion): making a point
int fibonacci_recursive(int n) {
    if (n > 2) {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    } else {
        return 1;
    }
}
