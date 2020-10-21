#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

int max(int n1, int n2) { return (n1 > n2) ? n1 : n2; }

void *max(void *n1, void *n2, bool (*compar)(void *, void *)) {
    return (compar(n1, n2)) ? n1 : n2;
}

bool compar(void *a, void *b) { return (*(int *)a < *(int *)b); }

template <class T> T max(T n1, T n2) { return (n1 > n2) ? n1 : n2; }

template <class T, class T2> T2 max(T n1, T2 n2) { return (n1 > n2) ? n1 : n2; }

template <class T1, class T2> struct pair {
    T1 first;
    T2 second;
};

int main() {
    // In old C++ and C, we need nullify pointers to create generic functions
    // - It's easy to see why this is inconvenient
    int a = 3;
    int b = 9;
    void *m = max(&a, &b, &compar);
    std::cout << "m: " << *(int *)m << std::endl;

    // Templates for any data type
    std::cout << "m: " << max(3, 9) << std::endl;
    std::cout << "m: " << max(3.5, 9.3) << std::endl;
    std::cout << "m: " << max(3, 9.3) << std::endl;

    // Objects with templates
    pair<int, double> p;
    p.first = 3;
    p.second = 3.3;
    std::cout << "p.first: " << p.first << std::endl;
    std::cout << "p.second: " << p.second << std::endl;

    return 0;
}