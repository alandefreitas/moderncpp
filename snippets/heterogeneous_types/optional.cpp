#include <iostream>
#include <numeric>
#include <optional>
#include <unordered_map>
#include <ctime>
#include <cmath>

// Clearly mark optional values
std::optional<int> get_even_random_number() {
    // std::rand() has limited randomness (use C++ <random> instead>
    int i = std::rand();
    if (i % 2 == 0) {
        return i;
    } else {
        return std::nullopt;
    }
}

std::optional<int> get_even_random_number2() {
    // std::rand() has limited randomness (use C++ <random> instead>
    int i = std::rand();
    return std::make_optional(int(i % 2 == 0));
}

int main() {
    using namespace std;

    auto entropy_source = static_cast<unsigned int>(std::time(nullptr));
    std::srand(entropy_source);

    std::cout << "Optional variables:" << std::endl;
    {
        optional<int> i = get_even_random_number();
        if (i) {
            std::cout << std::sqrt(static_cast<float>(*i)) << '\n';
        } else {
            std::cout << "No value was returned" << '\n';
        }

        i = get_even_random_number2();
        double d = i.value_or(0);
        std::cout << std::sqrt(d) << '\n';
        std::cout << i.value_or(0) << std::endl;
    }
    return 0;
}