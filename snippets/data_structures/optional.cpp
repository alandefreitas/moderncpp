#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <unordered_map>

using namespace std;

// Clearly mark optional values
optional<int> get_even_random_number() {
    int i = std::rand();
    if (i % 2 == 0) {
        return i;
    } else {
        return nullopt;
    }
}

optional<int> get_even_random_number2() {
    int i = std::rand();
    return make_optional(int(i % 2 == 0));
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

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