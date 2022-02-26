#include <array>
//[headers Headers
#include <concepts>
//]
#include <iostream>
#include <type_traits>
#include <vector>

//[boolean Define concept from a compile-time boolean predicate
template <typename T> concept Number = std::is_arithmetic_v<T>;

// is_arithmetic_v might be misleading since it also includes bool
// is_arithmetic_v might be misleading since it doesn't include std::complex
//]

//[from_concept Define concept from a another concepts as a boolean predicate
template<typename T> concept NotNumber = !Number<T>;
//]

//[conjunction Define concept from a conjunction of constraints
template<typename T> concept SignedNumber = Number<T> && std::is_signed_v<T>;
//]

//[conjunction_2 Define alternative mutually exclusive Number concept
template<typename T>
concept UnsignedNumber = Number<T> && !std::is_signed_v<T>;
//]

//[disjunction Define concept from disjunction of constraints
template<typename T1, typename T2>
concept Equivalent = std::is_convertible_v<T1, T2> || std::is_same_v<T1, T2>;
//]

//[requires Define concept from requires-expression
// These expressions must be something that will compile
template<typename T> concept Range = requires(T r) {
    *r.begin();
    *r.end();
};
//]

//[require_typename Define concept from typename requirement
// These expressions must something that will compile
template<typename T> concept HasValueType = requires(T r) {
    typename T::value_type; // required nested name
};
//]

//[compound Compound requirement
// Two requirements at the same time
template<typename T> concept Pair = requires(T p) {
    { p.first };
    { p.second };
};
//]

//[typename Typename requirement from expression type constraint
// The expression should not only compile, but it should also have
// a type that passes the concept after ->
template<typename T> concept IntPair = requires(T p) {
    { p.first } -> std::same_as<int>;
    { p.second } -> std::same_as<int>;
};
//]

//[two_params Requirement with two parameters
template<typename T>
concept EqualityComparable = requires(T a, T b) {
    { a == b };
    { a != b };
};
//]

//[nested_require Nested requirements
// Additional constraint to existing constraints
// Functions can use Range or RangeSameType now without ambiguity
template<typename T> concept PairSameType = Pair<T> && requires(T p) {
    { p.first } -> std::same_as<decltype(p.second)>;
};
//]

//[nested_requirement_no_require Nested requirements without requires
template<typename T> concept RangeWithValueType = Range<T> && HasValueType<T>;
template<typename T> concept RangeWithoutValueType = Range<T> && !HasValueType<T>;
//]

//[number_fn Constrain function to numbers
// Number, but nor SignedNumber neither UnsignedNumber
template<Number T>
void max_value(T a, T b) {
    if (a > b) {
        std::cout << "max_value: " << a << '\n';
    } else {
        std::cout << "max_value: " << b << '\n';
    }
}
//]

//[signed_fn Constrain function to signed numbers
// This function is used when Number is SignedNumber
template <SignedNumber T>
void max_value(T a, T b) {
    if (a > b) {
        if (a > 0) {
            std::cout << "max_value: positive " << a << '\n';
        } else {
            std::cout << "max_value: negative " << -a << '\n';
        }
    } else {
        if (b > 0) {
            std::cout << "max_value: positive " << b << '\n';
        } else {
            std::cout << "max_value: negative " << -b << '\n';
        }
    }
}
//]

//[unsigned_fn Constrain function to unsigned numbers
// This function is used when Number is UnsignedNumber
template<UnsignedNumber T>
void max_value(T a, T b) {
    if (a > b) {
        std::cout << "max_value: +" << a << '\n';
    } else {
        std::cout << "max_value: +" << b << '\n';
    }
}
//]

//[not_num_fn Constrain function to non-numbers
// NotNumber == !Number<T>
template<NotNumber T>
void max_value(T a, T b) {
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}
//]

//[unconstrained_fn Unconstrained function
template <class T>
void print_element(const T &c) {
    std::cout << c << '\n';
}
//]

//[range_fn Constrain function to Ranges
// - The most constrained concept is always used
template<Range T>
void print_element(const T &c) {
    for (const auto &item : c) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}
//]

//[range_value_fn Constrain function to ranges with value type member
// The most constrained concept is used in nested constraints
template<RangeWithValueType T>
void print_element(const T &c) {
    std::cout << typeid(typename T::value_type).name() << ": ";
    for (const auto &item : c) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}
//]

//[equal_compare_fn Constrain with require-clause directly in function declaration
template<typename T>
requires EqualityComparable<T>
void compare(const T &a, const T &b) {
    if (a == b) {
        std::cout << a << " == " << b << " is " << (a == b ? "true" : "false") << '\n';
    } else {
        std::cout << a << " != " << b << " is " << (a != b ? "true" : "false") << '\n';
    }
}
//]

//[compare_fn_unconstrained Unconstrained function
template<typename T>
void compare(const T &a, const T &b) {
    std::cout << typeid(T).name() << ": " << a.c << " == " << b.c << "?" << '\n';
}
//]

//[pair_fn Constrain function to pairs
template<Pair T>
void print_pair(const T &p) {
    std::cout << typeid(p.first).name() << ": " << p.first << ", " << typeid(p.second).name() << ": " << p.second
              << '\n';
}
//]

//[pair_same_fn Constrain function to pairs of same type
template<PairSameType T>
void print_pair(const T &p) {
    std::cout << typeid(p.first).name() << ": " << p.first << ", " << p.second << '\n';
}
//]

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

    struct nonComparableStruct {
        double c{0.};
    };
    compare(nonComparableStruct{1.0}, nonComparableStruct{2.0});

    print_pair(std::make_pair(1, 2));
    print_pair(std::make_pair(1.6, 2));

    return 0;
}
