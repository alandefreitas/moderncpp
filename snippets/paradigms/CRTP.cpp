#include <iostream>
#include <unordered_map>
#include <string>
#include <numeric>

template<typename derived>
class shape {
    public:
        derived clone() {
            return static_cast<derived>(*this);
        };
};

class square
        : public shape<square> {
    public:
        square clone() {
            return *this;
        }
};

int main() {
    square a;
    square b = a.clone();
    std::cout << "The square has been cloned as a real square" << std::endl;
    return 0;
}