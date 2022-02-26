#include <iostream>
#include <memory>
#include <optional>
#include <vector>

int main() {
    //[hello_printer A shared class that say hello
    class hello_printer : public std::enable_shared_from_this<hello_printer> {
      public:
        // Main class function
        void say_hello() { std::cout << "Hello, World!" << '\n'; }
        //]

        //[factory A factory function to create instances of hello_printer
        static std::shared_ptr<hello_printer> create() {
            return std::shared_ptr<hello_printer>(new hello_printer());
        }

      private:
        // New objects need to be created with the factory
        hello_printer() = default;
    };
    //]

    //[create Create a hello printer
    auto y = hello_printer::create();
    y->say_hello();
    std::cout << "y.get() = " << y.get() << '\n';
    std::cout << "&y = " << &y << '\n';
    //]

    //[share Share the hello printer
    // y2 will also point to the same object as y
    std::shared_ptr<hello_printer> y2 = y->shared_from_this();
    y2->say_hello();
    std::cout << "y2.get() = " << y2.get() << '\n';
    std::cout << "&y2 = " << &y2 << '\n';
    //]

    //[create_z Create an independent hello printer
    auto z = hello_printer::create();
    z->say_hello();
    std::cout << "z.get() = " << z.get() << '\n';
    std::cout << "&z = " << &z << '\n';
    //]

    return 0;
}