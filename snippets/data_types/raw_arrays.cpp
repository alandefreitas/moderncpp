#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    constexpr int n = 3;

    // Raw array
    // Examples only: don't use raw arrays!
    int temp[n] = {1, 2, 3};
    for (size_t i = 0; i < n; ++i) {
        cout << "temp[" << i << "]: " << temp[i] << endl;
    }

    // Array is converted to its initial pointer
    cout << "temp: " << temp << endl;
    cout << "&temp: " << &temp << endl;
    cout << "&temp[0]: " << &temp[0] << endl;
    cout << "&temp[1]: " << &temp[1] << endl;
    cout << "&temp[2]: " << &temp[2] << endl;

    return 0;
}
