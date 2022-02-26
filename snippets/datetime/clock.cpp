#include <chrono> // std::chrono::seconds
#include <ctime>  // clock_t, clock, CLOCKS_PER_SEC
#include <iostream>
#include <thread> // std::this_thread::sleep_for

void very_expensive_function();

int main() {
    //[clock_fn std::clock function
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    very_expensive_function();
    end = clock();
    cpu_time_used = static_cast<float>(end - start) / CLOCKS_PER_SEC;
    std::cout << "cpu_time_used: " << cpu_time_used << " seconds" << '\n';
    //]

    //[system_clock Modern C++ System Clock
    auto start2 = std::chrono::system_clock::now();
    very_expensive_function();
    auto end2 = std::chrono::system_clock::now();
    //]

    //[dur Duration represented with the default duration type
    auto auto_duration = end2 - start2;
    std::cout << "auto_duration.count() : " << auto_duration.count() << " ticks"
              << '\n'; // usually nanoseconds
    //]

    //[double_dur Duration represented with double, ratio in seconds
    std::chrono::duration<double> seconds_as_double = end2 - start2;
    std::cout << "seconds_as_double.count() : " << seconds_as_double.count()
              << " seconds" << '\n';
    //]

    //[int_milli Duration represented with int, ratio in milliseconds
    std::chrono::duration<int, std::milli> milliseconds_as_int_;
    //]

    //[cast_dur Cast duration (double, seconds) to duration (int, milliseconds)
    milliseconds_as_int_ =
        std::chrono::duration_cast<std::chrono::duration<int, std::milli>>(
            seconds_as_double);
    std::cout << "milliseconds_as_int_.count() : "
              << milliseconds_as_int_.count() << " milliseconds" << '\n';
    //]

    //[ratio Using ratio directly
    // Same as using hours
    constexpr int seconds_per_hour = 60 * 60;
    std::chrono::duration<int, std::ratio<seconds_per_hour>> hours_as_int;
    hours_as_int =
        std::chrono::duration_cast<std::chrono::duration<int, std::ratio<60 * 60>>>(
            seconds_as_double);
    std::cout << "hours_as_int.count() : " << hours_as_int.count() << " hours"
              << '\n';
    //]

    //[steady Modern C++ Steady Clock
    auto start3 = std::chrono::steady_clock::now();
    very_expensive_function();
    auto end3 = std::chrono::steady_clock::now();
    //]

    //[dur_steady Duration represented with the default duration type
    auto d3 = end2 - start2;
    std::cout << "auto_duration_3.count() : " << d3.count()
              << " ticks" << '\n'; // usually nanoseconds
    //]

    //[time_double Time in seconds as double
    std::chrono::duration<double> seconds_as_double_3 = end3 - start3;
    std::cout << "seconds_as_double_3.count() : " << seconds_as_double_3.count()
              << " seconds" << '\n';
    //]

    //[time_milli_steady Time in milliseconds as int
    std::chrono::duration<int, std::milli> milliseconds_as_int_3;
    milliseconds_as_int_3 =
        std::chrono::duration_cast<std::chrono::duration<int, std::milli>>(
            seconds_as_double_3);
    std::cout << "milliseconds_as_int_3.count() : "
              << milliseconds_as_int_3.count() << " milliseconds" << '\n';
    //]

    //[ratio_steady Time in hours as int
    std::chrono::duration<int, std::ratio<seconds_per_hour>>
        hours_as_int3; // same as using std::hours
    hours_as_int3 = std::chrono::duration_cast<
        std::chrono::duration<int, std::ratio<seconds_per_hour>>>(
        seconds_as_double_3);
    std::cout << "hours_as_int3.count() : " << hours_as_int3.count() << " hours"
              << '\n';
    //]

    //[parsing "Parsing" time
    // While std::std::chrono::parse is not available in all main compilers
    auto hours =
        std::chrono::duration_cast<std::chrono::hours>(d3);
    if (hours.count() > 0) {
        std::cout << hours.count() << " hours";
    }
    d3 -= hours;
    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(d3);
    if (seconds.count() > 0) {
        std::cout << seconds.count() << " seconds";
    }
    d3 -= seconds;
    auto milliseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(d3);
    if (milliseconds.count() > 0) {
        std::cout << milliseconds.count() << " milliseconds";
    }
    d3 -= milliseconds;
    auto nanoseconds =
        std::chrono::duration_cast<std::chrono::nanoseconds>(d3);
    if (nanoseconds.count() > 0) {
        std::cout << nanoseconds.count() << " nanoseconds";
    }
    //]

    return 0;
}

void very_expensive_function() {
    for (int i = 0; i < 5; ++i) {
        std::cout << '*' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << '\n';
}