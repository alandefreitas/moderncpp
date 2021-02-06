#include <bitset>
#include <iostream>

int main() {
    // Basic types
    bool a = true;
    std::cout << "a: " << a << std::endl;
    std::cout << "sizeof(a): " << sizeof(a) << std::endl;

    int b = 25;
    std::cout << "b: " << b << std::endl;
    std::cout << "sizeof(b): " << sizeof(b) << std::endl;

    double c = 1.34;
    std::cout << "c: " << c << std::endl;
    std::cout << "sizeof(c): " << sizeof(c) << std::endl;

    char d = 'g';
    std::cout << "d: " << d << std::endl;
    std::cout << "sizeof(d): " << sizeof(d) << std::endl;

    // Integer precision
    long g = 25;
    std::cout << "g: " << g << std::endl;
    long long h = 8271;
    std::cout << "h: " << h << std::endl;
    unsigned long i = 987312;
    std::cout << "i: " << i << std::endl;
    unsigned long long j = 4398271;
    std::cout << "j: " << j << std::endl;

    // Floating point precision
    float k = 25.54;
    std::cout << "k: " << k << std::endl;
    long double l = 987312.325;
    std::cout << "l: " << l << std::endl;

    // Char
    unsigned char m = 'c';
    std::cout << "m: " << m << std::endl;

    return 0;
}