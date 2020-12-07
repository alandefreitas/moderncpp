#include <iomanip>
#include <iostream>

using namespace std;

struct A {
    int x;
    int y;
    int z;
};

struct B {
    int x;
    A y;
    int z;
};

void print(const A &a) {
    std::cout << "a: {" << a.x << ", " << a.y << ", " << a.z << "}"
              << std::endl;
}

void print(const B &a) {
    std::cout << "a: {" << a.x << ", {" << a.y.x << ", " << a.y.y << ", "
              << a.y.z << "}, " << a.z << "}" << std::endl;
}

int main() {
    // Designated initializers
    A a{.x = 1, .z = 2};
    print(a);

    A b{.x = 1, .y = 2};
    print(b);

    // List initialization
    A c{1, 2, 3};
    print(c);

    // Nested initialization
    B d{.x = 1, .y = {2, 6, 5}, .z = 3};
    print(d);

    return 0;
}
