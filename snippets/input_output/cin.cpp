#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int age{60};
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age >= 18) {
        std::cout << "Welcome!\n";
    } else {
        std::cout << "Sorry.\n";
        return 1;
    }

    return 0;
}
