#include <iostream>
#include <map>
#include <numeric>
#include <random>
//[headers Headers
#include <range/v3/all.hpp>
//]
#include <iterator>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution(1, 30);

    //[iota Sequentially increasing range
    std::vector<double> v(30);
    ranges::iota(v, 1);
    //]

    //[count Counting
    std::cout << ranges::count(v, 0) << '\n';
    //]

    //[accumulate Accumulating
    std::cout << ranges::accumulate(v, 0) << '\n';
    //]

    //[sort Sorting
    ranges::sort(v);
    //]

    //[binary_search Binary Search
    std::cout << ranges::binary_search(v, 15) << '\n';
    //]

    //[is_sorted Check if sorted
    std::cout << ranges::is_sorted(v) << '\n';
    //]

    //[for_each For each
    ranges::for_each(v, [](const int c) { std::cout << c << " "; });
    std::cout << '\n';
    //]

    //[filter Filter views
    std::array<int, 6> a{{0, 5, 2, 1, 3, 4}};
    auto filtered_range = ranges::views::filter(a, [](int i) { return i > 2; });
    std::vector<int> v2(filtered_range.begin(), filtered_range.end());
    //]
    // This failed in some compilers:
    // ranges::copy(filtered_range, std::back_inserter(v2));
    // `std::back_inserter(v2)` did not satisfy `weakly_incrementable`

    //[reverse_view Reversed view
    auto reversed_range = ranges::views::reverse(a);
    for (int x : reversed_range) {
        std::cout << x << ' ';
    }
    //]

    //[unique Unique view
    ranges::sort(a);
    auto unique_range = ranges::views::unique(a);
    for (int x : unique_range) {
        std::cout << x << ' ';
    }
    //]

    //[keys Keys view
    std::map<std::string, int> m;
    m["a"] = 0;
    m["b"] = 1;
    m["c"] = 2;
    auto map_keys = ranges::views::keys(m);
    for (const std::string &k : map_keys) {
        std::cout << k << ",";
    }
    //]

    //[tokenize Tokenize view
    std::string s = "The range v3 library";
    std::regex expr{"[\\w+]+"};
    auto tokenizer = ranges::views::tokenize(
        s, expr, 0, std::regex_constants::match_default);
    for (auto &x : tokenizer) {
        std::cout << x << ",";
    }
    //]

    //[ints Integer views
    auto ir = ranges::views::ints(0, 3);
    for (auto x : ir) {
        std::cout << x << ",";
    }
    //]

    return 0;
}