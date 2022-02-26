#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

//[factorial Factorial value computed as constant class value
template <unsigned n> struct factorial {
    enum { value = n * factorial<n - 1>::value };
};

template <> struct factorial<0> {
    enum { value = 1 };
};
//]

void call_meta() {
    //[call_factorial Accessing factorial value calculated at compile-time
    std::cout << "factorial<7>::value : " << factorial<7>::value << '\n';
    //]
}

//[constexpr Computing at compile time with constexpr
constexpr int factorial2(int n) { return n <= 1 ? 1 : (n * factorial2(n - 1)); }
//]

void call_constexpr() {
    //[call_factorial Accessing factorial value calculated at compile-time
    std::cout << "factorial2(7) : " << factorial2(7) << '\n';
    //]
}

//[meta_count Count number of elements
struct MyClass {
    template <typename... Tail> static int count() { return 0; }

    template <char Head, char... Tail> static int count() {
        return 1 + count<Tail...>();
    }
};
//]

void call_count() {
    //[call_count Access number of elements
    std::cout << "MyClass::count<'f','o','o'>(): "
              << MyClass::count<'f', 'o', 'o'>() << '\n'; // 3
    //]
}

int main() {
    call_meta();
    call_constexpr();
    call_count();
    return 0;
}