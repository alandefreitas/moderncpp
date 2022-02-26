#include <iostream>
#include <cstddef>
//[headers Headers
#include <bitset>
//]


int main() {
    //[sizeof Get type size
    std::cout << "sizeof(char) = " << sizeof(char) << " bytes" << '\n';
    std::cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << " bytes"
         << '\n';
    std::cout << "sizeof(short) = " << sizeof(short) << " bytes" << '\n';
    std::cout << "sizeof(int) = " << sizeof(int) << " bytes" << '\n';
    std::cout << "sizeof(long) = " << sizeof(long) << " bytes" << '\n';
    std::cout << "sizeof(size_t) = " << sizeof(size_t) << " bytes" << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << " bytes" << '\n' << '\n';
    //]

    //[bin_literals Binary literals
    uint32_t r = 0b111111110100010001100110;
    std::cout << r << '\n';
    //]

    //[bitset Bitsets
    std::cout << "r = " << std::bitset<32>(r) << '\n' << '\n';
    //]

    //[bitset_operators Operators
    const uint32_t unit = 0x01;
    std::cout << "unit << 0 = " << std::bitset<32>(unit << 0) << '\n';
    std::cout << "~(unit << 0) = " << std::bitset<32>(~(unit << 0)) << '\n';
    std::cout << "r & (~(unit << 0)) = " << std::bitset<32>(r & (~(unit << 0))) << '\n'
         << '\n';

    std::cout << "unit << 1 = " << std::bitset<32>(unit << 1) << '\n';
    std::cout << "~(unit << 1) = " << std::bitset<32>(~(unit << 1)) << '\n';
    std::cout << "r & (~(unit << 1)) = " << std::bitset<32>(r & (~(unit << 1))) << '\n'
         << '\n';

    std::cout << "unit << 2 = " << std::bitset<32>(unit << 2) << '\n';
    std::cout << "~(unit << 2) = " << std::bitset<32>(~(unit << 2)) << '\n';
    std::cout << "r & (~(unit << 2)) = " << std::bitset<32>(r & (~(unit << 2))) << '\n'
         << '\n';

    std::cout << "unit << 3 = " << std::bitset<32>(unit << 3) << '\n';
    std::cout << "~(unit << 3) = " << std::bitset<32>(~(unit << 3)) << '\n';
    std::cout << "r & (~(unit << 3)) = " << std::bitset<32>(r & (~(unit << 3))) << '\n'
         << '\n';

    std::cout << "unit << 4 = " << std::bitset<32>(unit << 4) << '\n';
    std::cout << "~(unit << 4) = " << std::bitset<32>(~(unit << 4)) << '\n';
    std::cout << "r & (~(unit << 4)) = " << std::bitset<32>(r & (~(unit << 4))) << '\n'
         << '\n';

    std::cout << "unit << 5 = " << std::bitset<32>(unit << 5) << '\n';
    std::cout << "~(unit << 5) = " << std::bitset<32>(~(unit << 5)) << '\n';
    std::cout << "r & (~(unit << 5)) = " << std::bitset<32>(r & (~(unit << 5))) << '\n'
         << '\n';

    std::cout << "unit << 6 = " << std::bitset<32>(unit << 6) << '\n';
    std::cout << "~(unit << 6) = " << std::bitset<32>(~(unit << 6)) << '\n';
    std::cout << "r & (~(unit << 6)) = " << std::bitset<32>(r & (~(unit << 6))) << '\n'
         << '\n';

    std::cout << "unit << 7 = " << std::bitset<32>(unit << 7) << '\n';
    std::cout << "~(unit << 7) = " << std::bitset<32>(~(unit << 7)) << '\n';
    std::cout << "r & (~(unit << 7)) = " << std::bitset<32>(r & (~(unit << 7))) << '\n'
         << '\n';

    std::cout << "unit << 8 = " << std::bitset<32>(unit << 8) << '\n';
    std::cout << "~(unit << 8) = " << std::bitset<32>(~(unit << 8)) << '\n';
    std::cout << "r & (~(unit << 8)) = " << std::bitset<32>(r & (~(unit << 8))) << '\n'
         << '\n';
    //]

    //[new_bitset Create bitset with 8 bits
    std::bitset<8> b(20);
    //]

    //[convert Convert bitset
    std::cout << "b: " << b << '\n';
    std::cout << "b: " << b.to_ulong() << '\n';
    std::cout << "b: " << b.to_string() << '\n';
    for (size_t i = 0; i < b.size(); ++i) {
        std::cout << "b[i] : " << b[i] << '\n';
    }
    //]

    //[byte Create byte
    std::byte a{20};
    std::cout << "a: " << std::to_integer<int>(a) << '\n';
    //]

    return 0;
}
