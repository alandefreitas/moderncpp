#include <chrono>
#include <string>
#include <tuple>
#include <vector>

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>

int main() {
    /*
     * About fmt/format:
     * - fmt/format has been accepted into C++20
     * - It has the best of printf and cout
     * - Many compilers don't implement it yet
     * - We still depend on <fmt/format.h>
     */

    using namespace std;
    using namespace fmt;
    using namespace std::literals::chrono_literals;

    // Simple print
    print("Hello, world!\n");

    // Format to string
    string s = format("The answer is {}.\n", 42);
    print(s);

    // Format with order
    s = format("I'd rather be {1} than {0}.\n", "right", "happy");
    print(s);

    // Chrono literals
    print("Default format: {} {}\n", 42s, 100ms);
    print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
    time_t t = time(nullptr);
    print("The date is {:%Y-%m-%d}.", localtime(t));

    // Format ranges
    vector<int> v = {1, 2, 3};
    print("{}\n", v);

    tuple<char, int, float> t2{'a', 1, 2.0f};
    print("{}", t2);

    // Color support
    print(fg(color::crimson) | emphasis::bold, "Hello, {}!\n", "world");
    print(fg(color::floral_white) | bg(color::slate_gray) | emphasis::underline,
          "Hello, {}!\n", "мир");
    print(fg(color::steel_blue) | emphasis::italic, "Hello, {}!\n", "世界");

    // Format to memory
    memory_buffer out;
    format_to(out, "For a moment, {} happened.", "nothing");
    print(out.data());
}
