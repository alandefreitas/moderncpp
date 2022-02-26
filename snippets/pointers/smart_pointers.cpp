#include <iostream>
#include <memory>

int main() {
    //[unique Unique pointer with no pointed value
    // Only one unique pointer can point to an address
    std::unique_ptr<int> c;
    if (c) {
        std::cout << "*c : " << *c << '\n';
    } else {
        std::cout << "c is empty" << '\n';
    }
    //]

    //[change Changing value of unique pointer
    // Previous value is deleted if needed
    c = std::make_unique<int>(2);
    if (c) {
        std::cout << "*c : " << *c << '\n';
    } else {
        std::cout << "c is empty" << '\n';
    }
    //]

    //[unique_init Initialize unique pointer with value
    auto c2 = std::make_unique<int>(3);
    //]

    //[swap Swap unique pointers
    // Swapping values is valid
    c.swap(c2);
    // c = c2; <- but copying doesn't work
    //]

    //[move_unique Moving values is valid
    c = std::move(c2);
    if (c) {
        std::cout << "New *c : " << *c << '\n';
    } else {
        std::cout << "c is empty" << '\n';
    }
    //]

    if (c2) {
        std::cout << "New *c2 : " << *c << '\n';
    } else {
        std::cout << "c2 is empty" << '\n';
    }

    //[shared_ptr Create shared pointer
    auto sp = std::make_shared<int>(2);
    if (sp) {
        std::cout << "New *sp : " << *sp << '\n';
    } else {
        std::cout << "sp is empty" << '\n';
    }
    //]

    //[share_ptr Share pointed value
    std::shared_ptr<int> sp2 = sp;
    *sp2 = 3;
    if (sp) {
        std::cout << "New *sp : " << *sp << '\n'; // 3
    } else {
        std::cout << "sp is empty" << '\n';
    }
    if (sp2) {
        std::cout << "New *sp2 : " << *sp << '\n'; // 3
    } else {
        std::cout << "sp2 is empty" << '\n';
    }

    //[count Count number of shared pointers
    // How many pointers are pointing to this number?
    std::cout << "There are " << sp.use_count() << " pointers to " << sp.get()
              << '\n';
    //]

    return 0;
}