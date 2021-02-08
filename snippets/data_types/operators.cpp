#include <cmath>
#include <iostream>

using namespace std;

int main() {
    // Operators
    int number_1 = 8;
    int number_2 = 3;
    std::cout << number_1 << " + " << number_2 << ": " << number_1 + number_2
              << std::endl;
    std::cout << number_1 << " - " << number_2 << ": " << number_1 - number_2
              << std::endl;
    std::cout << number_1 << " * " << number_2 << ": " << number_1 * number_2
              << std::endl;
    std::cout << number_1 << " / " << number_2 << ": " << number_1 / number_2
              << std::endl;
    std::cout << number_1 << " % " << number_2 << ": " << number_1 % number_2
              << std::endl;

    double number_3 = 8.;
    double number_4 = 3.;
    std::cout << number_3 << " + " << number_4 << ": " << number_3 + number_4
              << std::endl;
    std::cout << number_3 << " - " << number_4 << ": " << number_3 - number_4
              << std::endl;
    std::cout << number_3 << " * " << number_4 << ": " << number_3 * number_4
              << std::endl;
    std::cout << number_3 << " / " << number_4 << ": " << number_3 / number_4
              << std::endl;
    std::cout << "fmod(" << number_3 << ", " << number_4
              << "): " << fmod(number_3, number_4) << std::endl;

    // Attribution operator
    number_1 += number_2; // number_1 = number_1 + number_2;
    std::cout << "number_1 after += is " << number_1 << std::endl;
    number_1 -= number_2;
    std::cout << "number_1 after -= is " << number_1 << std::endl;
    number_1 *= number_2;
    std::cout << "number_1 after *= is " << number_1 << std::endl;
    number_1 /= number_2;
    std::cout << "number_1 after /= is " << number_1 << std::endl;
    number_1 %= number_2;
    std::cout << "number_1 after %= is " << number_1 << std::endl;

    // Postfixed increment/decrement
    number_1++; // or number_1 += 1; // or number_1 = number_1 + 1;
    std::cout << "number_1 after ++ is " << number_1 << std::endl;
    number_1--;
    std::cout << "number_1 after -- is " << number_1 << std::endl;

    // Prefixed increment/decrement
    ++number_1; // or number_1 += 1; // or number_1 = number_1 + 1;
    std::cout << "number_1 after ++ is " << number_1 << std::endl;
    --number_1;
    std::cout << "number_1 after -- is " << number_1 << std::endl;

    // Inside an expression
    std::cout << "number_1: " << number_1++ << std::endl;
    std::cout << "number_1: " << ++number_1 << std::endl;

    return 0;
}
