#include <iostream>
#include <numeric>
#include <optional>
#include <unordered_map>
#include <ctime>
#include <cmath>

//[opt_func Function that returns a value only if it's even
std::optional<int> get_even_random_number() {
    int i = std::rand();
    if (i % 2 == 0) {
        return i;
    } else {
        return std::nullopt;
    }
}
//]

//[opt_func_2 Function that always returns a non-empty optional value
std::optional<int> get_even_random_number2() {
    int i = std::rand();
    return std::make_optional(int(i % 2 == 0));
}
//]

int main() {
    auto entropy_source = static_cast<unsigned int>(std::time(nullptr));
    std::srand(entropy_source);

    std::cout << "Optional variables:" << std::endl;
    {
        //[callfunc1 Call function that returns optional value
        std::optional<int> i = get_even_random_number();
        if (i) {
            std::cout << std::sqrt(static_cast<float>(*i)) << '\n';
        } else {
            std::cout << "No value was returned" << '\n';
        }
        //]

        //[callfunc2 Call function that returns non-empty optional value
        i = get_even_random_number2();
        double d = i.value_or(0);
        std::cout << std::sqrt(d) << '\n';
        std::cout << i.value_or(0) << std::endl;
        //]
    }
    return 0;
}