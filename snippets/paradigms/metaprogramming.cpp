#include <iostream>
#include <unordered_map>
#include <string>
#include <numeric>

template <unsigned n>
struct factorial {
  enum { value = n * factorial<n-1>::value };
};

template <>
struct factorial<0> {
  enum { value = 1 };
};

constexpr int factorial2(int n) {
    return n <= 1 ? 1 : (n * factorial2(n - 1));
}

struct MyClass {
    template<typename... Tail>
    static int count() {
        return 0;
    }

    template<char Head, char... Tail>
    static int count() {
        return 1 + count<Tail...>();
    }
};

int main() {
    std::cout << "factorial<7>::value : " << factorial<7>::value << std::endl;
    std::cout << "factorial2(7) : " << factorial2(7) << std::endl;
    std::cout << "MyClass::count<'f','o','o'>(): " << MyClass::count<'f','o','o'>() << std::endl;

    return 0;
}