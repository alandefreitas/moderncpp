#include <iostream>
#include <memory>
#include <vector>

//[shape Declare class
class shape {
  public:
    //]
    //[default_construct Default constructor
    shape() : _side1(0), _side2(0) {}
    //]

    //[double Constructor from double
    explicit shape(double side) : _side1(side), _side2(side) {}
    //]

    //[two_double Constructor from two doubles
    shape(double side1, double side2) : _side1(side1), _side2(side2) {}
    //]

    //[destroy Default Destructor
    virtual ~shape() = default;
    //]

    //[function Member function
    virtual double area() { return 0; }
    //]

    //[operators Equality operators to compare shapes
    bool operator==(const shape &rhs) const {
        return _side1 == rhs._side1 && _side2 == rhs._side2;
    }

    bool operator!=(const shape &rhs) const { return !(rhs == *this); }
    //]

    //[private_members Protected members
  protected:
    double _side1;
    double _side2;
    //]
};

//[triangle Triangle Inheritance
class triangle : public shape {
  public:
    // Reuse base class constructors
    using shape::shape;

    // Default destructor
    ~triangle() override = default;

    // Override area member function
    double area() override { return this->_side1 * this->_side2 / 2; }
};
//]

//[square Square Inheritance
class square : public shape {
  public:
    // Reuse base class constructors
    using shape::shape;

    // Default destructor
    ~square() override = default;

    // Override area member function
    double area() override { return this->_side1 * this->_side2; }
};
//]

int main() {
    //[square_shape Store a square as an abstract shape
    std::unique_ptr<shape> p = std::make_unique<square>(42);
    //]

    //[load_shapes Store both triangles and squares as abstract shapes
    std::vector<std::unique_ptr<shape>> v(30);
    for (size_t i = 0; i < v.size(); ++i) {
        if (i % 2) {
            v[i] = std::make_unique<triangle>(i + 30);
        } else {
            v[i] = std::make_unique<square>(i + 30);
        }
    }
    //]

    //[iter_shapes Iterate shape derived objects
    for (std::unique_ptr<shape> &item : v) {
        if (dynamic_cast<triangle *>(item.get())) {
            std::cout << "This shape is a triangle\n";
        } else if (dynamic_cast<square *>(item.get())) {
            std::cout << "This shape is a square\n";
        } else if (dynamic_cast<shape *>(item.get())) {
            std::cout << "This is an abstract shape\n";
        }
        if (item && *item == *p) {
            std::cout << "It has the same area as p: " << item->area() << '\n';
        }
    }
    //]

    return 0;
}