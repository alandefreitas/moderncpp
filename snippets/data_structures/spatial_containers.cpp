#include <iostream>
//[headers Headers
#include <pareto/spatial_map.h>
//]

int main() {
    //[construct Construct map
    // Unlike a map<map<...>>, which represents a disjunction of indexes,
    // a spatial map represents a conjunction of indexes.
    pareto::spatial_map<double, 2, unsigned> m;
    //]

    //[insert Inserting
    m(-2.5, -1.5) = 17;
    m(-2.1, -0.5) = 32;
    m(-1.6, 0.9) = 36;
    m(-0.6, 0.9) = 13;
    m(-0.5, 0.8) = 32;
    //]

    //[query Querying nearest
    std::cout << "Closest elements to [0, 0]:" << std::endl;
    for (auto it = m.find_nearest({0.,0.}, 2); it != m.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    //]

    //[intersection Querying intersection
    std::cout << "Elements between [-1, -1] and [+1, +1]:" << std::endl;
    for (auto it = m.find_intersection({-1.,-1.}, {+1, +1}); it != m.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    //]
}