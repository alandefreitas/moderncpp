#include <iostream>
#include <array>
#include <memory>
#include <chrono>

using namespace std;

// Constexpr function
constexpr double pi() {
    return 3.14159265358979323846;
}
void show_menu();
double power_three(double x);
double power(double x, int y);
void times_two(int& x);
void maxmin(int a, int b, int c, int& minimum, int& maximum);
pair<int,int> maxmin(int a, int b, int c);
void sort(int a, int b, int c, int& minimum, int& middle, int& maximum);
tuple<int,int,int> sort(int a, int b, int c);
bool has_element(const array<int,1000>& a, int element);
void increment_all(array<int,1000>& a, int increment_value = 1);
void pointer_to_cube(shared_ptr<int> p);
int fibonacci_iterative(int n);
int fibonacci_recursive(int n);

int main() {
    // No return function
    int opt = 3;
    do {
        show_menu();
        --opt;
    } while (opt != 0);

    // One return value
    cout << "π = " << pi() << endl;

    // One parameter
    cout << "4.4^3 = " << power_three(4.4) << endl;

    // Two parameters
    cout << "4.4^5 = " << power(4.4,5) << endl;

    // Parameters by reference
    int x = 5;
    times_two(x);
    cout << "x = " << x << endl;

    // Parameter by reference
    // - Always pass arrays by reference to avoid copying
    array<int,1000> v;
    increment_all(v);
    for (int i = 0; i < v.size() && i < 20; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    increment_all(v,10);
    for (int i = 0; i < v.size() && i < 20; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Parameters by constant reference
    // - We don't want to copy
    // - But we also don't want to change it
    for (int i = 0; i < v.size(); ++i) {
        v[i] = i;
    }
    if (has_element(v,400)) {
        cout << "Array v has the element 400" <<endl;
    } else {
        cout << "Array v doesn't have the element 400" <<endl;
    }

    // "Returning" two values by reference
    int maximum;
    int minimum;
    maxmin(5, 3, 8, minimum, maximum);
    cout << "Minimum and maximum: " << minimum << ", " << maximum << endl;

    // "Returning" three values by reference
    int middle;
    sort(5, 3, 8, minimum, middle, maximum);
    cout << "Sorting 5, 3, 8 = " << minimum << ", " << middle << ", " << maximum << endl;

    // Returning two values with a pair
    pair<int,int> p = maxmin(5,3,8);
    cout << "Minimum and maximum: " << p.first << ", " << p.second << endl;

    // Returning two values with structured binding (for new variables)
    auto [m1,m2] = maxmin(5,3,8);
    cout << "Minimum and maximum: " << m1 << ", " << m2 << endl;

    // Returning two values with tie (for existing variables)
    tie(m1,m2) = maxmin(5,3,8);
    cout << "Minimum and maximum: " << m1 << ", " << m2 << endl;

    // Returning three values with a tuple
    tuple<int,int,int> t = sort(5,3,8);
    cout << "Sorting 5, 3, 8: " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;

    // Returning three values with structured binding (for new variables)
    auto [minimum3, middle3, maximum3] = sort(5,3,8);
    cout << "Sorting 5, 3, 8: " << minimum3 << ", " << middle3 << ", " << maximum3 << endl;

    // Returning three values with tie (for existing variables)
    tie(minimum3, middle3, maximum3) = sort(5,3,8);
    cout << "Sorting 5, 3, 8: " << minimum3 << ", " << middle3 << ", " << maximum3 << endl;

    // Parameter by pointer by value
    shared_ptr<int> ptr = make_shared<int>(5);
    pointer_to_cube(ptr);
    cout << "5^3 = " << *ptr << endl;

    // Recursive functions
    cout << "fibonacci_iterative(6) = " << fibonacci_iterative(6) << endl;
    cout << "fibonacci_recursive(6) = " << fibonacci_recursive(6) << endl;

    // Comparing time
    // - This is a classic case
    // - Iterative algorithms are more efficient
    // - Recursive algorithms are easier to write
    for (int i = 3; i < 60; ++i) {
        auto start = chrono::high_resolution_clock::now();
        cout << "fibonacci_iterative(" << i << ") = " << fibonacci_iterative(i) << " - ";
        auto duration = chrono::duration_cast<chrono::milliseconds>(std::chrono::steady_clock::now()-start);
        cout << duration.count() << " milliseconds" << endl;

        start = chrono::high_resolution_clock::now();
        cout << "fibonacci_recursive(" << i << ") = " << fibonacci_recursive(i) << " - ";
        duration = chrono::duration_cast<chrono::milliseconds>(std::chrono::steady_clock::now()-start);
        cout << duration.count() << " milliseconds" << endl;
    }

    return 0;
}

void show_menu() {
    cout << "Options:\n"
                 "[0] Exit\n"
                 "[1] Sum\n"
                 "[2] Multiply" << endl;
}


double power_three(double x) {
    return x * x * x;
}

double power(double x, int y) {
    double result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

void times_two(int& x) {
    x = 2 * x;
}

void maxmin(int a, int b, int c, int& minimum, int& maximum) {
    if (a > b) {
        minimum = b;
        maximum = a;
    } else {
        minimum = a;
        maximum = b;
    }
    if (c > maximum) {
        maximum = c;
    }
    if (c < minimum) {
        minimum = c;
    }
}

pair<int,int> maxmin(int a, int b, int c) {
    int minimum;
    int maximum;
    if (a > b) {
        minimum = b;
        maximum = a;
    } else {
        minimum = a;
        maximum = b;
    }
    if (c > maximum) {
        maximum = c;
    }
    if (c < minimum) {
        minimum = c;
    }
    return make_pair(minimum,maximum);
}

void sort(int a, int b, int c, int& minimum, int& middle, int& maximum){
    maxmin(a,b,c,minimum,maximum);
    if (a != minimum && a != maximum) {
        middle = a;
        return;
    }
    if (b != minimum && b != maximum) {
        middle = b;
        return;
    }
    middle = c;
}

tuple<int,int,int> sort(int a, int b, int c){
    auto [minimum,maximum] = maxmin(a,b,c);
    if (a != minimum && a != maximum) {
        return make_tuple(minimum,a,maximum);
    }
    if (b != minimum && b != maximum) {
        return make_tuple(minimum,b,maximum);
    }
    return make_tuple(minimum,b,maximum);
}


bool has_element(const array<int,1000>& a, int element) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == element) {
            return true;
        }
    }
    return false;
}

void increment_all(array<int,1000>& a, int increment_value) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] += increment_value;
    }
}

void pointer_to_cube(shared_ptr<int> p) {
    if (p) {
        *p = *p * *p * *p;
    }
}

int fibonacci_iterative(int n) {
    if (n <= 2) {
        return 1;
    }
    int fn;
    int fn_1 = 1;
    int fn_2 = 1;
    for (int i = 3; i <= n; ++i) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}

int fibonacci_recursive(int n) {
    if (n > 2) {
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    } else {
        return 1;
    }
}
