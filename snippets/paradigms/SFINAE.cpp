#include <iostream>
#include <numeric>
#include <type_traits>
#include <array>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i) {
    return bool(i % 2);
}

// 2. the second template argument is only valid if T is an integral type:
template <class T,
          class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i) {
    return !bool(i % 2);
}

struct A {};
class B {};
union C {
    int i;
    float f;
};
enum class D { x, y, z };

int main() {
    std::cout << "Modern C++:" << std::endl;
    {
        // Run-time SFINAE
        std::cout << "int: " << std::is_floating_point<int>::value << std::endl;
        std::cout << "float: " << std::is_floating_point<float>::value
                  << std::endl;
        std::cout << "const double: "
                  << std::is_floating_point<const double>::value << std::endl;
        std::cout << "int: " << std::is_array<int>::value << std::endl;
        std::cout << "int[3]: " << std::is_array<int[3]>::value << std::endl;
        std::cout << "array<int,3>: "
                  << std::is_array<std::array<int, 3>>::value << std::endl;
        std::cout << "string: " << std::is_array<std::string>::value
                  << std::endl;
        std::cout << "string[3]: " << std::is_array<std::string[3]>::value
                  << std::endl;
        std::cout << "A: " << std::is_class<A>::value << std::endl;
        std::cout << "B: " << std::is_class<B>::value << std::endl;
        std::cout << "C: " << std::is_class<C>::value << std::endl;
        std::cout << "D: " << std::is_class<D>::value << std::endl;
        std::cout << "A: " << std::is_enum<A>::value << std::endl;
        std::cout << "B: " << std::is_enum<B>::value << std::endl;
        std::cout << "C: " << std::is_enum<C>::value << std::endl;
        std::cout << "is_odd: "
                  << std::is_function<decltype(is_odd<int>)>::value
                  << std::endl;
        std::cout << "id_even: "
                  << std::is_function<decltype(is_even<int>)>::value
                  << std::endl;
        std::cout << "decltype(c): " << std::is_function<C>::value << std::endl;
        std::cout << "char: " << std::is_integral<char>::value << std::endl;
        std::cout << "int: " << std::is_integral<int>::value << std::endl;
        std::cout << "float: " << std::is_integral<float>::value << std::endl;
        std::cout << "int: " << std::is_pointer<int>::value << std::endl;
        std::cout << "int*: " << std::is_pointer<int *>::value << std::endl;
        std::cout << "int**: " << std::is_pointer<int **>::value << std::endl;
        std::cout << "int(*)(int): " << std::is_pointer<int (*)(int)>::value
                  << std::endl;
        std::cout << "int: " << std::is_scalar<int>::value << std::endl;
        std::cout << "A: " << std::is_scalar<A>::value << std::endl;
        std::cout << "A&: " << std::is_scalar<A &>::value << std::endl;
        std::cout << "A*: " << std::is_scalar<A *>::value << std::endl;
        std::cout << "int(int): " << std::is_scalar<int(int)>::value
                  << std::endl;
        std::cout << "int(*)(int): " << std::is_scalar<int (*)(int)>::value
                  << std::endl;
        std::cout << "char: " << std::is_arithmetic<char>::value << std::endl;
        std::cout << "float: " << std::is_arithmetic<float>::value << std::endl;
        std::cout << "float*: " << std::is_arithmetic<float *>::value
                  << std::endl;

        // SFINAE on functions
        std::cout << "i is odd: " << is_odd(1)
                  << std::endl; // is_odd(1.2) wouldn't work
        std::cout << "i is even: " << is_even(1)
                  << std::endl; // is_even(1.2) wouldn't work
    }
    return 0;
}

/*
 // Concepts are only available in C++20 (not the final version yet)
 // We have to use SFINAE (Substitution error is not a failure) in the meanwhile

 template <class T>
    concept bool EqualityComparable() {
       return requires(T a, T b) {
           {a == b} -> Boolean; // Boolean is the concept defining a type usable
 in boolean context {a != b} -> Boolean;
       };
    }

    void f(const EqualityComparable&); // constrained function template
 declaration

    https://www.boost.org/doc/libs/1_60_0/libs/concept_check/using_concept_check.htm
*/
