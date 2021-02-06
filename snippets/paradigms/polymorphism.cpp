#include <iostream>
#include <memory>
#include <vector>

class shape {
  public:
    shape() : _side1(0), _side2(0) {}

    explicit shape(double side) : _side1(side), _side2(side) {}

    shape(double side1, double side2) : _side1(side1), _side2(side2) {}

    virtual ~shape() = default;

    virtual double area() { return 0; }

    double _side1;
    double _side2;

    bool operator==(const shape &rhs) const {
        return _side1 == rhs._side1 && _side2 == rhs._side2;
    }

    bool operator!=(const shape &rhs) const { return !(rhs == *this); }
};

class triangle : public shape {
  public:
    using shape::shape;

    ~triangle() override = default;

    double area() override { return this->_side1 * this->_side2 / 2; }
};

class square : public shape {
  public:
    using shape::shape;

    ~square() override = default;

    double area() override { return this->_side1 * this->_side2; }
};

std::vector<shape *> load_shapes_old_cpp() {
    std::vector<shape *> v(30);
    for (size_t i = 0; i < v.size(); ++i) {
        if (i % 2) {
            v[i] = new triangle(static_cast<double>(i + 30));
        } else {
            v[i] = new square(static_cast<double>(i + 30));
        }
    }
    return v;
}

std::vector<std::shared_ptr<shape>> load_shapes_modern_cpp() {
    std::vector<std::shared_ptr<shape>> v(30);
    for (size_t i = 0; i < v.size(); ++i) {
        if (i % 2) {
            v[i] = std::make_shared<triangle>(i + 30);
        } else {
            v[i] = std::make_shared<square>(i + 30);
        }
    }
    return v;
}

int main() {
    // using raw pointers
    // - Don't do that
    shape *rp = new square(42);
    std::vector<shape *> rv = load_shapes_old_cpp();

    for (std::vector<shape *>::iterator i = rv.begin(); i != rv.end(); ++i) {
        if (dynamic_cast<triangle *>(*i)) {
            std::cout << "This is a triangle" << std::endl;
        } else if (dynamic_cast<square *>(*i)) {
            std::cout << "This is a square" << std::endl;
        } else if (dynamic_cast<shape *>(*i)) {
            std::cout << "This is a shape" << std::endl;
        }
        if (*i && **i == *rp) {
            std::cout << "It has the same area as rp: " << (*i)->area()
                      << std::endl;
        }
    }

    /*
    for (std::vector<shape *>::iterator i = rv.begin(); i != rv.end(); ++i) {
        delete *i; // not exception safe
    }
    delete rp;
    */

    // Smart pointers
    std::shared_ptr<shape> p = std::make_shared<square>(42);
    std::vector<std::shared_ptr<shape>> v = load_shapes_modern_cpp();

    for (std::shared_ptr<shape> &item : v) {
        if (dynamic_cast<triangle *>(item.get())) {
            std::cout << "This is a triangle" << std::endl;
        } else if (dynamic_cast<square *>(item.get())) {
            std::cout << "This is a square" << std::endl;
        } else if (dynamic_cast<shape *>(item.get())) {
            std::cout << "This is a shape" << std::endl;
        }
        if (item && *item == *p) {
            std::cout << "It has the same area as p: " << item->area()
                      << std::endl;
        }
    }

    return 0;
}