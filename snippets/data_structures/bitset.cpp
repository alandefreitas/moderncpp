#include <bitset>
#include <iostream>

using namespace std;

int main() {
    // Get type size
    cout << "sizeof(char) = " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << " bytes"
         << endl;
    cout << "sizeof(short) = " << sizeof(short) << " bytes" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(long) = " << sizeof(long) << " bytes" << endl;
    cout << "sizeof(size_t) = " << sizeof(size_t) << " bytes" << endl;
    cout << "sizeof(double) = " << sizeof(double) << " bytes" << endl << endl;

    // Binary literals
    uint32_t r = 0b111111110100010001100110;
    cout << r << endl;

    // Bitsets
    cout << "r = " << bitset<32>(r) << endl << endl;

    // Operators
    const uint32_t unit = 0x01;
    cout << "unit << 0 = " << bitset<32>(unit << 0) << endl;
    cout << "~(unit << 0) = " << bitset<32>(~(unit << 0)) << endl;
    cout << "r & (~(unit << 0)) = " << bitset<32>(r & (~(unit << 0))) << endl
         << endl;

    cout << "unit << 1 = " << bitset<32>(unit << 1) << endl;
    cout << "~(unit << 1) = " << bitset<32>(~(unit << 1)) << endl;
    cout << "r & (~(unit << 1)) = " << bitset<32>(r & (~(unit << 1))) << endl
         << endl;

    cout << "unit << 2 = " << bitset<32>(unit << 2) << endl;
    cout << "~(unit << 2) = " << bitset<32>(~(unit << 2)) << endl;
    cout << "r & (~(unit << 2)) = " << bitset<32>(r & (~(unit << 2))) << endl
         << endl;

    cout << "unit << 3 = " << bitset<32>(unit << 3) << endl;
    cout << "~(unit << 3) = " << bitset<32>(~(unit << 3)) << endl;
    cout << "r & (~(unit << 3)) = " << bitset<32>(r & (~(unit << 3))) << endl
         << endl;

    cout << "unit << 4 = " << bitset<32>(unit << 4) << endl;
    cout << "~(unit << 4) = " << bitset<32>(~(unit << 4)) << endl;
    cout << "r & (~(unit << 4)) = " << bitset<32>(r & (~(unit << 4))) << endl
         << endl;

    cout << "unit << 5 = " << bitset<32>(unit << 5) << endl;
    cout << "~(unit << 5) = " << bitset<32>(~(unit << 5)) << endl;
    cout << "r & (~(unit << 5)) = " << bitset<32>(r & (~(unit << 5))) << endl
         << endl;

    cout << "unit << 6 = " << bitset<32>(unit << 6) << endl;
    cout << "~(unit << 6) = " << bitset<32>(~(unit << 6)) << endl;
    cout << "r & (~(unit << 6)) = " << bitset<32>(r & (~(unit << 6))) << endl
         << endl;

    cout << "unit << 7 = " << bitset<32>(unit << 7) << endl;
    cout << "~(unit << 7) = " << bitset<32>(~(unit << 7)) << endl;
    cout << "r & (~(unit << 7)) = " << bitset<32>(r & (~(unit << 7))) << endl
         << endl;

    cout << "unit << 8 = " << bitset<32>(unit << 8) << endl;
    cout << "~(unit << 8) = " << bitset<32>(~(unit << 8)) << endl;
    cout << "r & (~(unit << 8)) = " << bitset<32>(r & (~(unit << 8))) << endl
         << endl;

    std::bitset<8> b(20);
    std::cout << "b: " << b << std::endl;
    std::cout << "b: " << b.to_ulong() << std::endl;
    std::cout << "b: " << b.to_string() << std::endl;
    for (size_t i = 0; i < b.size(); ++i) {
        std::cout << "b[i] : " << b[i] << std::endl;
    }

    std::byte a{20};
    std::cout << "a: " << std::to_integer<int>(a) << std::endl;

    return 0;
}
