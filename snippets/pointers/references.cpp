#include <array>
#include <iostream>
#include <random>

int main() {
    //[stack References to stack value
    int n = 1;
    int &r1 = n;
    int &r2 = r1;
    int &r3 = n;
    //]

    //[print References as aliases
    std::cout << "n: " << n << '\n';
    std::cout << "r1: " << r1 << '\n';
    std::cout << "r2: " << r2 << '\n';
    std::cout << "r3: " << r3 << '\n';
    //]

    //[ref_array Reference to array
    int ar[3];
    int(&ra)[3] = ar;
    //]

    //[print_array Reference as array alias
    std::cout << "ar: " << ar << '\n';
    std::cout << "ra: " << ra << '\n';
    //]

    //[ptr_reference Reference to pointer
    int *p = new int(3);
    int *&ppr = p;
    //]

    //[print_array Reference as pointer alias
    std::cout << "p: " << p << '\n';
    std::cout << "ppr: " << ppr << '\n';
    //]

    //[ref_ptr_value Reference to value pointed by p
    int &prr = *p;
    std::cout << "prr: " << prr << '\n';
    //]

    //[delete_ptr Deleting pointer is not the responsibility of the reference
    delete p;
    // ppr and prr are now dangling references
    //]

    return 0;
}
