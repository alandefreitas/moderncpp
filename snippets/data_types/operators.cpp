#include <cmath>
#include <iostream>

int main() {


    //[operators Operators
    int n1 = 8;
    int n2 = 3;
    std::cout << n1 << " + " << n2 << ": " << n1 + n2 << '\n';
    std::cout << n1 << " - " << n2 << ": " << n1 - n2 << '\n';
    std::cout << n1 << " * " << n2 << ": " << n1 * n2 << '\n';
    std::cout << n1 << " / " << n2 << ": " << n1 / n2 << '\n';
    std::cout << n1 << " % " << n2 << ": " << n1 % n2 << '\n';
    //]

    //[float Operators for floating point types
    double n3 = 8.;
    double n4 = 3.;
    std::cout << n3 << " + " << n4 << ": " << n3 + n4 << '\n';
    std::cout << n3 << " - " << n4 << ": " << n3 - n4 << '\n';
    std::cout << n3 << " * " << n4 << ": " << n3 * n4 << '\n';
    std::cout << n3 << " / " << n4 << ": " << n3 / n4 << '\n';
    //]

    //[fmod There is no % for floating point types
    std::cout << "fmod(" << n3 << ", " << n4 << "): " << fmod(n3, n4) << '\n';
    // This won't work: std::cout << n3 << " % " << n4 << ": " << n3 % n4 << '\n';
    //]

    //[assign Attribution operator
    n1 += n2; // n1 = n1 + n2;
    std::cout << "n1 after += is " << n1 << '\n';
    n1 -= n2;
    std::cout << "n1 after -= is " << n1 << '\n';
    n1 *= n2;
    std::cout << "n1 after *= is " << n1 << '\n';
    n1 /= n2;
    std::cout << "n1 after /= is " << n1 << '\n';
    n1 %= n2;
    std::cout << "n1 after %= is " << n1 << '\n';
    //]

    //[postfix Postfixed increment/decrement
    n1++; // or n1 += 1; // or n1 = n1 + 1;
    std::cout << "n1 after ++ is " << n1 << '\n';
    n1--;
    std::cout << "n1 after -- is " << n1 << '\n';
    //]

    //[prefix Prefixed increment
    // same as n1 += 1; // or n1 = n1 + 1;
    ++n1;
    std::cout << "n1 after ++ is " << n1 << '\n';
    //]

    //[predecrement Prefixed decrement
    // same as n1 -= 1; // or n1 = n1 - 1;
    --n1;
    std::cout << "n1 after -- is " << n1 << '\n';
    //]

    //[postexpr Postfixed inside an expression: use and increment
    std::cout << "n1: " << n1++ << '\n';
    //]

    //[preexpr Prefixed inside an expression: increment and use
    std::cout << "n1: " << ++n1 << '\n';
    //]

    return 0;
}
