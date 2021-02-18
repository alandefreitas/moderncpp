#include <iostream>


int main() {
    using namespace std;

    double l = 4;
    double area = l * l;
    cout << "Area: " << area << endl;

    double height = 1.90;
    double weight = 90;
    cout << "BMI: " << weight / (height * height) << endl;

    int a = 4;
    int b = 7;
    int fx = (b * b * b + a * b) - 2 * b + a % b;
    cout << "f(x) = " << fx << endl;

    return 0;
}
