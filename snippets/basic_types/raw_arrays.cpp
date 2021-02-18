#include <array>
#include <iostream>
#include <string>


int main() {
    using namespace std;

    constexpr int n = 3;

    // Raw arrays
    // - Examples only: don't use raw arrays!

    // Explicit size
    int a[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    cout << "a: " << a << '\n';

    // Accessing elements
    cout << "a[0]: " << a[0] << '\n';
    cout << "a[1]: " << a[1] << '\n';
    cout << "a[2]: " << a[2] << '\n';

    // Accessing element address
    cout << "&a[0]: " << &a[0] << '\n';
    cout << "&a[1]: " << &a[1] << '\n';
    cout << "&a[2]: " << &a[2] << '\n';

    // Implicit size
    int b[] = {1, 2, 3};

    // Accessing elements
    for (size_t i = 0; i < n; ++i) {
        cout << "b[" << i << "]: " << b[i] << endl;
    }

    // Array is converted to its initial pointer
    cout << "b: " << b << endl;
    cout << "&b: " << &b << endl;

    cout << "b[0]: " << b[0] << endl;
    cout << "&b[0]: " << &b[0] << endl;

    cout << "b[1]: " << b[1] << endl;
    cout << "&b[1]: " << &b[1] << endl;

    cout << "b[2]: " << b[2] << endl;
    cout << "&b[2]: " << &b[2] << endl;

    // Raw strings are just arrays of chars
    char c[] = { 'a', 'b', 't', '\0' };

    // Raw strings are streamed until '\0' is found
    cout << "c: " << c << endl;

    return 0;
}
