#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
//[headers Headers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//]

template <class CONTAINER> void print_container_size(const CONTAINER &c) {
    if (c.empty()) {
        std::cout << "Empty container" << std::endl;
    } else {
        std::cout << "The container has " << c.size() << " elements"
                  << std::endl;
    }
}

void print_container(const std::set<int> &c) {
    typename std::set<int>::const_iterator i;
    for (i = c.begin(); i != c.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void print_container(const std::map<std::string, double> &c) {
    typename std::map<std::string, double>::const_iterator i;
    for (i = c.begin(); i != c.end(); ++i) {
        std::cout << i->first << ": " << i->second << " ";
    }
    std::cout << std::endl;
}

void print_container(const std::unordered_set<int> &c) {
    typename std::unordered_set<int>::const_iterator i;
    for (i = c.begin(); i != c.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void print_container(const std::unordered_map<std::string, double> &c) {
    typename std::unordered_map<std::string, double>::const_iterator i;
    for (i = c.begin(); i != c.end(); ++i) {
        std::cout << i->first << ": " << i->second << " ";
    }
    std::cout << std::endl;
}

int main() {
    //[construct Construct associative containers
    std::set<int> a = {2, 3, 1, 5, 4};
    std::unordered_set<int> a2 = {1, 2, 3, 4, 5};
    //]

    //[subscript Subscript Operator (Ordered maps)
    std::map<std::string, double> m;
    m["PI"] = 3.14;
    m["ZERO"] = 0.0;
    m["IRPF"] = 0.15;
    //]

    //[subscript Subscript Operator (Unordered maps)
    std::unordered_map<std::string, double> m2;
    m2["PI"] = 3.14;
    m2["ZERO"] = 0.0;
    m2["IRPF"] = 0.15;
    //]

    std::cout << "Print sizes:" << std::endl;
    print_container_size(a);
    print_container_size(a2);
    print_container_size(m);
    print_container_size(m2);

    //[print_size Container size
    std::cout << a.size() << '\n';
    std::cout << a2.size() << '\n';
    std::cout << m.size() << '\n';
    std::cout << m2.size() << '\n';
    //]

    std::cout << "Insertion:" << std::endl;

    //[insert Insert values in sets
    a.insert(8);
    a2.insert(8);
    //]

    //[insert_subscript Insert values in maps with subscript operator
    m["hundred"] = 100.0;
    m2["hundred"] = 100.0;
    //]

    //[insert_subscript Insert values in maps
    m.insert(std::make_pair("thousand", 1000.0));
    m2.insert(std::make_pair("thousand", 1000.0));
    //]

    std::cout << "Print containers" << std::endl;
    print_container(a);
    print_container(a2);
    print_container(m);
    print_container(m2);

    std::cout << "Removal:" << std::endl;
    //[erase Erase elements
    a.erase(2);
    a2.erase(2);
    m.erase("thousand");
    m2.erase("thousand");
    //]

    std::cout << "Print containers" << std::endl;
    print_container(a);
    print_container(a2);
    print_container(m);
    print_container(m2);
}