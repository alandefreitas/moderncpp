#include <cmath>
#include <iostream>

using namespace std;

int main() {
    // Operators
    int n1 = 8;
    int n2 = 3;
    std::cout << n1 << " + " << n2 << ": " << n1 + n2 << '\n';
    std::cout << n1 << " - " << n2 << ": " << n1 - n2 << '\n';
    std::cout << n1 << " * " << n2 << ": " << n1 * n2 << '\n';
    std::cout << n1 << " / " << n2 << ": " << n1 / n2 << '\n';
    std::cout << n1 << " % " << n2 << ": " << n1 % n2 << '\n';

    // Operators for floating point types
    double n3 = 8.;
    double n4 = 3.;
    std::cout << n3 << " + " << n4 << ": " << n3 + n4 << '\n';
    std::cout << n3 << " - " << n4 << ": " << n3 - n4 << '\n';
    std::cout << n3 << " * " << n4 << ": " << n3 * n4 << '\n';
    std::cout << n3 << " / " << n4 << ": " << n3 / n4 << '\n';

    // There is no % for floating point types
    std::cout << "fmod(" << n3 << ", " << n4 << "): " << fmod(n3, n4) << '\n';

    // Attribution operator
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

    // Postfixed increment/decrement
    n1++; // or n1 += 1; // or n1 = n1 + 1;
    std::cout << "n1 after ++ is " << n1 << '\n';
    n1--;
    std::cout << "n1 after -- is " << n1 << '\n';

    // Prefixed increment
    // same as n1 += 1; // or n1 = n1 + 1;
    ++n1;
    std::cout << "n1 after ++ is " << n1 << '\n';

    // Prefixed decrement
    // same as n1 -= 1; // or n1 = n1 - 1;
    --n1;
    std::cout << "n1 after -- is " << n1 << '\n';

    // Inside an expression
    // - Postfixed: use and increment
    std::cout << "n1: " << n1++ << '\n';
    // - Prefixed: increment and use
    std::cout << "n1: " << ++n1 << '\n';

    return 0;
}
