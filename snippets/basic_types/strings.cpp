#include <array>
#include <iostream>
//[headers Headers
#include <string>
//]

int main() {
    //[construct Create string
    // Strings are dynamic arrays of chars
    std::string str = "avocado";
    //]

    //[print Print the whole string
    std::cout << str << '\n';
    //]

    //[print_chars Iterate the string chars
    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << "str[" << i << "]: " << str[i] << '\n';
    }
    //]

    //[access Access index
    if (str.size() >= 10) {
        std::cout << "str[10]: " << str[10] << '\n';
    } else {
        std::cout << "str[10]: (does not exist)" << '\n';
    }
    //]

    //[member Container functions
    std::cout << "str.size(): " << str.size() << '\n';
    std::cout << "str.empty(): " << str.empty() << '\n';
    std::cout << "str.front(): " << str.front() << '\n';
    std::cout << "str.back(): " << str.back() << '\n';
    //]

    //[access_address Contiguous addresses (like any array)
    std::cout << "&str: " << &str << '\n';
    std::cout << "str.data(): " << str.data() << '\n';
    //]

    //[subscript The subscript operator accesses a single char
    std::cout << "str[0]: " << str[0] << '\n';
    std::cout << "str[1]: " << str[1] << '\n';
    std::cout << "str[2]: " << str[2] << '\n';
    //]

    //[position The address of a `char` prints from that position
    std::cout << "&str[0]: " << &str[0] << '\n';
    std::cout << "&str[1]: " << &str[1] << '\n';
    std::cout << "&str[2]: " << &str[2] << '\n';
    //]

    return 0;
}
