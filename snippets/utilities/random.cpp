#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

int main() {
    // Operating system number generator
    random_device rd;

    // Low-cost generator
    default_random_engine g(rd());

    // Create a distribution
    uniform_real_distribution<double> distribution(1.0,10.0);

    // Using the machine with that distribution
    cout <<  distribution(g) << endl;

    // Creating a mersenne twister machine (instead of default_random_engine) with a seed from rd (expensive)
    mt19937 g2{rd()};
    // Creating a normal distribution (very cheap)
    normal_distribution<double> d2(0.0,1.0);
    // Using the machine with that distribution
    cout << d2(g2) << endl;

    // Generating a histogram
    vector<int> hist(10,0);
    for (int i = 0; i < 300; ++i) {
        int bin = d2(g2) + hist.size()/2;
        if (bin >= 0 && bin < hist.size()){
            ++hist[bin];
        }
    }
    for (int i = 0; i < hist.size(); ++i) {
        cout << '-';
        for (int j = 0; j < hist[i]; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}