#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory_resource.hpp>

int main() {
    using namespace std;

    // Create buffer
    char buffer[64] = {};
    std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
    std::cout << buffer << '\n';

    // Create pool
    feroldi::pmr::monotonic_buffer_resource pool{
            std::data(buffer), std::size(buffer)
    };

    // Create vector
    std::vector<char, feroldi::pmr::polymorphic_allocator<char>> vec{&pool};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vec.push_back(ch);
    }

    std::cout << buffer << '\n';


    return 0;
}