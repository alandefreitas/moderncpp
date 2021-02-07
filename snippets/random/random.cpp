#include <iostream>
#include <random>
#include <chrono>

using namespace std;

static constexpr uint32_t fnv(uint32_t hash, const char *pos) {
    return *pos == '\0' ? hash : fnv((hash * 16777619U) ^ *pos, pos + 1);
}

int main() {
    // Operating system number generator (usually high-cost)
    random_device rd;

    // Generate seed for low cost generator
    unsigned int seed = rd();

    // Mix seed with some more imaginable cross-platform entropy sources
    // - Current time
    seed ^= static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    // - Compile stamp
    constexpr uint32_t compile_stamp = fnv(2166136261U, __DATE__ __TIME__ __FILE__);
    seed ^= static_cast<unsigned int>(compile_stamp);
    // - A heap address
    void *heap_addr = malloc(sizeof(int));
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>(heap_addr));
    // - A stack address
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>(&heap_addr));
    free(heap_addr);
    // - A fixed counter
    seed ^= static_cast<unsigned int>(45);
    // - The time function address
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>(&std::chrono::system_clock::now));
    // - The exit function address
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>((void *) &_Exit));
    // - A local function address
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>((int *) &main));
    // - The generator type hash code
    seed ^= static_cast<unsigned int>(typeid(random_device).hash_code());

    // Use seed for a low-cost generator (supposedly)
    default_random_engine g(seed);

    // Create a distribution
    uniform_real_distribution<double> distribution(1.0, 10.0);

    // Using the machine with that distribution
    cout << distribution(g) << endl;

    // Create a mt19937 generator instead of default_random_engine
    mt19937 g2{seed};

    // Creating a normal distribution (very cheap)
    normal_distribution<double> d2(0.0, 1.0);

    // Using the machine with that distribution
    cout << d2(g2) << endl;

    // Generate a histogram
    vector<int> hist(10, 0);
    for (int i = 0; i < 300; ++i) {
        auto bin = d2(g2) + static_cast<double>(hist.size()) / 2;
        if (bin >= 0. && static_cast<size_t>(bin) < hist.size()) {
            ++hist[static_cast<size_t>(bin)];
        }
    }
    for (int n : hist) {
        cout << '-';
        for (int j = 0; j < n; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}