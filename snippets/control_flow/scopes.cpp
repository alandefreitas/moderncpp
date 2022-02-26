#include <iostream>

int main() {
    //[scopes External and internal scopes
    int x = 1;
    std::cout << "External x: " << x << '\n';
    for (int i = 0; i < 2; ++i) {
        int y = 2;
        std::cout << "Internal i: " << i << '\n';
        std::cout << "External x: " << x << '\n';
        std::cout << "Internal y: " << y << '\n';
    }
    std::cout << "External x: " << x << '\n';
    //]

    //[fail Variables outside their scope
    // This won't work:
    // std::cout << "Internal i: " << i << '\n';
    // std::cout << "Internal y: " << y << '\n';
    //]
    return 0;
}