#include <bitset>
#include <iostream>
#include <cstdint>

auto get_bits(auto v) {
    return std::bitset<sizeof(v)*8>(*reinterpret_cast<unsigned long long*>(&v));
}

int main() {
    // Basic types
    bool a = true;
    std::cout << "bool a: " << a << std::endl;
    std::cout << "sizeof(a): " << sizeof(a) << " bytes" << std::endl;
    std::cout << get_bits(a) << std::endl;
    std::cout << std::endl;

    int b = 25;
    std::cout << "int b: " << b << std::endl;
    std::cout << "sizeof(b): " << sizeof(b) << " bytes" << std::endl;
    std::cout << get_bits(b) << std::endl;
    std::cout << std::endl;

    double c = 1.34;
    std::cout << "double c: " << c << std::endl;
    std::cout << "sizeof(c): " << sizeof(c) << " bytes" << std::endl;
    std::cout << get_bits(c) << std::endl;
    std::cout << std::endl;

    char d = 'g';
    std::cout << "char d: " << d << std::endl;
    std::cout << "sizeof(d): " << sizeof(d) << " bytes" << std::endl;
    std::cout << get_bits(d) << std::endl;
    std::cout << std::endl;

    // Integer implicit precision
    long g = 25;
    std::cout << "long g: " << g << std::endl;
    std::cout << "sizeof(g): " << sizeof(g) << " bytes" << std::endl;
    std::cout << get_bits(g) << std::endl;
    std::cout << std::endl;

    long long h = 8271;
    std::cout << "long long h: " << h << std::endl;
    std::cout << "sizeof(h): " << sizeof(h) << " bytes" << std::endl;
    std::cout << get_bits(h) << std::endl;
    std::cout << std::endl;

    // Unsigned integer - implicit precision
    unsigned long i = 987312;
    std::cout << "unsigned long i: " << i << std::endl;
    std::cout << "sizeof(i): " << sizeof(i) << " bytes" << std::endl;
    std::cout << get_bits(i) << std::endl;
    std::cout << std::endl;

    unsigned long long j = 4398271;
    std::cout << "unsigned long long j: " << j << std::endl;
    std::cout << "sizeof(j): " << sizeof(j) << " bytes" << std::endl;
    std::cout << get_bits(j) << std::endl;
    std::cout << std::endl;

    // Integer explicit precision
    int8_t k = 25;
    std::cout << "int8_t k: " << k << std::endl;
    std::cout << "sizeof(k): " << sizeof(k) << " bytes" << std::endl;
    std::cout << get_bits(k) << std::endl;
    std::cout << std::endl;

    int64_t l = 542;
    std::cout << "int64_t l: " << l << std::endl;
    std::cout << "sizeof(l): " << sizeof(l) << " bytes" << std::endl;
    std::cout << get_bits(l) << std::endl;
    std::cout << std::endl;

    // Unsigned integer explicit precision
    uint8_t m = 54;
    std::cout << "uint8_t m: " << m << std::endl;
    std::cout << "sizeof(m): " << sizeof(m) << " bytes" << std::endl;
    std::cout << get_bits(m) << std::endl;
    std::cout << std::endl;

    uint64_t n = 76354346;
    std::cout << "uint64_t n: " << n << std::endl;
    std::cout << "sizeof(n): " << sizeof(n) << " bytes" << std::endl;
    std::cout << get_bits(n) << std::endl;
    std::cout << std::endl;

    // Floating point precision
    float o = 25.54;
    std::cout << "float o: " << o << std::endl;
    std::cout << "sizeof(o): " << sizeof(o) << " bytes" << std::endl;
    std::cout << get_bits(o) << std::endl;
    std::cout << std::endl;

    long double p = 987312.325;
    std::cout << "long double p: " << p << std::endl;
    std::cout << "sizeof(p): " << sizeof(p) << " bytes" << std::endl;
    std::cout << get_bits(p) << std::endl;
    std::cout << std::endl;

    // Char
    unsigned char q = 'c';
    std::cout << "unsigned char m: " << q << std::endl;
    std::cout << "sizeof(q): " << sizeof(q) << " bytes" << std::endl;
    std::cout << get_bits(q) << std::endl;
    std::cout << std::endl;

    return 0;
}