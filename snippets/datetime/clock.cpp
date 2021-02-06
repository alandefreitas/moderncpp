#include <chrono> // std::chrono::seconds
#include <ctime>  // clock_t, clock, CLOCKS_PER_SEC
#include <iostream>
#include <thread> // std::this_thread::sleep_for

void very_expensive_function();

using namespace std;

int main() {
    // Old C Clock
    // - The only method specified in the standard to measure CPU time
    // - It's up to the user to keep track of the duration unit
    // - It doesn't work well with threads though
    // - Note how the example ignores the time spent this_thread::sleep_for
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    very_expensive_function();
    end = clock();
    cpu_time_used = static_cast<float>(end - start) / CLOCKS_PER_SEC;
    cout << "cpu_time_used: " << cpu_time_used << " seconds" << endl;

    // Modern C++
    // - System Clocks
    auto start2 = chrono::system_clock::now();
    very_expensive_function();
    auto end2 = chrono::system_clock::now();

    // Duration represented with the default duration type
    auto auto_duration = end2 - start2;
    cout << "auto_duration.count() : " << auto_duration.count()
         << " nanoseconds" << endl;

    // Duration represented with double, ratio in seconds
    chrono::duration<double> seconds_as_double = end2 - start2;
    cout << "seconds_as_double.count() : " << seconds_as_double.count()
         << " seconds" << endl;

    // Duration represented with int, ratio in milliseconds
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init)
    chrono::duration<int, milli> milliseconds_as_int_;

    // Cast duration (double, seconds) to duration (int, milliseconds)
    milliseconds_as_int_ =
        chrono::duration_cast<chrono::duration<int, milli>>(seconds_as_double);
    cout << "milliseconds_as_int_.count() : " << milliseconds_as_int_.count()
         << " milliseconds" << endl;

    // Using ratio directly
    // Same as using hours
    constexpr int seconds_per_hour = 60 * 60;
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init)
    chrono::duration<int, ratio<seconds_per_hour>> hours_as_int;
    hours_as_int = chrono::duration_cast<chrono::duration<int, ratio<60 * 60>>>(
        seconds_as_double);
    cout << "hours_as_int.count() : " << hours_as_int.count() << " hours"
         << endl;

    // Modern C++
    // - High Resolution Clock
    auto start3 = chrono::high_resolution_clock::now();
    very_expensive_function();
    auto end3 = chrono::high_resolution_clock::now();

    // Duration represented with the default duration type
    auto auto_duration_3 = end2 - start2;
    cout << "auto_duration_3.count() : " << auto_duration_3.count()
         << " nanoseconds" << endl;

    // Time in seconds as double
    chrono::duration<double> seconds_as_double_3 = end3 - start3;
    cout << "seconds_as_double_3.count() : " << seconds_as_double_3.count()
         << " seconds" << endl;

    // Time in milliseconds as int
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init)
    chrono::duration<int, milli> milliseconds_as_int_3;
    milliseconds_as_int_3 = chrono::duration_cast<chrono::duration<int, milli>>(
        seconds_as_double_3);
    cout << "milliseconds_as_int_3.count() : " << milliseconds_as_int_3.count()
         << " milliseconds" << endl;

    // Time in hours as int
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init)
    chrono::duration<int, ratio<seconds_per_hour>>
        hours_as_int3; // same as using hours
    hours_as_int3 =
        chrono::duration_cast<chrono::duration<int, ratio<seconds_per_hour>>>(
            seconds_as_double_3);
    cout << "hours_as_int3.count() : " << hours_as_int3.count() << " hours"
         << endl;

    // "Parsing" time
    // While std::chrono::parse is not available in all main compilers
    auto hours = chrono::duration_cast<chrono::hours>(auto_duration_3);
    if (hours.count() > 0) {
        cout << hours.count() << " hours";
    }
    auto seconds = chrono::duration_cast<chrono::seconds>(auto_duration_3);
    if (seconds.count() > 0) {
        cout << seconds.count() << " seconds";
    }
    auto milliseconds =
        chrono::duration_cast<chrono::milliseconds>(auto_duration_3);
    if (milliseconds.count() > 0) {
        cout << milliseconds.count() << " milliseconds";
    }
    auto nanoseconds =
        chrono::duration_cast<chrono::nanoseconds>(auto_duration_3);
    if (nanoseconds.count() > 0) {
        cout << nanoseconds.count() << " nanoseconds";
    }

    return 0;
}

void very_expensive_function() {
    for (int i = 0; i < 5; ++i) {
        cout << '*' << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;
}