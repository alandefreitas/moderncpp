#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    // Strings are dynamic arrays of chars
    string p = "avocado";
    for (size_t i = 0; i < p.size(); ++i) {
        cout << "p[" << i << "]: " << p[i] << endl;
    }

    // Look for letter
    if (p.size() >= 10) {
        cout << "p[10]: " << p[10] << endl;
    } else {
        cout << "p[10]: (não existe)" << endl;
    }

    // Container functions
    cout << "p.size(): " << p.size() << endl;
    cout << "p.empty(): " << p.empty() << endl;
    cout << "p.front(): " << p.front() << endl;
    cout << "p.back(): " << p.back() << endl;

    // Contiguous addresses (like any array)
    cout << "&p: " << &p << endl;
    cout << "p.data(): " << p.data() << endl;

    // The address of a char prints what is in that position
    cout << "&p[0]: " << &p[0] << endl;
    cout << "&p[1]: " << &p[1] << endl;
    cout << "&p[2]: " << &p[2] << endl;
    cout << "&p[9]: " << &p[9] << endl;

    return 0;
}
