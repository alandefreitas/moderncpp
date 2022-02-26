#include <iostream>
#include <unordered_map>
//[headers Headers
#include <tuple>
//]

//[return_ref Returning values by reference
void reference_minmax(int a, int b, int &min, int &max) {
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
}
//]

//[return_tuple Returning values with std::tuple
std::tuple<int, int> tuple_minmax(int a, int b) {
    if (a < b) {
        return std::make_tuple(a, b);
    } else {
        return std::make_tuple(b, a);
    }
}
//]

void call_tuple_fns() {
    //[return_ref_call Call function "returning" by reference
    int min;
    int max;
    reference_minmax(3, 2, min, max);
    std::cout << "min : " << min << '\n';
    std::cout << "max : " << max << '\n';
    //]

    //[return_tuple_call Call function returning a tuple
    auto t4 = tuple_minmax(3, 2);
    std::cout << "min : " << std::get<0>(t4) << '\n';
    std::cout << "max : " << std::get<1>(t4) << '\n';
    //]
}

int main() {
    //[custom_pair Custom pair structure for results
    struct my_pair {
        char first;
        int second;
    };
    // ...
    my_pair s{'c', 15};
    std::cout << "s.first: " << s.first << ", s.second: " << s.second << '\n';
    //]

    //[std_pair std::pair for results
    std::pair<char, int> p{'c', 15};
    std::cout << "p.first: " << p.first << ", p.second: " << p.second << '\n';
    //]

    //[std_tuple std::tuple for results
    std::pair<char, int> t('c', 15);
    std::cout << "t.first: " << t.first << ", t.second: " << t.second << '\n';
    //]

    //[auto_tuple Using type deduction
    auto t2 = std::make_pair<char, int>('c', 15);
    std::cout << "t2.first: " << t2.first << ", t2.second: " << t2.second
              << '\n';
    //]

    //[large_tuples Larger tuples
    auto t3 = std::make_tuple(6.3, "text", 2, 'o');
    char x = std::get<3>(t3);
    std::cout << "x: " << x << '\n';
    std::cout << "std::get<0>(t3): " << std::get<0>(t3)
              << ", std::get<1>(t3): " << std::get<1>(t3) << '\n';
    //]

    //[std_tie std::tie
    int a;
    char b;
    std::tie(std::ignore, std::ignore, a, b) = t3;
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    //]

    call_tuple_fns();

    //[unpack_tuple Unpacking a tuple
    int min2;
    int max2;
    std::tie(min2, max2) = tuple_minmax(3, 2);
    std::cout << "min : " << min2 << '\n';
    std::cout << "max : " << max2 << '\n';
    //]

    //[unpack_struct Structured binding
    auto [min3, max3] = tuple_minmax(3, 2);
    std::cout << "min : " << min3 << '\n';
    std::cout << "max : " << max3 << '\n';
    //]

    return 0;
}