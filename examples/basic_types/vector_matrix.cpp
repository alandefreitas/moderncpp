#include <iostream>
#include <vector>
#include <array>

int main() {
    using namespace std;
    array<array<int,4>,3> a{
        array<int,4>{3, 4, 7, 4},
        array<int,4>{4, 7, 4, 2},
        array<int,4>{7, 8, 3, 6}
    };
    cout << a[0][0] << endl;
    cout << a[0][1] << endl;
    cout << a[0][2] << endl;
    cout << a[0][3] << endl;
    cout << a[1][0] << endl;
    cout << a[1][1] << endl;
    cout << a[1][2] << endl;
    cout << a[1][3] << endl;
    cout << a[2][0] << endl;
    cout << a[2][1] << endl;
    cout << a[2][2] << endl;
    cout << a[2][3] << endl;

    cout << &a[0][0] << endl;
    cout << &a[0][1] << endl;
    cout << &a[0][2] << endl;
    cout << &a[0][3] << endl;
    cout << &a[1][0] << endl;
    cout << &a[1][1] << endl;
    cout << &a[1][2] << endl;
    cout << &a[1][3] << endl;
    cout << &a[2][0] << endl;
    cout << &a[2][1] << endl;
    cout << &a[2][2] << endl;
    cout << &a[2][3] << endl;
    return 0;
}