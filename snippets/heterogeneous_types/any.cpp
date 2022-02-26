#include <any>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::cout << std::boolalpha;

    //[any `std::any` is a container for single values of any type
    // Be careful when using it
    std::any a = 1;
    //]

    //[accessing_int Accessing values (int)
    std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
    //]

    //[accessing_double Accessing values (double)
    a = 3.14;
    std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
    //]

    //[accessing_bool Accessing values (bool)
    a = true;
    std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';
    //]

    //[accessing_string Accessing values (string)
    a = std::string("Any string");
    std::cout << a.type().name() << ": " << std::any_cast<std::string>(a) << '\n';
    //]

    //[attempt Attempting to access values
    try {
        std::any v = 1;
        std::cout << std::any_cast<float>(v) << '\n';
    } catch (std::bad_any_cast &e) {
        std::cout << e.what() << '\n';
    }
    //]

    //[check_value Checking if variable is empty
    std::any s2 = 1;
    if (!s2.has_value()) {
        const std::type_info &ti = s2.type();
        std::cout << ti.name() << '\n';
    }
    //]

    //[access_pointer Access pointer to value
    std::any a3 = 1;
    int *i = std::any_cast<int>(&a3);
    std::cout << *i << '\n';
    //]

    return 0;
}