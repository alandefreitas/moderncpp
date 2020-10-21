#include <iostream>

using namespace std;

int main() {
    constexpr int number_of_numbers = 2;
    int first_number;
    int second_number;
    int n_even_numbers = 0;

    cout << "Type the first number: ";
    cin >> first_number;
    n_even_numbers += (first_number % 2 == 0) ? 1 : 0;

    cout << "Type the second number: ";
    cin >> second_number;
    n_even_numbers += second_number % 2 == 0;

    // Common conditional
    if (n_even_numbers == 0) {
        cout << "You typed 0 even numbers and 2 odd numbers" << endl;
    } else if (n_even_numbers == 1) {
        cout << "You typed 1 número par e 1 odd number" << endl;
    } else if (n_even_numbers == 2) {
        cout << "You typed 2 even numbers e 0 odd numbers" << endl;
    } else {
        cout << "Tem um erro sério no seu programa" << endl;
        return 1;
    }

    // Switch on fundamental data types
    switch (n_even_numbers) {
    case 0:
        cout << "Zero even numbers. Two odd numbers." << endl;
        break;
    case 1:
        cout << "One even number and one odd number." << endl;
        break;
    case 2:
        cout << "Two even numbers. No odd numbers." << endl;
        break;
    default:
        cout << "Tem um erro sério no seu programa" << endl;
        return 1;
    }

    // Common conditional without n_even_numbers
    if (first_number % 2 != 0 && second_number % 2 != 0) {
        cout << "You typed 0 even numbers e 2 odd numbers" << endl;
    } else if (first_number % 2 == 0 && second_number % 2 == 0) {
        cout << "You typed 2 even numbers e 0 odd numbers" << endl;
    } else {
        cout << "You typed 1 número par e 1 odd number" << endl;
    }

    // Printing directly
    cout << "You typed " << n_even_numbers << " even numbers and "
         << number_of_numbers - n_even_numbers << " odd numbers" << endl;

    // Ternary operators for fixing plurals
    cout << "You typed " << n_even_numbers << " even number";
    cout << (n_even_numbers == 1 ? "" : "s");
    cout << " and " << number_of_numbers - n_even_numbers << " odd number";
    cout << (number_of_numbers - n_even_numbers == 1 ? "" : "s");

    // Common conditional
    if (n_even_numbers > number_of_numbers - n_even_numbers) {
        cout << "You have more even numbers" << endl;
    } else {
        cout << "You don't have more even numbers" << endl;
    }

    // Ternary operator
    cout << "You "
         << ((n_even_numbers > number_of_numbers - n_even_numbers) ? ("")
                                                                   : ("don't"));
    cout << " have more even numbers than odd numbers" << endl;

    // Testing constants
    if constexpr (number_of_numbers > 2) {
        cout << "You're program is not adapted to that yet" << endl;
    } else {
        cout << "Program for testing up to two numbers" << endl;
    }

    return 0;
}
