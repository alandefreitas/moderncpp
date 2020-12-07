#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <range/v3/all.hpp>
#include <regex>
#include <string>
#include <vector>

int main() {
    using std::array;
    using std::cout;
    using std::endl;
    using std::map;
    using std::regex;
    using std::string;
    using std::vector;
    using namespace ranges;

    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution(1, 30);

    // Algorithms
    vector<double> v(30);
    iota(v, 1);
    cout << count(v, 0) << endl;
    cout << accumulate(v, 0) << endl;
    sort(v);
    cout << binary_search(v, 15) << endl;
    cout << is_sorted(v) << endl;
    for_each(v, [](const int c) { cout << c << " "; });
    cout << endl;

    // Range views
    array<int, 6> a{{0, 5, 2, 1, 3, 4}};
    auto filtered_range = views::filter(a, [](int i) { return i > 2; });
    vector<int> v2;
    copy(filtered_range, back_inserter(v2));

    auto reversed_range = views::reverse(a);
    copy(reversed_range, ostream_iterator<int>{cout, " "});

    sort(a);
    auto unique_range = views::unique(a);
    copy(unique_range, ostream_iterator<int>{cout, " "});

    map<string, int> m;
    m["a"] = 0;
    m["b"] = 1;
    m["c"] = 2;
    auto map_keys = views::keys(m);
    copy(map_keys, ostream_iterator<string>{cout, ","});

    string s = "The range v3 library";
    regex expr{"[\\w+]+"};
    auto tokenizer =
            views::tokenize(s, expr, 0, std::regex_constants::match_default);
    copy(tokenizer, ostream_iterator<string>{cout, ","});

    auto ir = views::ints(0, 3);
    copy(ir, ostream_iterator<int>{cout, ","});

    return 0;
}