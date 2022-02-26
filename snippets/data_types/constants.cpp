#include <array>
#include <iostream>

int main() {
    //[mutable Mutable variable
    int a = 2;
    a = 3;
    std::cout << "a : " << a << '\n';
    //]

    //[const Constants as a promise
    const int b = 3;
    // b = 4; <- this fails. `b` is constant.
    std::cout << "b : " << b << '\n';
    //]

    //[const_2 `const` from mutable value
    // `b2` can be initialized with any value, but cannot be changed after this.
    // This is possible, but makes it impossible to know b2 in compile-time.
    const int b2 = a;
    std::cout << "b2 : " << b2 << '\n';
    //]

    //[constexpr Constant "more constant than const"
    // `c` can only use values available at compile-time
    // `c` cannot be initialized with a mutable value
    constexpr int c = 4;
    std::cout << "c : " << c << '\n';
    //]

    //[constexpr `constexpr` from mutable value
    // Impossible, we wouldn't know c2 in compile-time.
    // constexpr int c2 = a;
    //]


    //[array Creating arrays from mutable value
    // The compiler needs to know the size at compile time
    // Impossible:
    // std::array<int,a> v1;
    //]

    //[array_2 Creating arrays from compile-time `const` values
    // Sometimes possible, if b was not initialized with a mutable value
    std::array<int, b> v2 = {5, 6, 5};
    std::cout << "v2.size(): " << v2.size() << '\n';
    //]

    //[array_3 Creating arrays from runtime `const` values
    // Impossible (b2 depends on a variable):
    // std::array<int,b2> v2b;
    //]

    //[array_4 Creating arrays from compile-time `constexpr` values
    // Always possible
    std::array<int, c> v3 = {7, 8, 7, 8};
    std::cout << "v3.size(): " << v3.size() << '\n';
    //]

    return 0;
}