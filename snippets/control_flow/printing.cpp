#include <iostream>

using namespace std;

int main() {
    int age;
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age >= 18) {
        printf("Welcome! You are %d years old.", age);
    } else {
        std::cout << "Sorry.\n";
    }
    return 0;
}
