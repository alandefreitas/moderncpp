//
// Created by Alan Freitas on 28/11/18.
//

#include <iostream>
#include <memory>
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <map>
#include <set>

#include "warehouse.h"

warehouse::warehouse() {
    load_products("products.txt");
}

void warehouse::load_products(const std::string& filename) {
    std::ifstream fin(filename);
    if (fin) {
        while (!fin.eof()) {
            product x;
            fin >> x.id_;
            fin >> x.price_;
            fin >> x.name_;
            if (!x.name_.empty()) {
                products_[x.id_] = x;
            }
        }
        fin.close();
    }
}

warehouse::~warehouse() {
    save_products("products.txt");
    std::cout << "Bye..." << std::endl;
}

void warehouse::add_product() {
    // Find max id
    int max_id = 0;
    for (const auto &item : products_) {
        if (item.second.id_ > max_id) {
            max_id = item.second.id_;
        }
    }

    // Create set of recommended codes
    std::set<int> recommended_codes;
    for (int i = 1; i < max_id; ++i) {
        auto pos = products_.find(i);
        if (pos == products_.end()){
            recommended_codes.insert(i);
        }
        if (recommended_codes.size() >= 4) {
            break;
        }
    }
    recommended_codes.insert(max_id+1);

    // Add product
    product x;
    std::cout << "Product name: ";
    std::cin >> x.name_;
    std::cout << "Product price: ";
    std::cin >> x.price_;
    std::cout << "Product code (recommended: ";
    for (auto i = recommended_codes.begin(); i != recommended_codes.end(); ++i) {
        std::cout << *i;
        if (i != --recommended_codes.end()){
            std::cout << ",";
        }
    }
    std::cout << "): ";
    std::cin >> x.id_;

    // Check if code is available
    std::map<int,product>::iterator pos;
    do {
        pos = products_.find(x.id_);
        if (pos != products_.end()) {
            std::cout << "The code is not available" << std::endl;
            std::cout << "Choose another code (recommended = " << max_id + 1 << "): ";
            std::cin >> x.id_;
        }
    } while (pos != products_.end());

    // Guarda o product no map
    products_[x.id_] = x;

    std::cout << "Product added successfully" << std::endl;
    std::cout << products_.size() << " products in the database" << std::endl;

}

void warehouse::find_by_name() {
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

void warehouse::find_by_code() {
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

void warehouse::remove_product() {
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

void warehouse::list_products() {
    for (const auto &item : products_) {
        std::cout << item.second << std::endl;
    }
}

void warehouse::save_products(const std::string& filename) {
    std::ofstream fout(filename);
    for (auto i = products_.begin(); i != products_.end(); ++i) {
        fout << i->second.id_ << " ";
        fout << i->second.price_ << " ";
        fout << i->second.name_;
        if (i != --products_.end()){
            fout << std::endl;
        }
    }
    fout.close();
}