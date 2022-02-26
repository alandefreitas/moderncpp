#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>


int main() {
    //[alloc Pointer to an int on the heap
    int *x = new int(5);
    //]

    //[print Print pointer address
    std::cout << "x: " << x << '\n';
    //]

    //[print_value Print pointed value if any
    if (x) {
        std::cout << "*x: " << *x << '\n';
    } else {
        std::cout << "*x: empty" << '\n';
    }
    //]

    //[delete Delete value pointed
    // - Forgetting to delete causes memory leaks
    // - Forgetting to update to nullptr might lead to segmentation faults
    // - Use smart pointers to delete the data automatically
    delete x;
    x = nullptr;
    //]

    //[arrays_raw Raw dynamic arrays
    // - This is what existed before vectors
    // - Point to a sequence of values
    // - Always use vectors instead of this
    // - If you need to access the raw data, use vector::data()
    int *x2 = new int[10];
    for (int i2 = 0; i2 < 10; ++i2) {
        x2[i2] = 10 + i2 * 10;
    }
    //]

    //[print_dyn Print addresses
    std::cout << "x2: " << x2 << '\n';
    std::cout << "&x2[0]: " << &x2[0] << '\n';
    std::cout << "x2[0]: " << x2[0] << '\n';
    //]

    //[print_first Points to the first number in the sequence
    std::cout << "*x2: " << *x2 << '\n';
    std::cout << "x2[3]: " << x2[3] << '\n';
    std::cout << "*(x2+3): " << *(x2 + 3) << '\n';
    //]

    //[deallocate Deallocate sequence
    // - Slightly different command: more danger
    delete[] x2;
    x2 = nullptr;
    //]

    return 0;
}
