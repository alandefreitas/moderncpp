#include <chrono>
#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    constexpr size_t samples = 10000;
    std::vector<float> flushing_cpu(samples);
    std::vector<float> not_flushing_cpu_time(samples);
    std::vector<float> flushing_steady_clock(samples);
    std::vector<float> not_flushing_steady_clock(samples);

    clock_t start_cpu, end_cpu;
    chrono::steady_clock::time_point start_steady, end_steady;
    float cpu_time_used;
    for (size_t i = 0; i < samples; ++i) {
        start_cpu = clock();
        std::cout << "Hi " << 5 << "!" << std::endl;
        end_cpu = clock();
        cpu_time_used = static_cast<float>(end_cpu - start_cpu) / CLOCKS_PER_SEC;
        flushing_cpu[i] = cpu_time_used;

        start_cpu = clock();
        std::cout << "Hi " << 5 << "!" << '\n';
        end_cpu = clock();
        cpu_time_used = static_cast<float>(end_cpu - start_cpu) / CLOCKS_PER_SEC;
        not_flushing_cpu_time[i] = cpu_time_used;

        start_steady = chrono::steady_clock::now();
        std::cout << "Hi " << 5 << "!" << std::endl;
        end_steady = chrono::steady_clock::now();
        cpu_time_used = chrono::duration_cast<chrono::duration<float>>(
                            end_steady - start_steady).count();
        flushing_steady_clock[i] = cpu_time_used;

        start_steady = chrono::steady_clock::now();
        std::cout << "Hi " << 5 << "!" << '\n';
        end_steady = chrono::steady_clock::now();
        cpu_time_used = chrono::duration_cast<chrono::duration<float>>(
                            end_steady - start_steady).count();
        not_flushing_steady_clock[i] = cpu_time_used;
    }

    std::cout << "Flush CPU Time: "
              << accumulate(flushing_cpu.begin(), flushing_cpu.end(), 0.f) / samples
              << std::endl;

    std::cout << "Don't Flush CPU Time: "
              << accumulate(not_flushing_cpu_time.begin(),
                            not_flushing_cpu_time.end(), 0.f) / samples
              << '\n';

    std::cout << "Flush Steady Clock: "
              << accumulate(flushing_steady_clock.begin(),
                            flushing_steady_clock.end(), 0.f) / samples
              << std::endl;

    std::cout << "Don't Flush Steady Clock: "
              << accumulate(not_flushing_steady_clock.begin(),
                            not_flushing_steady_clock.end(), 0.f) / samples
              << '\n';

    /*
     * Results:
     *
     * GCC:
     * Flush: 2.05199e-06
     * Don't Flush: 2.01329e-06
     *
     * Clang:
     * Flush: 2.14641e-06
     * Don't Flush: 2.0685e-06
     *
     * GCC -O2:
     * Flush: 2.32234e-06
     * Don't Flush: 2.26303e-06
     *
     * Clang -O2:
     * Flush: 2.33343e-06
     * Don't Flush: 2.23031e-06
     *
     */

    // - The cost of outputting to cout dominates the cost of flushing
    // - Generalizing from examples dealing with files is a bad idea:
    //   There is much less reason to flush_cpu ofstream than to flush_cpu cout
    //   Completely different factors are at play there.
    // - Another reason for flushing is... you actually WANT to flush_cpu!

    return 0;
}