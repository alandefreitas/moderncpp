#include <iostream>
#include <vector>
#include <iterator>
//[headers Headers
#include <memory_resource>
//]

int main() {
    //[buffer Construct a buffer where to allocate memory
    char buffer[64] = {}; // a small buffer on the stack
    std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
    std::cout << buffer << '\n';
    //]

    //[pool Create a memory resource with the buffer
    std::pmr::monotonic_buffer_resource pool{std::data(buffer),
                                             std::size(buffer)};
    //]

    //[pmr_vector Create a vector that allocates memory from the pool
    std::pmr::vector<char> vec{&pool};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vec.push_back(ch);
    }
    std::cout << buffer << '\n';
    //]

    //[pool2 Create a pool for memory allocations and a vector using the pool
    std::pmr::unsynchronized_pool_resource pool2;
    std::pmr::vector<char> vec2{&pool2};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vec2.push_back(ch);
    }
    //]
    std::copy(vec2.begin(), vec2.end(),
              std::ostream_iterator<char>(std::cout, " "));
}