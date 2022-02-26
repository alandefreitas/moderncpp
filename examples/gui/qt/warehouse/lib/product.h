#ifndef BCC702_PRODUTO_H
#define BCC702_PRODUTO_H

#include <string>
#include <ostream>

class warehouse;
class product {
public:
    /// Create product
    product(int id, double price, const std::string &name);

    /// Create product vazio
    product() = default;

    /// Print product
    void print();
    void set_name(const std::string &name);
    const std::string& get_name();
    void set_price(double price);
    double get_price();
    void set_id(int id);
    int get_id();

    /// Stream
    friend std::ostream &operator<<(std::ostream &os, const product &product1);

    /// Relational
    bool operator<(const product &rhs) const;
    bool operator>(const product &rhs) const;
    bool operator<=(const product &rhs) const;
    bool operator>=(const product &rhs) const;

private:
    int id_;
    double price_;
    std::string name_;
};

#endif //BCC702_PRODUTO_H
