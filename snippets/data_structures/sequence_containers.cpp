//[headers Headers
#include <array>
#include <deque>
#include <list>
#include <vector>
//]
#include <iostream>

int main() {
    //[construct Construct sequence containers
    std::array<int, 5> a = {1, 2, 3, 4, 5}; // from values
    std::vector<int> v(8, 9); // from size and value
    std::deque<int> d(a.begin(), a.end()); // from iterators
    std::list<int> l; // empty
    //]

    //[print_size Container size
    std::cout << "a.size(): " << a.size() << '\n';
    std::cout << "v.size(): " << v.size() << '\n';
    std::cout << "d.size(): " << d.size() << '\n';
    std::cout << "l.size(): " << l.size() << '\n';
    //]

    //[push_back Push back / Append
    // a.push_back(6); <- not possible - array is fixed size
    v.push_back(6);
    d.push_back(6);
    l.push_back(6);
    //]

    std::cout << "a.size(): " << a.size() << '\n';
    std::cout << "v.size(): " << v.size() << '\n';
    std::cout << "d.size(): " << d.size() << '\n';
    std::cout << "l.size(): " << l.size() << '\n';

    //[push_front Push front
    // a.push_front(6); <- not possible - array is fixed size
    v.insert(v.begin(), 6); // <- not possible in constant time
    d.push_front(6);
    l.push_front(6);
    //]

    //[subscripts Subscripts
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';

    for (size_t i = 0; i < d.size(); ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << '\n';

    // Impossible: list is not random access
    //    for (size_t i = 0; i < l.size(); ++i) {
    //        std::cout << l[i] << " ";
    //    }
    //    std::cout << '\n';
    //]

    //[iter Iterators
    for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = d.begin(); it != d.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    //]

    //[range_loop Range-based for loop
    for (int x: a) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    for (int x: v) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    for (int x: d) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    for (int x: l) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    //]
}