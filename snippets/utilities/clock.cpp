#include <chrono> // std::chrono::seconds
#include <iostream>
#include <numeric>
#include <thread> // std::this_thread::sleep_for
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <vector>

void very_expensive_function();

int main() {
    // C++ Clock
    // - The only method specified in the standard to measure CPU time
    // - It doesn't work well with threads
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    very_expensive_function();
    end = clock();
    cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "cpu_time_used: " << cpu_time_used << " seconds" << std::endl;

    // Modern C++
    // - System Clocks
    auto start2 = std::chrono::system_clock::now();
    very_expensive_function();
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end2 - start2;
    std::chrono::duration<int, std::milli> milliseconds_diff;
    milliseconds_diff =
        std::chrono::duration_cast<std::chrono::duration<int, std::milli>>(
            diff);
    std::chrono::duration<int, std::ratio<60 * 60>>
        hours_diff; // same as using std::hours
    hours_diff = std::chrono::duration_cast<
        std::chrono::duration<int, std::ratio<60 * 60>>>(diff);
    std::cout << "diff.count() : " << diff.count() << " seconds" << std::endl;
    std::cout << "milliseconds_diff.count() : " << milliseconds_diff.count()
              << " milliseconds" << std::endl;
    std::cout << "hours_diff.count() : " << hours_diff.count() << " hours"
              << std::endl;

    // Modern C++
    // - High Resolution Clock
    auto start3 = std::chrono::high_resolution_clock::now();
    very_expensive_function();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    std::chrono::duration<int, std::milli> milliseconds_diff3;
    milliseconds_diff3 =
        std::chrono::duration_cast<std::chrono::duration<int, std::milli>>(
            diff3);
    std::chrono::duration<int, std::ratio<60 * 60>>
        hours_diff3; // same as using std::hours
    hours_diff3 = std::chrono::duration_cast<
        std::chrono::duration<int, std::ratio<60 * 60>>>(diff3);
    std::cout << "diff3.count() : " << diff3.count() << " seconds" << std::endl;
    std::cout << "milliseconds_diff3.count() : " << milliseconds_diff3.count()
              << " milliseconds" << std::endl;
    std::cout << "hours_diff3.count() : " << hours_diff3.count() << " hours"
              << std::endl;

    return 0;
}

void very_expensive_function() {
    for (int i = 0; i < 5; ++i) {
        std::cout << '*' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
}