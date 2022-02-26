#include <iostream>
#include <random>
#include <pcg_random.hpp>

int main() {
    //[init Initialize generator with two fixed seeds
    pcg32 rng(42u, 54u);
    //]

    //[init_seed Seed generator with external entropy
    rng.seed(pcg_extras::seed_seq_from<std::random_device>());
    //]

    //[random Random numbers
    std::cout << "Random number: " << rng() << '\n';
    //]
    std::cout << "Random number: " << rng() << '\n';
    std::cout << "Random number: " << rng() << '\n';

    //[flip Flip coins
    std::cout << "Flip coin: " << rng(2) << '\n';
    //]
    std::cout << "Flip coin: " << rng(2) << '\n';
    std::cout << "Flip coin: " << rng(2) << '\n';

    //[dice Roll dice
    std::cout << "Roll dice: " << rng(6) << '\n';
    //]
    std::cout << "Roll dice: " << rng(6) << '\n';
    std::cout << "Roll dice: " << rng(6) << '\n';

    //[state Print generator state
    std::cout << "Generator state: " << rng << '\n';
    std::cout << "Result size: " << sizeof(pcg32::result_type) * 8 << "bits" << '\n';
    std::cout << "Period: 2^" << pcg32::period_pow2() << '\n';
    //]

    //[dist Use with C++ distributions
    std::uniform_real_distribution<double> distribution(1.0, 10.0);
    std::cout << distribution(rng) << '\n';
    //]

    return 0;
}