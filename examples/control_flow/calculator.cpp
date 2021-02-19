#include <iostream>

int main() {
    using namespace std;

    int option;
    double n1, n2, res;
    do {
        cout << "=== Options ===" << endl;
        cout << "[1] Summation" << endl;
        cout << "[2] Subtraction" << endl;
        cout << "[3] Multiply" << endl;
        cout << "[4] Divide" << endl;
        cout << "[0] Quit" << endl;

        cout << "Enter an option: ";
        cin >> option;
        bool valid_range = option >= 0 && option <= 4;
        while (!cin.good() || !valid_range) {
            if (!cin.good()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "!! Enter a NUMERIC option: ";
                cin >> option;
            } else {
                cout << "!! Enter a VALID option: ";
                cin >> option;
            }
            valid_range = option >= 0 && option <= 4;
        }

        if (option != 0) {
            cout << "Enter the first number: ";
            cin >> n1;
            cout << "Enter the second number: ";
            cin >> n2;
            switch (option) {
            case 1:
                res = n1 + n2;
                cout << n1 << " + " << n2 << " = " << res << endl;
                break;
            case 2:
                res = n1 - n2;
                cout << n1 << " - " << n2 << " = " << res << endl;
                break;
            case 3:
                res = n1 * n2;
                cout << n1 << " * " << n2 << " = " << res << endl;
                break;
            case 4:
                res = n1 / n2;
                cout << n1 << " / " << n2 << " = " << res << endl;
                break;
            default:
                cout << "!!! Invalid option !!!" << endl;
                break;
            }
        } else {
            cout << "Thank you. Bye." << endl;
        }
    } while (option != 0);

    return 0;
}