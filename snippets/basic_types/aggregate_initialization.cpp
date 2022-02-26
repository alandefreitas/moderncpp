#include <iomanip>
#include <iostream>

int main() {


    //[aggregate_type_a An aggregate type
    struct A {
        int x;
        int y;
        int z;
    };
    //]

    auto print_a = [](const A &a) {
        std::cout << "a: {" << a.x << ", " << a.y << ", " << a.z << "}"
                  << std::endl;
    };

    //[init Initialize type with designated initializers
    A a{.x = 1, .y = 4, .z = 2};
    //]
    print_a(a);

    A b{.x = 1, .y = 2, .z = 6};
    print_a(b);

    //[list List initialization
    A c{1, 2, 3};
    //]
    print_a(c);

    //[nested Nested type
    struct B {
        int x;
        A y;
        int z;
    };
    //]

    auto print_b =
        [](const B &a) {
            std::cout << "a: {" << a.x << ", {" << a.y.x << ", " << a.y.y
                      << ", " << a.y.z << "}, " << a.z << "}" << std::endl;
        };

    //[nested_init Nested initialization
    B d{.x = 1, .y = {2, 6, 5}, .z = 3};
    //]
    print_b(d);

    return 0;
}
