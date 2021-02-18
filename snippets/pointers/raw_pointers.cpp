#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>


int main() {
    using namespace std;

    // Raw pointers
    // - They might be dangerous
    // - Try to avoid them, with a few exceptions
    // - See the smart pointer snippets

    // Pointer to an int
    int *x = new int(5);
    std::cout << "x: " << x << std::endl;
    if (x) {
        std::cout << "*x: " << *x << std::endl;
    } else {
        std::cout << "*x: empty" << std::endl;
    }

    // Delete x
    // - Forgetting to delete causes memory leaks
    // - Smart pointers delete the data automatically
    delete x;

    // Update to nullptr
    // - Nullptr indicates the pointer is free
    // - It means the pointer points to no one
    // - Forgetting to update to nullptr might lead to segmentation faults
    // - Smart pointers do that automatically
    x = nullptr;

    // Testing pointer again
    std::cout << "x: " << x << std::endl;
    if (x) {
        std::cout << "*x: " << *x << std::endl;
    } else {
        std::cout << "*x: empty" << std::endl;
    }

    // Pointers to dynamic arrays
    // Very dangerous if you forget to deallocate
    int i = 0;
    while (i < 1000000) {
        // Point to a new value
        x = new int(i);

        // Deallocate the value pointed by x
        // - Forget to do that and we'll have a big problem!
        delete x;
        x = nullptr;

        ++i;
    }

    // Another danger: pointer arithmetic
    // We might access invalid addresses
    x = new int(i);
    int *tmp = x;
    for (int i = 0; i < 30; ++i) {
        // Go to new address
        // - But what's in there?
        std::cout << "x++: " << x++ << std::endl;
    }

    // This would cause an error now:
    // delete x;

    // Use tmp, which is fortunately pointing to the address we need to delete
    delete tmp;
    delete x;

    // Raw dynamic arrays
    // - This is what existed before vectors
    // - Point to a sequence of values
    // - Always use vectors instead of this
    // - If you need to access the raw data, use vector::data()
    int *x2 = new int[10];
    for (int i2 = 0; i2 < 10; ++i2) {
        x2[i2] = 10 + i2 * 10;
    }
    std::cout << "x2: " << x2 << std::endl;
    std::cout << "&x2[0]: " << &x2[0] << std::endl;
    std::cout << "x2[0]: " << x2[0] << std::endl;
    // x2 is pointing to the first number in the sequence
    std::cout << "*x2: " << *x2 << std::endl;
    std::cout << "x2[3]: " << x2[3] << std::endl;
    std::cout << "*(x2+3): " << *(x2 + 3) << std::endl;

    // Deallocate sequence
    // - Different command - more danger
    delete[] x2;

    return 0;
}
