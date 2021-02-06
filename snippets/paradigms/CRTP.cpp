#include <iostream>

template <typename derived> class shape {
  public:
    virtual derived clone() { return static_cast<derived>(*this); };
};

class square : public shape<square> {
  public:
    square() = default;
    explicit square(const shape &){};
    // CRTP: Clone can return a square even though it's derived from shape
    square clone() override { return *this; }
};

int main() {
    square a;
    square b = a.clone();

    std::cout << "The square has been cloned as a real square" << std::endl;
    std::cout << "&a: " << &a << std::endl;
    std::cout << "&b: " << &b << std::endl;
    return 0;
}