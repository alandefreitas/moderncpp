#include <iostream>


int main() {
    using namespace std;

    int age;
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age >= 18) {
        // The "old" way
        printf("Welcome! You are %d years old.", age);
        // The C++ way
        std::cout << "Welcome! You are " << age << " years old." << '\n';
        // The C++ way (flushing output)
        std::cout << "Welcome! You are " << age << " years old." << std::endl;
        // See the format example for another way
        // std::cout << std::format(...);
    } else {
        // The "old" way
        printf("Sorry.");
        // The C++ way
        std::cout << "Sorry." << '\n';
        // The C++ way (flushing output)
        std::cout << "Sorry." << std::endl;
        // See the format example for another way
        // std::cout << std::format(...);
    }
    return 0;
}
