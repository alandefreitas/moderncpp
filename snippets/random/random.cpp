#include <iostream>
//[headers Headers
#include <random>
//]
#include <chrono>
#include <memory>

unsigned int mix_seed(unsigned int seed);

int main() {
    //[random_device Operating system number generator
    // Usually a high-cost generator
    std::random_device rd;
    //]

    //[gen_seed Generate seed for a low-cost generator
    unsigned int seed = rd();
    //]

    //[mix_seed Mix the seed with other sources of entropy
    // We recur to a user-defined function to mix other sources
    // of entropy in the seed
    seed = mix_seed(seed);
    //]

    //[default_random Use seed for a lower-cost number generator
    // This is the generator we will ultimately use
    std::default_random_engine g(seed);
    //]

    //[dist Create a number distribution (cheap)
    std::uniform_real_distribution<double> distribution(1.0, 10.0);
    //]

    //[dist_use Using the generator with that distribution
    std::cout << distribution(g) << '\n';
    //]

    //[mt19937 Explicitly create a mt19937 generator
    std::mt19937 g2{seed};
    //]

    //[normal Creating a normal distribution (cheap)
    std::normal_distribution<double> d2(0.0, 1.0);
    //]

    //[use_normal Using the generator with that distribution
    std::cout << d2(g2) << '\n';
    //]

    //[hist Generate a histogram from the generator
    std::vector<int> hist(10, 0);
    for (int i = 0; i < 300; ++i) {
        auto bin = d2(g2) + static_cast<double>(hist.size()) / 2;
        if (bin >= 0. && static_cast<size_t>(bin) < hist.size()) {
            ++hist[static_cast<size_t>(bin)];
        }
    }
    //]

    //[print_hist Print the histogram
    for (int n : hist) {
        std::cout << '-';
        for (int j = 0; j < n; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    //]

    return 0;
}

//[mix_seed_fn User-defined function to mix the seed
constexpr uint32_t fnv(uint32_t hash, const char *pos) {
    return *pos == '\0' ? hash : fnv((hash * 16777619U) ^ *pos, pos + 1);
}

unsigned int mix_seed(unsigned int seed) {
    // Mix seed with some cross-platform entropy sources
    // - Mix the current time
    seed ^= static_cast<unsigned int>(
        std::chrono::system_clock::now().time_since_epoch().count());

    // - Mix an arbitrary compile-time stamp
    constexpr uint32_t compile_stamp =
        fnv(2166136261U, __DATE__ __TIME__ __FILE__);
    seed ^= static_cast<unsigned int>(compile_stamp);

    // - Mix an arbitrary heap address
    auto heap_addr = std::make_unique<int>(0);
    seed ^=
        static_cast<unsigned int>(reinterpret_cast<uintptr_t>(heap_addr.get()));

    // - Mix an arbitrary stack address
    seed ^= static_cast<unsigned int>(reinterpret_cast<uintptr_t>(&heap_addr));

    // - Mix an arbitrary fixed number / counter
    seed ^= static_cast<unsigned int>(45);

    // - Mix an arbitrary function address (the clock function `now`)
    seed ^= static_cast<unsigned int>(
        reinterpret_cast<uintptr_t>(&std::chrono::system_clock::now));

    // - Mix the exit function address
    seed ^=
        static_cast<unsigned int>(reinterpret_cast<uintptr_t>((void *)&_Exit));

    // - Mix the random_device generator type hash code
    seed ^= static_cast<unsigned int>(typeid(std::random_device).hash_code());

    return seed;
}
//]