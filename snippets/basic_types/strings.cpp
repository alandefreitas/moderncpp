#include <array>
#include <iostream>
#include <string>


int main() {
    using namespace std;

    // Strings are dynamic arrays of chars
    string str = "avocado";

    // Print the whole string
    cout << str << '\n';

    // Print the string chars
    for (size_t i = 0; i < str.size(); ++i) {
        cout << "str[" << i << "]: " << str[i] << '\n';
    }

    // Access index
    if (str.size() >= 10) {
        cout << "str[10]: " << str[10] << '\n';
    } else {
        cout << "str[10]: (does not exist)" << '\n';
    }

    // Container functions
    cout << "str.size(): " << str.size() << '\n';
    cout << "str.empty(): " << str.empty() << '\n';
    cout << "str.front(): " << str.front() << '\n';
    cout << "str.back(): " << str.back() << '\n';

    // Contiguous addresses (like any array)
    cout << "&str: " << &str << '\n';
    cout << "str.data(): " << str.data() << '\n';

    // The subscript operator accesses a single char
    cout << "str[0]: " << str[0] << '\n';
    cout << "str[1]: " << str[1] << '\n';
    cout << "str[2]: " << str[2] << '\n';

    // The address of a char prints from that position
    cout << "&str[0]: " << &str[0] << '\n';
    cout << "&str[1]: " << &str[1] << '\n';
    cout << "&str[2]: " << &str[2] << '\n';

    return 0;
}
