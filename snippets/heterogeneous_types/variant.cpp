#include <iostream>
#include <numeric>
#include <variant>

int main() {
    //[decl_union Declare an C union
    union my_union {
        double a;
        char b;
        int c;
    };
    //]

    //[use_union Using unions
    // - It only works with fundamental data type
    // - It doesn't have convenience functions
    my_union u = {3.14};
    u = {'A'};
    u = {15};
    //]

    //[size_union Union size
    // A union is as large as the largest type in the union
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(my_union): " << sizeof(my_union) << '\n';
    //]

    //[decl_variant Declaring a variant type
    std::variant<double, char, std::string> v;
    //]

    //[set_value Setting variant values
    v = 3.14;               // becomes double
    v = 'A';                // becomes char
    v = "Some longer text"; // becomes std::string
    //]

    //[variant_size Variant size
    // A variant is larger than the largest type in the variant
    // This happens because variants need a flag to indicate the current type
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(string): " << sizeof(std::string) << '\n';
    std::cout << "sizeof(variant<double, char, std::string>): "
              << sizeof(std::variant<double, char, std::string>) << '\n';
    //]

    //[access Accessing values
    v = 3.14;
    std::cout << get<double>(v) << '\n';
    v = 'A';
    std::cout << get<char>(v) << '\n';
    v = "Some longer text";
    std::cout << get<std::string>(v) << '\n';
    //]

    //[visit Visiting variant
    // Applying function to whatever value type it holds
    std::visit([](auto x) { std::cout << x << '\n'; }, v);
    //]

    //[index Checking current alternative index
    switch (v.index()) {
    case 0:
        std::cout << "This is a double\n";
        break;
    case 1:
        std::cout << "This is a char\n";
        break;
    case 2:
        std::cout << "This is a string\n";
        break;
    }
    //]

    //[check_type Checking current alternative type
    if (std::holds_alternative<double>(v)) {
        std::cout << "This is a double\n";
    } else if (std::holds_alternative<char>(v)) {
        std::cout << "This is a char\n";
    } else if (std::holds_alternative<std::string>(v)) {
        std::cout << "This is a string\n";
    }
    //]

    return 0;
}
