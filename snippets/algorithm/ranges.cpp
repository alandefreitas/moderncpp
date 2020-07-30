#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <regex>
#include <map>
#include <string>
#include <range/v3/all.hpp>

int main() {
    using std::cout;
    using std::endl;
    using std::vector;
    using std::array;
    using std::map;
    using std::string;
    using std::regex;
    using namespace ranges;

    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution(1,30) ;

    // Algorithms
    vector<double> v(30);
    iota(v, 1);
    cout << count(v, 0) << endl;
    cout << accumulate(v, 0) << endl;
    sort(v);
    cout << binary_search(v,15) << endl;
    cout << is_sorted(v) << endl;
    for_each(v,[] (const int c) {cout << c << " ";});
    cout << endl;

    // Range views
    array<int, 6> a{{0, 5, 2, 1, 3, 4}};
    auto filtered_range = view::filter(a, [](int i){ return i > 2; });
    vector<int> v2;
    copy(filtered_range, back_inserter(v2));

    auto reversed_range = view::reverse(a);
    copy(reversed_range, ostream_iterator<int>{cout, " "});

    sort(a);
    auto unique_range = view::unique(a);
    copy(unique_range, ostream_iterator<int>{cout, " "});

    map<string, int> m;
    m["a"] = 0;
    m["b"] = 1;
    m["c"] = 2;
    auto map_keys = view::keys(m);
    copy(map_keys, ostream_iterator<string>{cout, ","});

    string s = "The range v3 library";
    regex expr{"[\\w+]+"};
    auto tokenizer = view::tokenize(s, expr, 0, std::regex_constants::match_default);
    copy(tokenizer, ostream_iterator<string>{cout, ","});

    auto ir = view::ints(0, 3);
    copy(ir, ostream_iterator<int>{cout, ","});

    return 0;
}