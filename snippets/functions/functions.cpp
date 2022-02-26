#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>

//[no_return_decl Function declaration
void show_menu();
//]

//[no_return_def Function definition
void show_menu() {
    std::cout << "Options:\n"
                 "[0] Exit\n"
                 "[1] Sum\n"
                 "[2] Multiply\n";
}
//]

void call_show_menu() {
    //[no_return_call Calling Function
    // Call function 3 times
    for (int i = 0; i < 3; ++i) {
        show_menu();
    }
    //]
}

//[constexpr Declare and define constexpr function - return value `double`
constexpr double pi() { return 3.14159265358979323846; }
//]

// One return value
void call_pi() {
    //[constexpr_call Call constexpr function
    std::cout << "π = " << pi() << '\n';
    //]
}

//[one_param Declare and define function with one parameter
double power_three(double x) { return x * x * x; }
//]

void call_power_three() {
    //[one_param_call Call function with one parameter
    std::cout << "4.4^3 = " << power_three(4.4) << '\n';
    //]
}

//[two_param Function with two parameters
double power(double x, int y) {
    double result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}
//]

void call_power() {
    //[two_param_call Call function with two parameters
    std::cout << "4.4^5 = " << power(4.4, 5) << '\n';
    //]
}

//[ref_param Function with parameters by reference - No return
void times_two(int &x) { x *= 2; }
//]

void call_times_two() {
    //[ref_param_call Call function with parameters by reference
    int x = 5;
    times_two(x);
    std::cout << "x = " << x << '\n'; // 10
    //]
}

//[ref_param_default Parameters by reference and default parameter
// Always pass arrays by reference to avoid copying
void increment_all(std::array<int, 1000> &a, int increment_value = 1) {
    for (int &x : a) {
        x += increment_value;
    }
}
//]

void call_increment_all() {
    //[ref_param_default_call Call function with parameter by reference
    std::array<int, 1000> v{};
    increment_all(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    //]

    //[ref_param_no_default_call Call function without default parameter
    increment_all(v, 10);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    //]
}

//[const_ref_function Parameters by const reference
// Parameters by constant reference
// - We don't want to copy
// - But we also don't want to change it
bool has_element(const std::array<int, 1000> &a, int element) {
    for (int x : a) {
        if (x == element) {
            return true;
        }
    }
    return false;
}
//]

void call_has_element() {
    //[const_ref_function_call Call function with parameters by const reference
    std::array<int, 1000> v{};
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i;
    }
    if (has_element(v, 400)) {
        std::cout << "Array v has the element 400" << '\n';
    } else {
        std::cout << "Array v doesn't have the element 400" << '\n';
    }
    //]
}

//[ref_return "Return" two values by reference
void minmax(int a, int b, int c, int &minimum, int &maximum) {
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
    // values of external variables are set
}
//]

void call_minmax_ref() {
    //[ref_return_call "Returning" two values by reference
    int maximum;
    int minimum;
    minmax(5, 3, 8, minimum, maximum);
    std::cout << "Minimum and maximum: " << minimum << ", " << maximum << '\n';
    //]
}

//[pair_return Return two values with a pair
std::pair<int, int> minmax(int a, int b, int c) {
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
    return std::make_pair(minimum, maximum);
}
//]

void call_minmax_pair() {
    //[pair_return_call Returning two values with a pair
    std::pair<int, int> p = minmax(5, 3, 8);
    std::cout << "Minimum and maximum: " << p.first << ", " << p.second << '\n';
    //]

    //[pair_return_bind Returning two values with structured binding
    auto [m1, m2] = minmax(5, 3, 8);
    std::cout << "Minimum and maximum: " << m1 << ", " << m2 << '\n';
    //]

    //[pair_return_tie Returning two values with tie
    std::tie(m1, m2) = minmax(5, 3, 8);
    std::cout << "Minimum and maximum: " << m1 << ", " << m2 << '\n';
    //]
}

//[ref_3_return "Return" three values by reference
void sort(int a, int b, int c, int &minimum, int &middle, int &maximum) {
    minmax(a, b, c, minimum, maximum);
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
//]

void call_sort() {
    //[ref_3_return_call "Returning" three values by reference
    int minimum;
    int middle;
    int maximum;
    sort(5, 3, 8, minimum, middle, maximum);
    std::cout << "Sorting 5, 3, 8 = " << minimum << ", " << middle << ", "
              << maximum << '\n';
    //]
}

//[ret_tuple Return three values with a tuple
std::tuple<int, int, int> sort(int a, int b, int c) {
    auto [minimum, maximum] = minmax(a, b, c);
    if (a != minimum && a != maximum) {
        return std::make_tuple(minimum, a, maximum);
    }
    if (b != minimum && b != maximum) {
        return std::make_tuple(minimum, b, maximum);
    }
    return std::make_tuple(minimum, b, maximum);
}
//]

void call_sort_tuple() {
    //[ret_tuple_call Returning three values with a tuple
    std::tuple<int, int, int> t = sort(5, 3, 8);
    std::cout << "Sorting 5, 3, 8: " << get<0>(t) << ", " << get<1>(t) << ", "
              << get<2>(t) << '\n';
    //]

    //[ret_tuple_bind Returning three values with structured binding
    auto [minimum3, middle3, maximum3] = sort(5, 3, 8);
    std::cout << "Sorting 5, 3, 8: " << minimum3 << ", " << middle3 << ", "
              << maximum3 << '\n';
    //]

    //[ret_tuple_tie Returning three values with tie
    std::tie(minimum3, middle3, maximum3) = sort(5, 3, 8);
    std::cout << "Sorting 5, 3, 8: " << minimum3 << ", " << middle3 << ", "
              << maximum3 << '\n';
    //]
}

//[pointer_param Parameter by pointer by value
// Pass pointers by value: https://youtu.be/xGDLkt-jBJ4?t=869
// As small as the reference and no other level of indirection
void pointer_to_cube(std::shared_ptr<int> p) {
    if (p) {
        *p = *p * *p * *p;
    }
}
//]

void call_pointer_to_cube() {
    //[pointer_param_call Parameter by pointer by value
    std::shared_ptr<int> ptr = std::make_shared<int>(5);
    pointer_to_cube(ptr);
    std::cout << "5^3 = " << *ptr << '\n';
    //]
}

//[iter_fib Iterative Fibonacci function
int fibonacci_iterative(int n) {
    if (n == 0) {
        return 0;
    } else if (n <= 2) {
        return 1;
    }
    int fib;
    int fib_previous = 1;
    int fib_previous_2 = 1;
    for (int i = 3; i <= n; ++i) {
        fib = fib_previous + fib_previous_2;
        fib_previous_2 = fib_previous;
        fib_previous = fib;
    }
    return fib;
}
//]

//[recursive_fib Recursive Fibonacci function
int fibonacci_recursive(int n) {
    if (n > 2) {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    } else {
        return n == 0 ? 0 : 1;
    }
}
//]

void call_fibonacci() {
    //[fib_call Iterative and Recursive functions
    std::cout << "fibonacci_iterative(6) = " << fibonacci_iterative(6) << '\n';
    std::cout << "fibonacci_recursive(6) = " << fibonacci_recursive(6) << '\n';
    //]
}

int main() {


    call_show_menu();
    call_pi();
    call_power_three();
    call_power();
    call_times_two();
    call_increment_all();
    call_has_element();
    call_minmax_ref();
    call_minmax_pair();
    call_sort();
    call_sort_tuple();
    call_pointer_to_cube();


    return 0;
}



