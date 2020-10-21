#include <iostream>
#include <tuple>
#include <unordered_map>

void reference_minmax(int a, int b, int &min, int &max) {
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
}

std::tuple<int, int> tuple_minmax(int a, int b) {
    std::tuple<int, int> t;
    if (a < b) {
        std::get<0>(t) = a;
        std::get<1>(t) = b;
    } else {
        std::get<0>(t) = b;
        std::get<1>(t) = a;
    }
    return t;
}

int main() {
    // Structure for results
    struct my_pair {
        char first;
        int second;
    };
    my_pair s{'c', 15};
    std::cout << "s.first: " << s.first << ", s.second: " << s.second
              << std::endl;

    // Tuples
    std::pair<char, int> t('c', 15);
    std::cout << "t.first: " << t.first << ", t.second: " << t.second
              << std::endl;

    // Using auto
    auto t2 = std::make_pair<char, int>('c', 15);
    std::cout << "t2.first: " << t2.first << ", t2.second: " << t2.second
              << std::endl;

    // Larger tuple
    auto t3 = std::make_tuple(6.3, "texto", 2, 'o');
    int x = std::get<3>(t3);
    std::cout << "std::get<0>(t3): " << std::get<0>(t3)
              << ", std::get<1>(t3): " << std::get<1>(t3) << std::endl;

    // Tie
    int a;
    char b;
    std::tie(std::ignore, std::ignore, a, b) = t3;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // "Returning" by reference
    int min;
    int max;
    reference_minmax(3, 2, min, max);
    std::cout << "min : " << min << std::endl;
    std::cout << "max : " << max << std::endl;

    // Returning a tuple
    auto t4 = tuple_minmax(3, 2);
    std::cout << "min : " << std::get<0>(t4) << std::endl;
    std::cout << "max : " << std::get<1>(t4) << std::endl;

    // Unpackaging the tuple
    int min2;
    int max2;
    std::tie(min2, max2) = tuple_minmax(3, 2);
    std::cout << "min : " << min2 << std::endl;
    std::cout << "max : " << max2 << std::endl;

    // Structured binding
    auto [min3, max3] = tuple_minmax(3, 2);
    std::cout << "min : " << min3 << std::endl;
    std::cout << "max : " << max3 << std::endl;

    return 0;
}