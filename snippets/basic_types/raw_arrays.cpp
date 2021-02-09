#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    constexpr int n = 3;

    // Raw arrays
    // - Examples only: don't use raw arrays!

    // Explicit size
    int a[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    cout << "a: " << a << '\n';

    // Implicit size
    int b[] = {1, 2, 3};
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

    return 0;
}
