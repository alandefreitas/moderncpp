#include <iostream>
#include <unordered_map>

int main() {
    using std::cout;
    using std::endl;

    // Auto for fundamental data types
    // - Example only: don't do that for fundamental data types!
    // - This is a bad place for auto
    //   - It does not avoid a long type name
    //   - It creates ambiguity
    //     - 87 could *semantically* be any number type
    // - This is somewhat equivalent to:
    //   - swift:  var dont_do_that = 87
    //   - rust:   let mut dont_do_that = 87
    auto dont_do_that = 87;
    cout << "dont_do_that: " << dont_do_that << endl;

    // Creating a hash table for the next example
    std::unordered_map<std::string, double> t;
    t["zero"] = 0.0;
    t["pi"] = 3.14;
    t["ten"] = 10.0;

    // Without auto
    // NOLINTNEXTLINE(modernize-use-auto)
    std::unordered_map<std::string, double>::iterator it = t.find("pi");
    if (it != t.end()) {
        cout << it->first << ": " << it->second << endl;
    }

    // With auto
    // This is the perfect place for auto
    // - It avoids a long type name
    // - There's no ambiguity
    //   - Find will always return an iterator
    auto it2 = t.find("zero");
    if (it2 != t.end()) {
        cout << it2->first << ": " << it2->second << endl;
    }

    // Get type from another variable
    decltype(it) it3;
    it3 = it;
    ++it3;
    if (it3 != t.end()) {
        cout << it3->first << ": " << it3->second << endl;
    }

    // Auto is also very useful for generic functions
    auto print_map_container = [](const auto &m) {
        for (auto &&item : m) {
            std::cout << item.first << ": " << item.second << std::endl;
        }
    };
    print_map_container(t);

    return 0;
}