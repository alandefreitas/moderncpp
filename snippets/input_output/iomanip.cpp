#include <iostream>
#include <iomanip>

int main() {


    double f = 3.14159;
    std::cout << "std::setprecision(2): " << std::setprecision(2) << f << '\n';
    std::cout << "std::setprecision(5): " << std::setprecision(5) << f << '\n';
    std::cout << "std::setprecision(9): " << std::setprecision(9) << f << '\n';
    std::cout << std::fixed;
    std::cout << "std::setprecision(5): " << std::setprecision(5) << f << '\n';
    std::cout << "std::setprecision(9): " << std::setprecision(9) << f << '\n';
    return 0;
}
