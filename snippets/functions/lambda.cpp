#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

class add {
  public:
    add(){};

    double operator()(double left, double right) { return left + right; }
};

using namespace std;

int main() {
    // The old way: Functors
    // - Function objects overload operator() to hold functions
    double number = add()(2, 3);
    cout << number << endl;

    // The modern way
    // - Keeping inline lambda functions in variables
    // - This is a good place to use auto
    auto function = []() { cout << "Hello, world! "; };
    function();

    // Using the lambda functions as arguments to other functions
    // Sort in increasing order
    vector<int> v{4, 3, 1, 2};
    auto comparison = [](int a, int b) { return a < b; };
    sort(v.begin(), v.end(), comparison);

    // Using lambda functions directly
    // Sort in decreasing order
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for_each(v.begin(), v.end(), [](const double c) { cout << c << " "; });
    cout << endl;

    // Function type
    std::function<int(int)> func = [](int i) { return i + 10; };
    cout << "func(6): " << func(6) << endl;

    // Capturing values in lambda function
    // - These values are external to the function parameters
    int x = 10;
    std::function<int(int)> func2 = [x](int i) { return i + x; };
    cout << "func2(6): " << func2(6) << endl;

    // Automatic parameters
    auto decreasing_comparison = [](auto a, auto b) { return b < a; };
    vector<double> v2 = {3.6, 3.2, 7.5, 2.4};
    sort(v.begin(), v.end());

    // Binding parameters to the function
    // - Creates new functions from existing functions
    auto my_divide = [](double x, double y) { return x / y; }; // returns x/y
    cout << "my_divide(4,7): " << my_divide(4, 7) << endl;

    // Make x and y always 10 and 2
    // - Function has no parameters now
    auto fn_five = bind(my_divide, 10, 2);
    cout << "fn_five(): " << fn_five() << endl;

    // Make y always 2
    // - Function has only one parameter now
    auto fn_half = bind(my_divide, placeholders::_1, 2); // returns x/2
    cout << "fn_half(10): " << fn_half(10) << endl;

    // Keep parameters but convert the return type
    auto fn_floor = bind<int>(my_divide, placeholders::_1,
                              placeholders::_2); // returns int(x/y)
    cout << "fn_floor(10,2): " << fn_floor(13, 2) << endl;

    // Sorting with lambdas
    vector<int> myvector = {32, 71, 12, 45, 26, 80, 53, 33};
    sort(myvector.begin(), myvector.begin() + 4);
    sort(myvector.begin() + 4, myvector.end(),
         [](auto x, auto y) { return x > y; });

    // Checking condition on all elements
    // - This algorithm (like some others) only makes sense with lambdas
    vector<int> foo = {3, 5, 7, 11, 13, 17, 19, 23};
    if (all_of(foo.begin(), foo.end(), [](int i) { return i % 2; })) {
        cout << "All the elements are odd numbers.\n";
    }

    // Any of
    array<int, 7> foo2 = {0, 1, -1, 3, -3, 5, -5};
    if (any_of(foo2.begin(), foo2.end(), [](int i) { return i < 0; })) {
        cout << "There are negative elements in the range.\n";
    }

    // None of
    array<int, 8> foo3 = {1, 2, 4, 8, 16, 32, 64, 128};
    if (none_of(foo3.begin(), foo3.end(), [](int i) { return i < 0; })) {
        cout << "There are no negative elements in the range.\n";
    }

    // Find if...
    vector<int> v3 = {10, 25, 40, 55};
    auto it = find_if(v3.begin(), v3.end(), [](auto i) { return i % 2 == 1; });
    cout << "The first odd value is " << *it << '\n';

    // Removing if...
    vector<int> v4{1, 2, 3, 4, 5, 6, 7};
    auto last = remove_if(v4.begin(), v4.end(), [](int n) { return n < 6; });
    v4.erase(last, v4.end());
    for_each(v4.begin(), v4.end(), [](const double c) { cout << c << " "; });
    cout << endl;
    x = 5;
    v4.erase(remove_if(v4.begin(), v4.end(), [x](int n) { return n < x; }),
             v4.end());
    for_each(v4.begin(), v4.end(), [](const double c) { cout << c << " "; });
    cout << endl;

    // Counting if...
    vector<int> v5(9);
    iota(v5.begin(), v5.end(), 1);
    int mycount =
        count_if(v5.begin(), v5.end(), [](int i) { return ((i % 2) == 1); });
    cout << "My vector contains " << mycount << " odd values.\n";

    // Replacing if...
    vector<int> v6(9);
    iota(v6.begin(), v6.end(), 1);
    replace_if(
        v6.begin(), v6.end(), [](int i) { return ((i % 2) == 1); }, 0);
    cout << "v6 contains:";
    for (vector<int>::iterator it = v6.begin(); it != v6.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << '\n';

    return 0;
}