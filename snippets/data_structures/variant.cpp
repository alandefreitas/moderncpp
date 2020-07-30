#include <iostream>
#include <vector>
#include <numeric>
#include <variant>

using namespace std;

union my_union {
    double a;
    char b;
    int c;
};

int main() {
    // The old union
    // - It only works with fundamental data type
    // - It doesn't have many convenience function
    my_union u = {3.14};
    u = {'A'};
    u = {15};

    // Variant types
    // - Only use variant types if you really need it
    variant<double, char, string> v;
    v = 3.14;
    v = 'A';
    v = "Some longer text";
    visit([](auto x) { cout << x << '\n'; }, v);

    v = 3.14;
    cout << get<double>(v) << endl;
    v = 'A';
    cout << get<char>(v) << endl;
    v = "Some longer text";
    cout << get<string>(v) << endl;

    switch (v.index()) {
        case 0:
            cout << "This is a double" << endl;
        case 1:
            cout << "This is a char" << endl;
        case 2:
            cout << "This is a string" << endl;
    }

    return 0;
}