#include <iostream>
#include <string_view>

#if defined(__has_include) && __has_include("source_location")
# include <source_location>
#endif

#include "source_location.h"

void print_msg_with_line(
        std::string_view message,
        const std::source_location &location = std::source_location::current()) {
    std::cout << "info: " << location.file_name() << ':' << location.line()
              << ' ' << message << '\n';
}

int main() {
    print_msg_with_line("Hello world!");
    return 0;
}