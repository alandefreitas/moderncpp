#include <iostream>
#include <array>
#include <string>
#include <type_traits>

// Define concept with a boolean
template <class T>
void max(std::enable_if_t<std::is_arithmetic_v<T>, T> a, T b) {
    if (a > b) {
        std::cout << "max: " << a << std::endl;
    } else {
        std::cout << "max: " << b << std::endl;
    }
}

template <class T>
void max(std::enable_if_t<!std::is_arithmetic_v<T>, T> a, T b) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

int main() {
    max(5,7);
    max("foo", "bar");
    return 0;
}
