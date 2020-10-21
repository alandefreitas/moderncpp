#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

template <typename derived> class shape {
  public:
    derived clone() { return static_cast<derived>(*this); };
};

class square : public shape<square> {
  public:
    square clone() { return *this; }
};

int main() {
    square a;
    square b = a.clone();
    std::cout << "The square has been cloned as a real square" << std::endl;
    return 0;
}