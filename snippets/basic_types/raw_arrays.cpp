#include <array>
#include <iostream>
#include <string>


int main() {

    // Raw arrays
    // - Examples only: don't use raw arrays!

    //[explicit Explicit size
    constexpr int n = 3;
    int a[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    std::cout << "a: " << a << '\n';
    //]

    //[accessing Accessing elements
    std::cout << "a[0]: " << a[0] << '\n';
    std::cout << "a[1]: " << a[1] << '\n';
    std::cout << "a[2]: " << a[2] << '\n';
    //]

    //[accessing_address Accessing element address
    std::cout << "&a[0]: " << &a[0] << '\n';
    std::cout << "&a[1]: " << &a[1] << '\n';
    std::cout << "&a[2]: " << &a[2] << '\n';
    //]

    //[implicit Implicit size
    int b[] = {1, 2, 3};
    //]

    //[accessing_loop Accessing elements in a loop
    for (size_t i = 0; i < n; ++i) {
        std::cout << "b[" << i << "]: " << b[i] << '\n';
    }
    //]

    //[print Array is converted to its initial pointer
    std::cout << "b: " << b << '\n';
    std::cout << "&b: " << &b << '\n';
    std::cout << "b[0]: " << b[0] << '\n';
    std::cout << "&b[0]: " << &b[0] << '\n';
    //]

    //[print_sequence Array addresses are sequential
    std::cout << "b[1]: " << b[1] << '\n';
    std::cout << "&b[1]: " << &b[1] << '\n';
    std::cout << "b[2]: " << b[2] << '\n';
    std::cout << "&b[2]: " << &b[2] << '\n';
    //]

    //[string_array Raw strings are just arrays of chars
    char c[] = { 'a', 'b', 't', '\0' };
    // same as:
    char d[] = "abt";
    //]

    //[string_cout Raw strings are streamed until '\0' is found
    std::cout << "c: " << c << '\n';
    std::cout << "d: " << d << '\n';
    //]

    return 0;
}
