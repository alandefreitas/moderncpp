#include <iostream>

//[shape Declare shape class with derived type as template parameter
template <typename derived> class shape {
  public:
    virtual derived clone() { return static_cast<derived>(*this); };
};
//]

//[square Inherits from base and base has derived as a template parameter
class square : public shape<square> {
  public:
    square() = default;
    explicit square(const shape &){};
    // CRTP: Clone can return a square even though it's derived from shape
    square clone() override { return *this; }
};
//]

int main() {
    //[use_fn Use a template dependant function
    square a;
    square b = a.clone();
    //]

    //[print Print addresses
    std::cout << "The square has been cloned as a real square" << '\n';
    std::cout << "&a: " << &a << '\n';
    std::cout << "&b: " << &b << '\n';
    //]

    return 0;
}