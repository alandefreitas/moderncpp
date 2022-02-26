#include <array>
#include <iostream>
#include <string>

struct product {
    std::string name;
    double weight;
    double price;
};

int main() {


    product apple;

    apple.name = "Apple X";
    apple.price = 2.4;
    apple.weight = 7.8;

    std::cout << "sizeof(product): " << sizeof(product) << " bytes\n";
    std::cout << "sizeof(double): " << sizeof(double) << " bytes\n";
    std::cout << "sizeof(std::string): " << sizeof(std::string) << " bytes\n";

    std::array<product, 4> ps;
    for (size_t i = 0; i < ps.size(); ++i) {
        ps[i].name = "Apple X";
        ps[i].price = 2.4 + i;
        ps[i].weight = 7.8 + i;
    }

    for (auto &p : ps) {
        std::cout << p.name << std::endl;
        std::cout << p.price << std::endl;
        std::cout << p.weight << std::endl;
    }

    product *cheapest = &ps[0];
    for (size_t i = 1; i < ps.size(); ++i) {
        std::cout << "cheapest->name: " << cheapest->name << '\n';
        std::cout << "(*cheapest).name: " << (*cheapest).name << '\n';
        if (ps[i].price < cheapest->price) {
            cheapest = &ps[i];
        }
    }

    return 0;
}