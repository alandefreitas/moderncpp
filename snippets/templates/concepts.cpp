#include <array>
#include <concepts>
#include <iostream>
#include <type_traits>
#include <vector>

// Define concepts with a compile-time boolean predicate
// - is_arithmetic_v might be misleading since it also includes bool
// - is_arithmetic_v might be misleading since it doesn't include std::complex
template <typename T> concept Number = std::is_arithmetic_v<T>;

template<typename T> concept NotNumber = !Number<T>;

// Define concept from conjunction of constraints
template<typename T> concept SignedNumber = Number<T> && std::is_signed_v<T>;

template<typename T>
concept UnsignedNumber = Number<T> && !std::is_signed_v<T>;

// Define concept from disjunction of constraints
template<typename T1, typename T2>
concept Equivalent = std::is_convertible_v<T1, T2> || std::is_same_v<T1, T2>;

// Define concept from simple requires-expression
// These expressions must be something that will compile
template<typename T> concept Range = requires(T r) {
    *r.begin();
    *r.end();
};

// Typename requirement (e.g. check type exists)
// Define concept from typename requires-expression
// These expressions must something that will compile
template<typename T> concept HasValueType = requires(T r) {
    typename T::value_type; // required nested name
};

// Compound requirement
// Two requirements at the same time
template<typename T> concept Pair = requires(T p) {
    { p.first };
    { p.second };
};

// Typename requirement with type constraint
// The expression should not only compile but it should also have
// a type that passes the concept after ->
template<typename T> concept IntPair = requires(T p) {
    { p.first } -> std::same_as<int>;
    { p.second } -> std::same_as<int>;
};

// Requirement with two parameters
template<typename T>
concept EqualityComparable = requires(T a, T b) {
    { a == b };
    { a != b };
};


// Nested requirements
// Additional constraint to existing constraints
// Functions can use Range or RangeSameType now without
// ambiguity
template<typename T> concept PairSameType = Pair<T> && requires(T p) {
    { p.first } -> std::same_as<decltype(p.second)>;
};

// Nested requirements without requires
template<typename T> concept RangeWithValueType = Range<T> && HasValueType<T>;
template<typename T> concept RangeWithoutValueType = Range<T> && !HasValueType<T>;


// Constrain with template type
// Number, but nor SignedNumber neither UnsignedNumber
template<Number T>
void max_value(T a, T b) {
    if (a > b) {
        std::cout << "max_value: " << a << std::endl;
    } else {
        std::cout << "max_value: " << b << std::endl;
    }
}

// Constrain with template type
// Number -> SignedNumber
template<SignedNumber T>
void max_value(T a, T b) {
    if (a > b) {
        if (a > 0) {
            std::cout << "max_value: positive " << a << std::endl;
        } else {
            std::cout << "max_value: negative " << -a << std::endl;
        }
    } else {
        if (b > 0) {
            std::cout << "max_value: positive " << b << std::endl;
        } else {
            std::cout << "max_value: negative " << -b << std::endl;
        }
    }
}

// Constrain with template type
// Number -> UnsignedNumber
template<UnsignedNumber T>
void max_value(T a, T b) {
    if (a > b) {
        std::cout << "max_value: +" << a << std::endl;
    } else {
        std::cout << "max_value: +" << b << std::endl;
    }
}

// Constrain with template type
// NotNumber == !Number<T>
template<NotNumber T>
void max_value(T a, T b) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

// Unconstrained function (Not range)
template<class T>
void print_element(const T &c) {
    std::cout << c << std::endl;
}

// Constrained with template type
// - The most constrained concept is used
template<Range T>
void print_element(const T &c) {
    for (const auto &item : c) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

// Constrain the same function with a more constrained template type
// - The most constrained concept is used in nested constraints
template<RangeWithValueType T>
void print_element(const T &c) {
    std::cout << typeid(typename T::value_type).name() << ": ";
    for (const auto &item : c) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

// Constrain with require-clause directly in function declaration
template<typename T>
requires EqualityComparable<T>
void compare(const T &a, const T &b) {
    if (a == b) {
        std::cout << a << " == " << b << " is " << (a == b ? "true" : "false") << std::endl;
    } else {
        std::cout << a << " != " << b << " is " << (a != b ? "true" : "false") << std::endl;
    }
}

// Unconstrained version
template<typename T>
void compare(const T &a, const T &b) {
    std::cout << typeid(T).name() << ": " << a.c << " == " << b.c << "?" << std::endl;
}

struct nonComparableStruct {
    double c{0.};
};

// Constrain with template type
template<Pair T>
void print_pair(const T &p) {
    std::cout << typeid(p.first).name() << ": " << p.first << " == " << typeid(p.second).name() << ": " << p.second
              << std::endl;
}

// Constrain again with more specific requirement
template<PairSameType T>
void print_pair(const T &p) {
    std::cout << typeid(p.first).name() << ": " << p.first << " == " << p.second << std::endl;
}


int main() {
    /*
     * \see https://en.cppreference.com/w/cpp/language/constraints
     */
    max_value(5, 7);
    max_value(4, 7);
    max_value("foo", "bar");

    print_element(std::vector<int>{2, 4, 6, 4});
    print_element(56);

    compare(4, 7);
    compare(nonComparableStruct{1.0}, nonComparableStruct{2.0});

    print_pair(std::make_pair(1, 2));
    print_pair(std::make_pair(1.6, 2));

    return 0;
}
