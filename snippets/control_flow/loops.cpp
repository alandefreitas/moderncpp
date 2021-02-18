#include <array>
#include <iostream>
#include <map>


int main() {
    using namespace std;

    // Basic loop
    for (int i = 0; i < 10; ++i) {
        cout << "Hello world!" << '\n';
    }

    // Changing the number of repetitions
    cout << "How many hello worlds? ";
    int z;
    cin >> z;
    for (int i = 0; i < z; ++i) {
        cout << "Hello world" << '\n';
    }

    // Similar tasks according to the counter
    for (int i = 0; i < 10; ++i) {
        cout << "Hello world " << i << "!\n";
    }

    // Changing external variables
    int total = 0;
    for (int i = 0; i < 10; ++i) {
        total += i;
    }
    cout << "0+1+2+3+4+...+9: " << total << '\n';

    // Loop + conditional
    total = 0;
    for (int i = 0; i < 50; ++i) {
        const bool is_multiple_of_three = i % 3 == 0;
        if (is_multiple_of_three) {
            total += i;
        }
    }
    cout << "0+3+6+9+12+...+48: " << total << '\n';

    // Changing initialization
    // 5/3 + 7/4 + 9/5 + 11/6 + ...
    float series = 0.;
    for (int i = 3.f; i < 50; ++i) {
        const auto i_float = static_cast<float>(i);
        series += (i_float * 2 - 1) / i_float;
    }
    cout << "5/3+7/4+9/5+...+97/49: " << series << '\n';

    // Changing update statement to +=
    total = 0;
    for (int i = 7; i < 500; i += 7) {
        total += i;
    }
    cout << "7+14+21+...+497: " << total << '\n';

    // Changing update statement to *=
    for (int i = 2; i <= 1024; i *= 2) {
        cout << i << '\n';
    }

    // Do-While loop
    int option = 0;
    do {
        ++option;
    } while (option < 4);

    // Index-based loop for containers with subscript operator[]
    constexpr int n = 100;
    array<double, n> prices{};
    for (size_t i = 0; i < prices.size(); ++i) {
        prices[i] = 4 + 0.1 * i;
    }

    // Range-based loop for containers
    for (double& price : prices) {
        cout << "Item price: " << price << '\n';
    }

    // Range-based loop with constant references
    double sum = 0.;
    for (const auto &price : prices) {
        sum += price;
    }
    cout << "Average price: " << sum / n << '\n';

    // Range-based loop with value pairs
    map<int, int> t;
    t[7] = 2;
    t[8] = 4;
    t[4] = 6;
    for (const auto &[key, value] : t) {
        cout << key << ": " << value << '\n';
    }

    // Create multidimensional array
    constexpr int n1 = 100;
    constexpr int n2 = 3;
    array<array<double, n2>, n1> grades{};

    // Iterating 2-dimensional arrays with index-based loops
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
        cout << "Average student grade: " << row_sum / grades.size() << '\n';
    }

    // Columns in the external for
    for (int j = 0; j < n2; ++j) {
        double col_sum = 0.0;
        for (int i = 0; i < n1; ++i) {
            col_sum += grades[i][j];
        }
        cout << "Average score on test " << j + 1 << ": " << col_sum / n1
             << '\n';
    }

    return 0;
}
