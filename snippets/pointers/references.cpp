#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>

int main() {
    using namespace std;

    // References
    // - They solve some problems with raw pointers
    // - Once initialized, a reference cannot be changed
    // - Instead of "pointing" to an address, a reference
    //   only "refers" to a fixed address / variable
    int n = 1;

    // References to n
    int &r1 = n;
    int &r2 = r1;
    int &r3 = n;

    std::cout << "n: " << n << '\n';
    std::cout << "r1: " << r1 << '\n';
    std::cout << "r2: " << r2 << '\n';
    std::cout << "r3: " << r3 << '\n';

    // Reference to array
    int ar[3];
    int(&ra)[3] = ar;

    std::cout << "ar: " << ar << '\n';
    std::cout << "ra: " << ra << '\n';

    // Reference to pointer
    int *p = new int(3);
    int *&ppr = p;

    std::cout << "p: " << p << '\n';
    std::cout << "ppr: " << ppr << '\n';

    // Reference to value pointed by p
    int &prr = *p;
    std::cout << "prr: " << prr << '\n';

    // Deleting p is not the resposibility of ppr or prr
    delete p;

    // ppr and prr are now dangling references

    return 0;
}
