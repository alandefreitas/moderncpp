#include <array>
#include <iostream>
#include <map>
#include <random>
#include <string>

using namespace std;

int main() {
    // Classic loop
    for (size_t i = 0; i < 10; ++i) {
        cout << i << endl;
    }

    // Changing update statement
    int b = 2;
    int e = 1024;
    for (size_t i = b; i <= e; i *= b) {
        cout << b << endl;
    }

    // While loop
    int option = 0;
    do {
        ++option;
    } while (option < 4);

    // Index based loop
    constexpr int n = 100;
    array<double, n> prices;
    for (int i = 0; i < prices.size(); ++i) {
        prices[i] = 4 + 0.1 * i;
    }

    // Iterator based loop
    for (auto it = prices.begin(); it != prices.end(); ++it) {
        cout << "Item price: " << *it << endl;
    }

    // Range based loop
    double sum = 0.;
    for (const auto &price : prices) {
        sum += price;
    }
    cout << "Average price: " << sum / n << endl;

    // Range based loop with value pairs
    map<int, int> t;
    t[7] = 2;
    t[8] = 4;
    t[4] = 6;
    for (const auto &[key, value] : t) {
        cout << key << ": " << value << endl;
    }

    // Iterating 2-dimensional arrays
    constexpr int n1 = 100;
    constexpr int n2 = 3;
    array<array<double, n2>, n1> grades;

    // Index based loop
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            grades[i][j] = 6. + i * (2. / n1) + j * (2. / n2);
        }
    }

    // Range based loop
    for (const auto &row : grades) {
        double row_sum = 0.0;
        for (const auto &col : row) {
            row_sum += col;
        }
        cout << "Average student grade: " << row_sum / grades.size() << endl;
    }

    // Columns in the external for
    for (int j = 0; j < n2; ++j) {
        double col_sum = 0.0;
        for (int i = 0; i < n1; ++i) {
            col_sum += grades[i][j];
        }
        cout << "Average score on test " << j + 1 << ": " << col_sum / n1
             << endl;
    }

    return 0;
}
