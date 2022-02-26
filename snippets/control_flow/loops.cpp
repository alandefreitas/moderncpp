#include <array>
#include <iostream>
#include <map>


int main() {
    //[basic Basic loop
    for (int i = 0; i < 10; ++i) {
        std::cout << "Hello world!" << '\n';
    }
    //]

    //[cin_n Changing the number of repetitions
    std::cout << "How many hello worlds? ";
    int z;
    std::cin >> z;
    for (int i = 0; i < z; ++i) {
        std::cout << "Hello world" << '\n';
    }
    //]

    //[siml Similar tasks according to the counter
    for (int i = 0; i < 10; ++i) {
        std::cout << "Hello world " << i << "!\n";
    }
    //]

    //[external Changing external variables
    int total = 0;
    for (int i = 0; i < 10; ++i) {
        total += i;
    }
    std::cout << "0+1+2+3+4+...+9: " << total << '\n';
    //]

    //[loop_if Loop + conditional
    total = 0;
    for (int i = 0; i < 50; ++i) {
        const bool is_multiple_of_three = i % 3 == 0;
        if (is_multiple_of_three) {
            total += i;
        }
    }
    std::cout << "0+3+6+9+12+...+48: " << total << '\n';
    //]

    //[custom_init Changing initialization
    // 5/3 + 7/4 + 9/5 + 11/6 + ...
    float series = 0.;
    for (int i = 3; i < 50; ++i) {
        const auto i_float = static_cast<float>(i);
        series += (i_float * 2 - 1) / i_float;
    }
    std::cout << "5/3+7/4+9/5+...+97/49: " << series << '\n';
    //]

    //[custom_update Changing update statement to +=
    total = 0;
    for (int i = 7; i < 500; i += 7) {
        total += i;
    }
    std::cout << "7+14+21+...+497: " << total << '\n';
    //]

    //[custom_update_2 Changing update statement to *=
    for (int i = 2; i <= 1024; i *= 2) {
        std::cout << i << '\n';
    }
    //]

    //[container Index-based loop for containers with subscript operator[]
    constexpr int n = 100;
    std::array<double, n> prices{};
    for (size_t i = 0; i < prices.size(); ++i) {
        prices[i] = 4.0 + 0.1 * i;
    }
    //]

    //[range_based Range-based loop for containers
    for (double& price : prices) {
        std::cout << "Item price: " << price << '\n';
    }
    //]

    //[range_with_ref Range-based loop with constant references
    double sum = 0.;
    for (const auto &price : prices) {
        sum += price;
    }
    std::cout << "Average price: " << sum / n << '\n';
    //]

    //[map Range-based loop with maps
    std::map<int, int> t;
    t[7] = 2;
    t[8] = 4;
    t[4] = 6;
    for (const auto &p : t) {
        std::cout << p.first << ": " << p.second << '\n';
    }
    //]

    //[pairs Range-based loop with value pairs
    for (const auto &[key, value] : t) {
        std::cout << key << ": " << value << '\n';
    }
    //]

    //[multidim 2D arrays
    constexpr int n1 = 100;
    constexpr int n2 = 3;
    std::array<std::array<double, n2>, n1> grades{};
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            grades[i][j] = 6. + i * (2. / n1) + j * (2. / n2);
        }
    }
    //]

    //[multidim_range 2D range based loop
    for (const auto &row : grades) {
        double row_sum = 0.0;
        for (const auto &col : row) {
            row_sum += col;
        }
        std::cout << "Average student grade: " << row_sum / row.size() << '\n';
    }
    //]

    //[columns_out Columns in the external for
    for (int j = 0; j < n2; ++j) {
        double col_sum = 0.0;
        for (int i = 0; i < n1; ++i) {
            col_sum += grades[i][j];
        }
        std::cout << "Average score on test " << j + 1 << ": " << col_sum / n1
             << '\n';
    }
    //]

    //[while While loop
    int num = 1;
    while (num != 0) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        std::cout << num << "^2 = " << num * num << '\n';
    }
    //]

    //[do_while Do-while loop
    do {
        std::cout << "Enter a number: ";
        std::cin >> num;
        std::cout << num << "^2 = " << num * num << '\n';
    } while (num != 0);
    //]

    return 0;
}
