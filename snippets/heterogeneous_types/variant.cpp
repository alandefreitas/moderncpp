#include <iostream>
#include <numeric>
#include <variant>

using namespace std;

union my_union {
    double a;
    char b;
    int c;
};

int main() {
    // The "old" union
    // - It only works with fundamental data type
    // - It doesn't have many convenience function
    my_union u = {3.14};
    u = {'A'};
    u = {15};

    // A union is as large as the largest type in the union
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(my_union): " << sizeof(my_union) << '\n';

    // Variant types
    // - Only use variant types if you really need them
    variant<double, char, string> v;

    // Settings values
    // - If we defined a variant including lots of types, including
    //   booleans and lists, this would be somewhat similar to:
    //   - PHP:         $v = 3.14;    // see https://bit.ly/3cVuJvb
    //   - Python:      v = 3.14;
    //   - Javascript:  var v = 3.14;
    v = 3.14;
    v = 'A';
    v = "Some longer text";

    // A variant is larger than the largest type in the variant
    // - This happens because variants need a flag to indicate the current type
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(string): " << sizeof(string) << '\n';
    std::cout << "sizeof(variant<double, char, string>): "
              << sizeof(variant<double, char, string>) << '\n';

    // Getting values
    v = 3.14;
    cout << get<double>(v) << '\n';
    v = 'A';
    cout << get<char>(v) << '\n';
    v = "Some longer text";
    cout << get<string>(v) << '\n';

    // Visiting / Applying function to value
    visit([](auto x) { cout << x << '\n'; }, v);

    // Checking current alternative index
    switch (v.index()) {
    case 0:
        cout << "This is a double\n";
        break;
    case 1:
        cout << "This is a char\n";
        break;
    case 2:
        cout << "This is a string\n";
        break;
    }

    // Checking current alternative type
    if (std::holds_alternative<double>(v)) {
        cout << "This is a double\n";
    } else if (std::holds_alternative<char>(v)) {
        cout << "This is a char\n";
    } else if (std::holds_alternative<std::string>(v)) {
        cout << "This is a string\n";
    }

    return 0;
}
