#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
    // Operating system number generator
    random_device rd;

    // Low-cost generator
    default_random_engine g(rd());

    // Create a distribution
    uniform_real_distribution<double> distribution(1.0, 10.0);

    // Using the machine with that distribution
    cout << distribution(g) << endl;

    // Creating a mersenne twister machine (instead of default_random_engine)
    // with a seed from rd (expensive)
    mt19937 g2{rd()};
    // Creating a normal distribution (very cheap)
    normal_distribution<double> d2(0.0, 1.0);
    // Using the machine with that distribution
    cout << d2(g2) << endl;

    // Generating a histogram
    vector<int> hist(10, 0);
    for (int i = 0; i < 300; ++i) {
        auto bin = d2(g2) + static_cast<double>(hist.size()) / 2;
        if (bin >= 0. && static_cast<size_t>(bin) < hist.size()) {
            ++hist[static_cast<size_t>(bin)];
        }
    }
    for (int n : hist) {
        cout << '-';
        for (int j = 0; j < n; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}