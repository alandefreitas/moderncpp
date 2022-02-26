#include <iostream>
#include <vector>

int main() {
    using std::cout;
    using std::cin;

    // Declare constants and variables
    constexpr int number_of_numbers = 2;
    int first_number;
    int second_number;
    int n_even_numbers = 0;

    // Input
    cout << "Type the first number: ";
    cin >> first_number;
    cout << "Type the second number: ";
    cin >> second_number;

    //[if Simple conditional
    if (first_number % 2 == 0) {
        ++n_even_numbers;
    }
    //]

    //[ternary Ternary Operator
    // same as: n_even_numbers += second_number % 2 == 0;
    n_even_numbers += (first_number % 2 == 0) ? 1 : 0;
    //]

    //[if_else Branches
    if (n_even_numbers == 0) {
        cout << "You typed 0 even numbers and 2 odd numbers\n";
    } else if (n_even_numbers == 1) {
        cout << "You typed 1 even number e 1 odd number\n";
    } else if (n_even_numbers == 2) {
        cout << "You typed 2 even numbers e 0 odd numbers\n";
    } else {
        cout << "There's a serious problem here\n";
        return 1;
    }
    //]

    //[switch Switch on fundamental data types
    switch (n_even_numbers) {
    case 0:
        cout << "Zero even numbers. Two odd numbers.\n";
        break;
    case 1:
        cout << "One even number and one odd number.\n";
        break;
    case 2:
        cout << "Two even numbers. No odd numbers.\n";
        break;
    default:
        cout << "We found a serious error with your program\n";
        return 1;
    }
    //]

    //[no_n_even Common conditional without n_even_numbers
    if (first_number % 2 != 0 && second_number % 2 != 0) {
        cout << "You typed 0 even numbers e 2 odd numbers\n";
    } else if (first_number % 2 == 0 && second_number % 2 == 0) {
        cout << "You typed 2 even numbers e 0 odd numbers\n";
    } else {
        cout << "You typed 1 even number e 1 odd number\n";
    }
    //]

    //[print_direct Printing directly
    cout << "You typed " << n_even_numbers << " even numbers and "
         << number_of_numbers - n_even_numbers << " odd numbers\n";
    //]

    //[plurals Ternary operators for fixing plurals
    cout << "You typed " << n_even_numbers << " even number";
    cout << (n_even_numbers == 1 ? "" : "s");
    cout << " and " << number_of_numbers - n_even_numbers << " odd number";
    cout << (number_of_numbers - n_even_numbers == 1 ? "" : "s");
    //]

    //[if_else_simple Common conditional
    if (n_even_numbers > number_of_numbers - n_even_numbers) {
        cout << "You have more even numbers\n";
    } else {
        cout << "You don't have more even numbers\n";
    }
    //]

    //[ternary_2 Ternary operator
    cout << "You "
         << ((n_even_numbers > number_of_numbers - n_even_numbers) ? ("")
                                                                   : ("don't"));
    cout << " have more even numbers than odd numbers\n";
    //]

    //[if_constexpr Testing constants
    if constexpr (number_of_numbers > 2) {
        cout << "You're program is not adapted to that yet\n";
    } else {
        cout << "Program for testing up to two numbers\n";
    }
    //]

    return 0;
}
