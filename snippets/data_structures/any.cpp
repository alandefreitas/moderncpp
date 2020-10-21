#include <any>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    // any is a container for single values of any type
    // - be careful when using it
    cout << boolalpha;

    // any type
    any a = 1;

    cout << a.type().name() << ": " << any_cast<int>(a) << '\n';
    a = 3.14;
    cout << a.type().name() << ": " << any_cast<double>(a) << '\n';
    a = true;
    cout << a.type().name() << ": " << any_cast<bool>(a) << '\n';
    a = string("Any string");
    cout << a.type().name() << ": " << any_cast<string>(a) << '\n';

    try {
        any a = 1;
        cout << any_cast<float>(a) << '\n';
    } catch (bad_any_cast &e) {
        cout << e.what() << '\n';
    }

    any s2 = 1;
    if (!s2.has_value()) {
        const type_info &ti = s2.type();
        cout << ti.name() << '\n';
    }

    any a3 = 1;
    int *i = any_cast<int>(&a3);
    cout << *i << '\n';

    return 0;
}