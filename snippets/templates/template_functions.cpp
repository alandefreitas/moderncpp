#include <iostream>

// max for int
int max(int n1, int n2) { return (n1 > n2) ? n1 : n2; }

// max for any type T
template <class T> T max(T n1, T n2) { return (n1 > n2) ? n1 : n2; }

// max for any types T and T2
template <class T, class T2> T2 max(T n1, T2 n2) { return (n1 > n2) ? n1 : n2; }

// The "old" way: max operating on nullified pointers
void *max(void *n1, void *n2, bool (*comp)(void *, void *)) {
    return (comp(n1, n2)) ? n1 : n2;
}

// The "old" way: an extra function operating on the nullified pointers
bool comp(void *a, void *b) { return (*(int *)a < *(int *)b); }

template <class T1, class T2> struct pair {
    T1 first;
    T2 second;
};

int main() {
    // Templates for any data type
    std::cout << "m: " << max(3, 9) << std::endl;
    std::cout << "m: " << max(3.5, 9.3) << std::endl;
    std::cout << "m: " << max(3, 9.3) << std::endl;

    // Objects with templates
    pair<int, double> p{3, 3.3};
    std::cout << "p.first: " << p.first << std::endl;
    std::cout << "p.second: " << p.second << std::endl;

    // In old C++ and C, we need nullify pointers to create generic functions
    // - It's easy to see why this is inconvenient
    int a = 3;
    int b = 9;
    void *m = max(&a, &b, &comp);
    std::cout << "m: " << *(int *)m << std::endl;

    return 0;
}