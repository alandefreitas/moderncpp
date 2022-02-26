//
// Created by Alan Freitas on 2/7/21.
//

#include <iostream>
#include <product.h>
#include "application.h"

void application::run() {
    int option;
    do {
        option = show_menu();
        if (option > 5 || option < 0) {
            std::cerr << "Invalid option!" << std::endl;
        } else if (option > 0) {
            switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                find_by_name();
                break;
            case 3:
                find_by_code();
                break;
            case 4:
                remove_product();
                break;
            case 5:
                list_products();
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    } while (option != 0);
}

int application::show_menu() {
    std::cout << "************************************" << std::endl;
    std::cout << "[1] Add product" << std::endl;
    std::cout << "[2] Find product by name" << std::endl;
    std::cout << "[3] Find product by code" << std::endl;
    std::cout << "[4] Remove product" << std::endl;
    std::cout << "[5] List products" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "Choose an option:";
    int option;
    std::cin >> option;
    return option;
}

void application::add_product() {
    // Add product
    product x;

    std::string input;
    std::cout << "Product name: ";
    std::cin >> input;
    x.set_name(input);

    auto is_floating_string = [](const std::string& s) {
          if (s.empty()) {
              return false;
          }
          for (const auto &c : s) {
              if (!std::isdigit(c) && c != '.') {
                  return false;
              }
          }
          return false;
    };
    do {
        std::cout << "Product price: ";
        std::cin >> input;
    } while (!is_floating_string(input));
    x.set_price(std::stod(input));

    auto is_integer_string = [](const std::string& s) {
          if (s.empty()) {
              return false;
          }
          for (const auto &c : s) {
              if (!std::isdigit(c)) {
                  return false;
              }
          }
          return false;
    };
    do {
        std::cout << "Product code: ";
        std::cin >> input;
    } while (!is_integer_string(input));
    x.set_id(std::stoi(input));


    std::cout << "Product code (recommended: ";
    for (auto i = recommended_codes.begin(); i != recommended_codes.end(); ++i) {
        std::cout << *i;
        if (i != --recommended_codes.end()){
            std::cout << ",";
        }
    }
    std::cout << "): ";
    std::cin >> x.id_;

    q_.add_product(x);

    std::cout << "Product added successfully" << std::endl;
    std::cout << products_.size() << " products in the database" << std::endl;

}

void application::find_by_name() {
    std::string nome;
    std::cout << "Product name: ";
    std::cin >> nome;

    auto it = find_if(products_.begin(),products_.end(),[&nome](std::pair<const int,product> &a){
      return a.second.name_ == nome;
    });

    if (it != products_.end()){
        std::cout << it->second << std::endl;
    } else {
        std::cout << "Product not found" << std::endl;
    }
}

void application::find_by_code() {
    int id;
    std::cout << "Product code: ";
    std::cin >> id;

    auto pos = products_.find(id);
    if (pos != products_.end()) {
        std::cout << pos->second << std::endl;
    } else {
        std::cout << "Product not found" << std::endl;
    }
}

void application::remove_product() {
    int id;
    std::cout << "Product code: ";
    std::cin >> id;
    auto pos = products_.find(id);
    if (pos != products_.end()) {
        products_.erase(pos);
        std::cout << "Product removed" << std::endl;
    } else {
        std::cout << "Product not found" << std::endl;
    }
}

void application::list_products() {
    for (const auto &item : products_) {
        std::cout << item.second << std::endl;
    }
}
