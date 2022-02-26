//
// Created by Alan Freitas on 2/7/21.
//

#include <warehouse.h>

#ifndef MODERNCPP_APPLICATION_H
#define MODERNCPP_APPLICATION_H

class application {
  public:
    void run();
    int show_menu();
    void add_product();
    void find_by_name();
    void find_by_code();
    void remove_product();
    void list_products();

  private:
    warehouse q_;
};


#endif // MODERNCPP_APPLICATION_H
