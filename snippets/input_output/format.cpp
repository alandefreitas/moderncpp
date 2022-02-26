#include <chrono>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

//[headers Headers
#include <fmt/chrono.h>  // time formatters
#include <fmt/color.h>   // color formatters
#include <fmt/format.h>  // main header
#include <fmt/ostream.h> // ostream formatters
#include <fmt/ranges.h>  // range formatters
//]

int main() {
    //[print Simple print
    fmt::print("Hello, world!\n");
    //]

    //[to_string Format to string
    std::cout << fmt::format("The answer is {}.\n", 42);
    //]

    //[ordered Format with order
    std::cout << fmt::format("I'd rather be {1} than {0}.\n", "right", "happy");
    //]

    //[chrono Chrono literals
    using namespace std::literals::chrono_literals;
    fmt::print("Default format: {} {}\n", 42s, 100ms);
    //]

    //[custom_chrono strftime-like format
    fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
    //]

    //[ranges Format ranges
    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);
    //]

    //[tuple Format tuple
    std::tuple<char, int, float> t2{'a', 1, 2.0f};
    fmt::print("{}", t2);
    //]

    //[color Color support
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n",
               "world");
    auto style = fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
                 fmt::emphasis::underline;
    fmt::print(style, "Hello, {}!\n", "мир");
    //]

    //[utf8 UTF-8
    print(fg(fmt::color::steel_blue) | fmt::emphasis::italic, "Hello, {}!\n", "世界");
    //]

    //[memory Format to memory
    std::vector<char> out;
    fmt::format_to(std::back_inserter(out), "For a moment, {} happened.", "nothing");
    fmt::print("{}", out.data());
    //]
}
