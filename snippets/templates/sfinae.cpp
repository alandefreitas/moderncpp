#include <array>
#include <iostream>
//[headers Headers
#include <type_traits>
//]
#include <array>
#include <numeric>

//[arith Constrain parameter type to arithmetic types
// The overload fails if the first parameter is not arithmetic
template <class T>
void max(std::enable_if_t<std::is_arithmetic_v<T>, T> a, T b) {
    if (a > b) {
        std::cout << "max: " << a << '\n';
    } else {
        std::cout << "max: " << b << '\n';
    }
}
//]

//[no_arith Constrain parameter type to not arithmetic
// The overload fails if the first parameter is arithmetic
template <class T>
void max(std::enable_if_t<!std::is_arithmetic_v<T>, T> a, T b) {
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}
//]

void call_max() {
    //[call_max SFINAE: Substitution Failure is Not An Error
    max(5, 7);         // call overload for arithmetic types
    max("foo", "bar"); // call overload for non-arithmetic types
    //]
}

//[bool Constrain on the return type
// The return type (bool) is only valid if T is an integral type:
template <class T> std::enable_if_t<std::is_integral_v<T>, bool> is_odd(T i) {
    return bool(i % 2);
}
//]

//[bool_param Constrain on the parameter list
// The second template argument is only valid if T is an integral type
template <class T, class = std::enable_if_t<std::is_integral_v<T>>>
bool is_even(T i) {
    return !bool(i % 2);
}
//]

void call_is_odd() {
    //[call_is_odd SFINAE on functions
    std::cout << "i is odd: " << is_odd(1) << '\n'; // is_odd(1.2) wouldn't work
    std::cout << "i is even: " << is_even(1)
              << '\n'; // is_even(1.2) wouldn't work
    //]
}

struct A {};
class B {};
union C {
    int i;
    float f;
};
enum class D { x, y, z };

int main() {
    call_max();
    call_is_odd();

    //[traits_float Floating point traits
    std::cout << "int: " << std::is_floating_point<int>::value << '\n';
    std::cout << "float: " << std::is_floating_point<float>::value << '\n';
    std::cout << "const double: " << std::is_floating_point<const double>::value
              << '\n';
    //]

    //[traits_array Array traits
    std::cout << "int: " << std::is_array<int>::value << '\n';
    std::cout << "int[3]: " << std::is_array<int[3]>::value << '\n';
    std::cout << "array<int,3>: " << std::is_array<std::array<int, 3>>::value
              << '\n';
    std::cout << "string: " << std::is_array<std::string>::value << '\n';
    std::cout << "string[3]: " << std::is_array<std::string[3]>::value << '\n';
    //]

    //[traits_class Class traits
    std::cout << "A: " << std::is_class<A>::value << '\n';
    std::cout << "B: " << std::is_class<B>::value << '\n';
    std::cout << "C: " << std::is_class<C>::value << '\n';
    std::cout << "D: " << std::is_class<D>::value << '\n';
    std::cout << "A: " << std::is_enum<A>::value << '\n';
    std::cout << "B: " << std::is_enum<B>::value << '\n';
    std::cout << "C: " << std::is_enum<C>::value << '\n';
    //]

    //[traits_function Function traits
    std::cout << "is_odd: " << std::is_function<decltype(is_odd<int>)>::value
              << '\n';
    std::cout << "id_even: " << std::is_function<decltype(is_even<int>)>::value
              << '\n';
    std::cout << "decltype(c): " << std::is_function<C>::value << '\n';
    //]

    //[traits_integral Integral traits
    std::cout << "char: " << std::is_integral<char>::value << '\n';
    std::cout << "int: " << std::is_integral<int>::value << '\n';
    std::cout << "float: " << std::is_integral<float>::value << '\n';
    //]

    //[traits_pointer Pointer traits
    std::cout << "int: " << std::is_pointer<int>::value << '\n';
    std::cout << "int*: " << std::is_pointer<int *>::value << '\n';
    std::cout << "int**: " << std::is_pointer<int **>::value << '\n';
    std::cout << "int(*)(int): " << std::is_pointer<int (*)(int)>::value
              << '\n';
    //]

    //[traits_scalar Scalar traits
    std::cout << "int: " << std::is_scalar<int>::value << '\n';
    std::cout << "A: " << std::is_scalar<A>::value << '\n';
    std::cout << "A&: " << std::is_scalar<A &>::value << '\n';
    std::cout << "A*: " << std::is_scalar<A *>::value << '\n';
    std::cout << "int(int): " << std::is_scalar<int(int)>::value << '\n';
    std::cout << "int(*)(int): " << std::is_scalar<int (*)(int)>::value << '\n';
    std::cout << "char: " << std::is_arithmetic<char>::value << '\n';
    std::cout << "float: " << std::is_arithmetic<float>::value << '\n';
    std::cout << "float*: " << std::is_arithmetic<float *>::value << '\n';
    //]



    return 0;
}
