#include <iostream>

int main() {


    int age;
    std::cout << "How old are you? ";
    std::cin >> age;
    if (age < 18) {
        //[printf printf
        printf("Sorry.");
        //]
        //[cout std::cout
        std::cout << "Sorry." << '\n';
        //]
        //[cout_flush Flushing std::cout
        std::cout << "Sorry." << std::endl;
        //]
    } else {
        //[printf_param printf with parameters
        printf("Welcome! You are %d years old.", age);
        //]
        //[cout_param std::cout with parameters
        std::cout << "Welcome! You are " << age << " years old." << '\n';
        //]
        //[cout_param_flush Flushing std::cout with parameters
        std::cout << "Welcome! You are " << age << " years old." << std::endl;
        //]
        // See the format example for another way
        // std::cout << std::format(...);
    }
    return 0;
}
