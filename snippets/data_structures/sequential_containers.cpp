#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>

template <class CONTAINER>
void print_size(const CONTAINER& c) {
    if (c.empty()) {
        std::cout << "The container is empty" << std::endl;
    } else {
        std::cout << "The container has " << c.size() << " elements" << std::endl;
    }
}

template <class CONTAINER>
std::enable_if_t<!std::is_same_v<CONTAINER,std::array<int,5>>,void>
append(CONTAINER& c, int el) {
    c.push_back(el);
}

template <class CONTAINER>
std::enable_if_t<std::is_same_v<CONTAINER,std::array<int,5>>,void>
append(CONTAINER& c, int el) {
    std::cout << "Cannot increase the array" << std::endl;
}


template <class CONTAINER>
std::enable_if_t<std::is_same_v<CONTAINER,std::vector<int>> || std::is_same_v<CONTAINER,std::array<int,5>>,void>
append_front(CONTAINER& c, int el) {
    std::cout << "Cannot insert in front of vector or array" << std::endl;
}

template <class CONTAINER>
std::enable_if_t<!(std::is_same_v<CONTAINER,std::vector<int>> || std::is_same_v<CONTAINER,std::array<int,5>>),void>
append_front(CONTAINER& c, int el) {
    c.push_front(el);
}

template <class CONTAINER>
std::enable_if_t<std::is_same_v<CONTAINER,std::list<int>>,void>
print_container_with_subscript(const CONTAINER& c) {
    std::cout << "Cannot iterate list with subscripts" << std::endl;
}

template <class CONTAINER>
std::enable_if_t<!std::is_same_v<CONTAINER,std::list<int>>,void>
print_container_with_subscript(const CONTAINER& c) {
    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

template <class CONTAINER>
void print_container(const CONTAINER& c) {
    typename CONTAINER::const_iterator i;
    for (i = c.begin(); i != c.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int,5> a = {1,2,3,4,5};
    std::vector<int> v(8,9);
    std::deque<int> d(a.begin(),a.end());
    std::list<int> l;

    std::cout << "Print sizes:" << std::endl;
    print_size(a);
    print_size(v);
    print_size(d);
    print_size(l);

    std::cout << "Push back:" << std::endl;
    append(a,6);
    append(v,6);
    append(d,6);
    append(l,6);

    std::cout << "Print sizes" << std::endl;
    print_size(a);
    print_size(v);
    print_size(d);
    print_size(l);

    std::cout << "Push front" << std::endl;
    append_front(a,6);
    append_front(v,6);
    append_front(d,6);
    append_front(l,6);

    std::cout << "Subscrits" << std::endl;
    print_container_with_subscript(a);
    print_container_with_subscript(v);
    print_container_with_subscript(d);
    print_container_with_subscript(l);

    std::cout << "Iterators" << std::endl;
    print_container(a);
    print_container(v);
    print_container(d);
    print_container(l);

}