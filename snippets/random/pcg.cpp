#include <iostream>
#include <random>
#include <pcg_random.hpp>

int main() {
    using namespace std;

    // Initialize with two fixed seeds
    pcg32 rng(42u, 54u);

    // Seed with external entropy
    rng.seed(pcg_extras::seed_seq_from<std::random_device>());

    // Random number
    std::cout << "Random number: " << rng() << std::endl;
    std::cout << "Random number: " << rng() << std::endl;
    std::cout << "Random number: " << rng() << std::endl;

    // Flip coins
    std::cout << "Flip coin: " << rng(2) << std::endl;
    std::cout << "Flip coin: " << rng(2) << std::endl;
    std::cout << "Flip coin: " << rng(2) << std::endl;

    // Roll dice
    std::cout << "Roll dice: " << rng(6) << std::endl;
    std::cout << "Roll dice: " << rng(6) << std::endl;
    std::cout << "Roll dice: " << rng(6) << std::endl;

    // Print generator state
    std::cout << "Generator state: " << rng << std::endl;
    std::cout << "Result size: " << sizeof(pcg32::result_type) * 8 << "bits" << std::endl;
    std::cout << "Period: 2^" << pcg32::period_pow2() << std::endl;

    // C++ distributions
    uniform_real_distribution<double> distribution(1.0, 10.0);
    cout << distribution(rng) << endl;

    return 0;
}