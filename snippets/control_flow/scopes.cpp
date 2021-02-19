#include <iostream>

int main() {
    using namespace std;
    int x = 1;
    cout << "External x: " << x << '\n';
    for (int i = 0; i < 2; ++i) {
        int y = 2;
        cout << "Internal i: " << i << '\n';
        cout << "External x: " << x << '\n';
        cout << "Internal y: " << y << '\n';
    }
    cout << "External x: " << x << '\n';

    // This won't work:
    // cout << "Internal i: " << i << '\n';
    // cout << "Internal y: " << y << '\n';
    return 0;
}