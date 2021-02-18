#include <array>
#include <iostream>

int main() {
    // Using namespace std in the main scope
    // - Almost never do that in a global scope
    // - Never do that in the global scope of a header file
    // - Probably not a good idea in other files too
    using namespace std;

    // Variable
    int a = 2;
    cout << "a : " << a << endl;

    // Constant as a promise
    const int b = 3;
    cout << "b : " << b << endl;

    // Possible, but makes it impossible to know
    // b2 in compile-time.
    const int b2 = a;
    cout << "b2 : " << b2 << endl;

    // Constant "more constant than const"
    constexpr int c = 4;
    cout << "c : " << c << endl;

    // Impossible, we wouldn't know c2 in compile-time.
    // constexpr int c2 = a;

    // Creating arrays of size a, b, c
    // The compiler needs to know the size at compile time

    // Impossible:
    // std::array<int,a> v1;

    // Sometimes possible
    std::array<int, b> v2 = {5, 6, 5};
    cout << "v2.size(): " << v2.size() << endl;

    // Impossible (b2 depends on a variable):
    // std::array<int,b2> v2b;

    // Always possible
    std::array<int, c> v3 = {7, 8, 7, 8};
    cout << "v3.size(): " << v3.size() << endl;

    return 0;
}