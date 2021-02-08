#include <cmath>
#include <iostream>

using namespace std;

int main() {
    // User input
    int age;
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age >= 18) {
        std::cout << "Welcome!\n";
    } else {
        std::cout << "Sorry.\n";
        return 1;
    }

    // User input (Handling error)
    std::cout << "How old are you again? ";
    if (!(std::cin >> age)) {
        std::cout << "There is an error in your input\n";
        return 1;
    }
    if (age >= 18) {
        std::cout << "Welcome!\n";
    } else {
        std::cout << "Sorry.\n";
        return 1;
    }

    return 0;
}
