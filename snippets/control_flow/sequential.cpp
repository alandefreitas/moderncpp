#include <iostream>


int main() {


    //[values Store and output values
    double l = 4;
    double area = l * l;
    std::cout << "Area: " << area << '\n';
    //]

    //[values Store and output expressions
    double height = 1.90;
    double weight = 90;
    std::cout << "BMI: " << weight / (height * height) << '\n';
    //]

    //[values Calculate and output expressions
    int a = 4;
    int b = 7;
    int fx = (b * b * b + a * b) - 2 * b + a % b;
    std::cout << "f(x) = " << fx << '\n';
    //]

    return 0;
}
