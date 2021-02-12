#include <iostream>
#include <memory>

int main() {
    using std::cout;

    // Print variable and its address
    int a = 10;
    cout << "a: " << a << '\n';
    cout << "&a (hex): " << &a << '\n';
    cout << "&a: (dec) " << reinterpret_cast<uintptr_t>(&a) << '\n';

    // Create another stack variable
    int b = 10;
    cout << "b: " << b << '\n';
    cout << "&b (hex): " << &b << '\n';
    cout << "&b: (dec) " << reinterpret_cast<uintptr_t>(&b) << '\n';

    // Create a value in the heap
    // - See pointers
    auto c = std::make_unique<int>(10);
    cout << "*c: " << *c << '\n';
    cout << "c (hex): " << c << '\n';
    cout << "c: (dec) " << reinterpret_cast<uintptr_t>(c.get()) << '\n';

    // Distance between two stack variables
    cout << "Distance &b - &a = " << &b - &a << " ints\n";
    cout << "Distance &b - &a = " << reinterpret_cast<unsigned char*>(&b) - reinterpret_cast<unsigned char*>(&a) << " bytes\n";

    // Distance between two stack variables
    cout << "Distance c.get() - &a = " << c.get() - &a << " ints\n";
    cout << "Distance c.get() - &a = " << reinterpret_cast<unsigned char*>(c.get()) - reinterpret_cast<unsigned char*>(&a) << " bytes\n";

    return 0;
}