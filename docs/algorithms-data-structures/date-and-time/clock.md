# Clock

!!!note "Clock"

    A clock consists of a starting point (or epoch) and a tick rate. For example, a clock may have an epoch of 
    January 1, 1970 and tick every second. C++ defines several clock types:

    - `system_clock` (C++11): wall clock time from the system-wide realtime clock
    - `steady_clock` (C++11): monotonic clock that will never be adjusted
    - `high_resolution_clock` (C++11): the clock with the shortest tick period available
    - `utc_clock` (C++20): Clock for Coordinated Universal Time (UTC)
    - `tai_clock` (C++20): Clock for International Atomic Time (TAI)
    - `gps_clock` (C++20): Clock for GPS time
    - `file_clock` (C++20): Clock used for file time
    - `local_t` (C++20): pseudo-clock representing local time

    C++ also inherits the C `clock` function, which returns the approximate processor time used by the process 
    since the beginning of an implementation-defined era related to the program's execution. 
    To convert result value to seconds divide it by CLOCKS_PER_SEC. The `clock` function:

    - The only method specified in the standard to measure CPU time
    - It's up to the user to keep track of the duration unit
    - It doesn't work well with threads
    - Ignores the time spent on `this_thread::sleep_for`

{{ all_code_snippets("snippets/datetime/clock.cpp") }}

