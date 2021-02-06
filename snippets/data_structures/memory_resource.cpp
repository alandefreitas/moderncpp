#include <iostream>
#include <memory_resource>
#include <vector>

int main() {
    char buffer[64] = {}; // a small buffer on the stack
    std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
    std::cout << buffer << '\n';
    std::pmr::monotonic_buffer_resource pool{std::data(buffer),
                                             std::size(buffer)};
    std::pmr::vector<char> vec{&pool};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vec.push_back(ch);
    }
    std::cout << buffer << '\n';

    std::pmr::unsynchronized_pool_resource pool2;
    std::pmr::vector<char> vec2{&pool2};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vec2.push_back(ch);
    }
    std::copy(vec2.begin(), vec2.end(),
              std::ostream_iterator<char>(std::cout, " "));
}