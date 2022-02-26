#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

/// \brief Print the system endianess
/// \note If you're learning C++, don't worry about what this function
///       does. This is here to make a point.
void print_endianess();

/// \brief Get bits with the internal representation of a variable
/// \note If you're learning C++, don't worry about how this function
///       works. This is here to make a point.
/// \note In the near future, we can replace this with std::bit_cast.
/// \tparam T Variable type
/// \param v  Variable
/// \return Bitset with the internal representation of v
template <class T> std::bitset<sizeof(T) * 8> to_bitset(T v);

int main() {
    print_endianess();

    //[bool Basic types: bool
    bool a = true;
    std::cout << "bool a: " << a << std::endl;
    std::cout << "sizeof(a): " << sizeof(a) << " bytes" << std::endl;
    std::cout << to_bitset(a) << std::endl;
    //]
    std::cout << std::endl;

    //[int Basic types: int
    int b = 25;
    std::cout << "int b: " << b << std::endl;
    std::cout << "sizeof(b): " << sizeof(b) << " bytes" << std::endl;
    std::cout << to_bitset(b) << std::endl;
    //]
    std::cout << std::endl;

    //[double Basic types: double
    double c = 1.34;
    std::cout << "double c: " << c << std::endl;
    std::cout << "sizeof(c): " << sizeof(c) << " bytes" << std::endl;
    std::cout << to_bitset(c) << std::endl;
    //]
    std::cout << std::endl;

    //[char Basic types: char
    char d = 'g';
    std::cout << "char d: " << d << std::endl;
    std::cout << "sizeof(d): " << sizeof(d) << " bytes" << std::endl;
    std::cout << to_bitset(d) << std::endl;
    //]
    std::cout << std::endl;

    //[long Integer implicit precision: long
    long g = 25;
    std::cout << "long g: " << g << std::endl;
    std::cout << "sizeof(g): " << sizeof(g) << " bytes" << std::endl;
    std::cout << to_bitset(g) << std::endl;
    //]
    std::cout << std::endl;

    //[longlong Integer implicit precision: long long
    long long h = 8271;
    std::cout << "long long h: " << h << std::endl;
    std::cout << "sizeof(h): " << sizeof(h) << " bytes" << std::endl;
    std::cout << to_bitset(h) << std::endl;
    //]
    std::cout << std::endl;

    //[unsigned_long Unsigned integer - implicit precision: unsigned long
    unsigned long i = 987312;
    std::cout << "unsigned long i: " << i << std::endl;
    std::cout << "sizeof(i): " << sizeof(i) << " bytes" << std::endl;
    std::cout << to_bitset(i) << std::endl;
    //]
    std::cout << std::endl;

    //[unsigned_long_long Unsigned integer - implicit precision: unsigned long long
    unsigned long long j = 4398271;
    std::cout << "unsigned long long j: " << j << std::endl;
    std::cout << "sizeof(j): " << sizeof(j) << " bytes" << std::endl;
    std::cout << to_bitset(j) << std::endl;
    //]
    std::cout << std::endl;

    //[int8_t Integer explicit precision: int8_t
    int8_t k = 25;
    std::cout << "int8_t k: " << k << std::endl;
    std::cout << "sizeof(k): " << sizeof(k) << " bytes" << std::endl;
    std::cout << to_bitset(k) << std::endl;
    //]
    std::cout << std::endl;

    //[int64_t Integer explicit precision: int64_t
    int64_t l = 542;
    std::cout << "int64_t l: " << l << std::endl;
    std::cout << "sizeof(l): " << sizeof(l) << " bytes" << std::endl;
    std::cout << to_bitset(l) << std::endl;
    //]
    std::cout << std::endl;

    //uint8_t Unsigned integer explicit precision: uint8_t
    uint8_t m = 54;
    std::cout << "uint8_t m: " << m << std::endl;
    std::cout << "sizeof(m): " << sizeof(m) << " bytes" << std::endl;
    std::cout << to_bitset(m) << std::endl;
    //]
    std::cout << std::endl;

    //uint64_t Unsigned integer explicit precision: uint64_t
    uint64_t n = 76354346;
    std::cout << "uint64_t n: " << n << std::endl;
    std::cout << "sizeof(n): " << sizeof(n) << " bytes" << std::endl;
    std::cout << to_bitset(n) << std::endl;
    //]
    std::cout << std::endl;

    //[float Floating point precision: float
    float o = 25.54;
    std::cout << "float o: " << o << std::endl;
    std::cout << "sizeof(o): " << sizeof(o) << " bytes" << std::endl;
    std::cout << to_bitset(o) << std::endl;
    //]
    std::cout << std::endl;

    //[long_double Floating point precision: long double
    long double p = 987312.325;
    std::cout << "long double p: " << p << std::endl;
    std::cout << "sizeof(p): " << sizeof(p) << " bytes" << std::endl;
    std::cout << to_bitset(p) << std::endl;
    //]
    std::cout << std::endl;

    //[char Unsigned Char (1 byte)
    unsigned char q = 'c';
    std::cout << "unsigned char m: " << q << std::endl;
    std::cout << "sizeof(q): " << sizeof(q) << " bytes" << std::endl;
    std::cout << to_bitset(q) << std::endl;
    //]
    std::cout << std::endl;

    return 0;
}

void print_endianess() {
    if constexpr (std::endian::native == std::endian::big) {
        std::cout << "big-endian" << '\n';
    } else if constexpr (std::endian::native == std::endian::little) {
        std::cout << "little-endian platform" << '\n';
    } else {
        std::cout << "mixed-endian" << '\n';
    }
}

template <class T> std::bitset<sizeof(T) * 8> to_bitset(T v) {
    auto ptr = reinterpret_cast<unsigned char *>(&v);
    unsigned long long bytes = ptr[0];
    for (size_t i = 1; i < sizeof(v); ++i) {
        bytes <<= 8;
        bytes += ptr[i];
    }
    return std::bitset<sizeof(v) * 8>(bytes);
}