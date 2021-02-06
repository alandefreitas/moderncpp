#ifndef BCC702_WAREHOUSE_H
#define BCC702_WAREHOUSE_H

#include <map>
#include "product.h"

class warehouse {
public:
    /// Create warehouse
    warehouse();

    /// Destroy warehouse
    virtual ~warehouse();

    /// Interface
    void interface();

private:
    int show_menu();

    void add_product();

    void find_by_name();

    void find_by_code();

    void remove_product();

    void list_products();

    void save_products(const std::string &filename);

    void load_products(const std::string &filename);

private:
    std::map<int, product> products_;
};


#endif //BCC702_WAREHOUSE_H
