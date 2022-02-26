#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

//[functor Defining a functor manually
class add {
  public:
    double operator()(double left, double right) { return left + right; }
};
//]

int main() {
    //[functor_call Calling a functor
    // Function objects overload operator() so they act like functions
    double number = add()(2, 3);
    std::cout << number << '\n';
    //]

    //[lambda Keeping inline lambda functions in variables
    // Automatically creates a functor for the function
    auto function = []() { std::cout << "Hello, world! "; };
    //]

    //[lambda_call Calling a lambda
    function();
    //]

    //[lambda_args Lambdas as arguments
    // Sort in increasing order
    std::vector<int> v{4, 3, 1, 2};
    auto comparison = [](int a, int b) { return a < b; };
    std::sort(v.begin(), v.end(), comparison);
    //]

    //[lambda_use Lambdas in function calls
    // Sort in decreasing order
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    // Print each element
    std::for_each(v.begin(), v.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << '\n';
    //]

    //[std_function Store lambda as std::function
    std::function<int(int)> func = [](int i) { return i + 10; };
    std::cout << "func(6): " << func(6) << '\n';
    //]

    //[capture Capturing values in lambda function
    // These values are external to the function parameters
    int x = 10;
    std::function<int(int)> func2 = [x](int i) { return i + x; };
    std::cout << "func2(6): " << func2(6) << '\n';
    //]

    //[auto_params Parameter type deduction
    auto decreasing_comparison = [](auto a, auto b) { return b < a; };
    std::vector<double> v2 = {3.6, 3.2, 7.5, 2.4};
    std::sort(v.begin(), v.end(), decreasing_comparison);
    //]

    //[bind_param Binding parameters to the function
    // Creates new functions from existing functions
    // Create base function my_divide
    auto my_divide = [](double x, double y) { return x / y; };
    std::cout << "my_divide(4,7): " << my_divide(4, 7) << '\n';

    // Make x and y always 10 and 2
    // Function fn_five has no parameters now
    auto fn_five = std::bind(my_divide, 10, 2);
    std::cout << "fn_five(): " << fn_five() << '\n';
    //]

    //[bind_single Bind a single parameter
    // Function has only one parameter now
    auto fn_half =
        std::bind(my_divide, std::placeholders::_1, 2); // returns x/2
    std::cout << "fn_half(10): " << fn_half(10) << '\n';
    //]

    //[bind_return Keep parameters and convert the return type
    auto fn_floor = std::bind<int>(my_divide, std::placeholders::_1,
                                   std::placeholders::_2); // returns int(x/y)
    std::cout << "fn_floor(10,2): " << fn_floor(13, 2) << '\n';
    //]

    //[lambda_sort Sorting with lambdas
    std::vector<int> myvector = {32, 71, 12, 45, 26, 80, 53, 33};
    std::sort(myvector.begin(), myvector.begin() + 4); // uses operator <
    std::sort(myvector.begin() + 4, myvector.end(),
              [](auto x, auto y) { return x > y; }); // use operator >
    //]

    //[lambda_all Checking conditions on all elements
    // Many algorithms hardly make much sense without lambdas
    std::vector<int> foo = {3, 5, 7, 11, 13, 17, 19, 23};
    auto is_odd = [](int i) { return i % 2; };
    if (std::all_of(foo.begin(), foo.end(), is_odd)) {
        std::cout << "All the elements are odd numbers.\n";
    }
    //]

    //[lambda_any Check any of elements
    std::array<int, 7> foo2 = {0, 1, -1, 3, -3, 5, -5};
    if (std::any_of(foo2.begin(), foo2.end(), [](int i) { return i < 0; })) {
        std::cout << "There are negative elements in the range.\n";
    }
    //]

    //[lambda_none Check none of the element
    std::array<int, 8> foo3 = {1, 2, 4, 8, 16, 32, 64, 128};
    if (std::none_of(foo3.begin(), foo3.end(), [](int i) { return i < 0; })) {
        std::cout << "There are no negative elements in the range.\n";
    }
    //]

    //[lambda_find Find if element
    std::vector<int> v3 = {10, 25, 40, 55};
    auto it =
        std::find_if(v3.begin(), v3.end(), [](auto i) { return i % 2 == 1; });
    std::cout << "The first odd value is " << *it << '\n';
    //]

    //[lambda_remove_if Removing if element
    std::vector<int> v4{1, 2, 3, 4, 5, 6, 7};
    auto last = remove_if(v4.begin(), v4.end(), [](int n) { return n < 6; });
    v4.erase(last, v4.end());
    //]

    for_each(v4.begin(), v4.end(),
             [](const double c) { std::cout << c << " "; });
    std::cout << '\n';

    //[lambda_remove_if_oneliner Removing if element
    x = 5;
    v4.erase(remove_if(v4.begin(), v4.end(), [x](int n) { return n < x; }),
             v4.end());
    //]

    std::for_each(v4.begin(), v4.end(),
                  [](const double c) { std::cout << c << " "; });
    std::cout << '\n';

    //[count_if Counting if elements
    std::vector<int> v5(9);
    std::iota(v5.begin(), v5.end(), 1);
    int mycount = std::count_if(v5.begin(), v5.end(),
                                [](int i) { return ((i % 2) == 1); });
    std::cout << "My vector contains " << mycount << " odd values.\n";
    //]

    //[replace_if Replacing if match
    std::vector<int> v6(9);
    std::iota(v6.begin(), v6.end(), 1);
    replace_if(
        v6.begin(), v6.end(), [](int i) { return ((i % 2) == 1); }, 0);
    //]

    std::cout << "v6 contains:";
    for (auto it = v6.begin(); it != v6.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    return 0;
}