#include <iostream>
#include <array>
#include <string>
#include <type_traits>

// Define concept with a boolean
template<typename T>
concept Number = std::is_arithmetic_v<T>;

template<typename T>
concept NotNumber = !Number<T>;

template <class T>
void max(T a, T b) {
    if (a > b) {
        std::cout << "max: " << a << std::endl;
    } else {
        std::cout << "max: " << b << std::endl;
    }
}

template <NotNumber T>
void max(T a, T b) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}


int main() {
    max(5,7);
    max(4,7);
    max("foo", "bar");
    return 0;
}
