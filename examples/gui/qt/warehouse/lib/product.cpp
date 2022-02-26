#include "product.h"
#include <iostream>
#include <iomanip>

void product::print() {
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const product &product1) {
    os << "#" << product1.id_ << " \t" << std::setw(15) << product1.name_ << " \tR$" << product1.price_;
    return os;
}

product::product(int id_, double price_, const std::string &_name_) :
id_(id_), price_(price_), name_(_name_) {}

void product::set_name(const std::string& _name_) {
    product::name_ = _name_;
}

const std::string& product::get_name() {
    return name_;
}

void product::set_price(double price) {
    price_ = price;
}

double product::get_price() {
    return price_;
}

void product::set_id(int id) {
    id_ = id;
}

int product::get_id() {
    return id_;
}

bool product::operator<(const product &rhs) const {
    if (id_ < rhs.id_)
        return true;
    if (rhs.id_ < id_)
        return false;
    if (price_ < rhs.price_)
        return true;
    if (rhs.price_ < price_)
        return false;
    return name_ < rhs.name_;
}

bool product::operator>(const product &rhs) const {
    return rhs < *this;
}

bool product::operator<=(const product &rhs) const {
    return !(rhs < *this);
}

bool product::operator>=(const product &rhs) const {
    return !(*this < rhs);
}
