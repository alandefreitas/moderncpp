#include <iostream>
#include <unordered_map>

int main() {
    //[auto_pod Auto for fundamental data types
    auto dont_do_that = 87;
    std::cout << "dont_do_that: " << dont_do_that << '\n';
    //]

    //[container Creating a hash table for the next snippet
    std::unordered_map<std::string, double> t;
    t["zero"] = 0.0;
    t["pi"] = 3.14;
    t["ten"] = 10.0;
    //]

    //[no_auto Accessing container without `auto`
    // NOLINTNEXTLINE(modernize-use-auto)
    std::unordered_map<std::string, double>::iterator it = t.find("pi");
    if (it != t.end()) {
        std::cout << it->first << ": " << it->second << '\n';
    }
    //]

    //[with_auto Accessing container with `auto`
    // This is the perfect place for auto
    // - It avoids a long type name
    // - There's no ambiguity
    //   - Find will always return an iterator
    auto it2 = t.find("zero");
    if (it2 != t.end()) {
        std::cout << it2->first << ": " << it2->second << '\n';
    }
    //]

    //[decltype Get type from another variable
    decltype(it) it3;
    it3 = it;
    ++it3;
    if (it3 != t.end()) {
        std::cout << it3->first << ": " << it3->second << '\n';
    }
    //]

    //[functions `auto` in generic functions
    auto print_map_container = [](const auto &m) {
        for (auto &&item : m) {
            std::cout << item.first << ": " << item.second << '\n';
        }
    };
    print_map_container(t);
    //]

    return 0;
}