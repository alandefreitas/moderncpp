#include <iostream>

//[max_int Function with int parameters
int max(int n1, int n2) { return (n1 > n2) ? n1 : n2; }
//]

//[max_T Function for any type T
template <class T> T max(T n1, T n2) { return (n1 > n2) ? n1 : n2; }
//]

//[max_t1_t2 Function for any types T1 and T2
template <class T1, class T2> T2 max(T1 n1, T2 n2) {
    return (n1 > n2) ? n1 : n2;
}
//]

void call_max() {
    //[call_max Calling template function for any data type
    std::cout << "max: " << max(3, 9) << '\n';
    std::cout << "max: " << max(3.5, 9.3) << '\n';
    std::cout << "max: " << max(3, 9.3) << '\n';
    //]
}

//[max_erased Type erased max function
// The "old" way: max operating on nullified pointers
void *max(void *n1, void *n2, bool (*comp)(void *, void *)) {
    // `comp` is responsible to internally convert `void*` to the appropriate
    // data type and perform the comparison.
    return (comp(n1, n2)) ? n1 : n2;
}
//]

//[comp_erased Type erased comparison function
// The "old" way: an extra function operating on the nullified pointers
bool comp(void *a, void *b) { return (*(int *)a < *(int *)b); }
//]

void call_max_erased() {
    //[call_max_erased Calling function with type erased parameters
    // In old C++ and C, we need nullify pointers to create generic functions.
    // It's easy to see why this is inconvenient.
    int a = 3;
    int b = 9;
    void *m = max(&a, &b, &comp);
    std::cout << "m: " << *(int *)m << '\n';
    //]
}

//[class Template class
template <class T1, class T2> struct pair {
    T1 first;
    T2 second;
};
//]

int main() {
    call_max();
    call_max_erased();

    //[instance_class Instances of templated objects
    pair<int, double> p{3, 3.3};
    std::cout << "p.first: " << p.first << '\n';
    std::cout << "p.second: " << p.second << '\n';
    //]



    return 0;
}