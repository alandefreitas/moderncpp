#include <iostream>
#include <string_view>

#if defined(__has_include) && __has_include("<source_location>")
//[headers Headers
#include <source_location>
//]
#else
#include "source_location.h"
#endif

//[function Function that requires source location
void print_msg_with_line(
    std::string_view message,
    const std::source_location &location = std::source_location::current()) {
    std::cout << "info: " << location.file_name() << ':' << location.line()
              << ' ' << message << '\n';
}
//]

int main() {
    //[call Call function with source location
    print_msg_with_line("Hello world!");
    //]
    return 0;
}