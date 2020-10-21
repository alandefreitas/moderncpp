#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <variant>
#include <vector>

class hello_printer : public std::enable_shared_from_this<hello_printer> {
  public:
    void say_hello() { std::cout << "Hello, World!" << std::endl; }

    static std::shared_ptr<hello_printer> create() {
        return std::make_shared<hello_printer>();
    }
};

class hello_class : public std::shared_ptr<hello_printer> {
  public:
    hello_class()
        : std::shared_ptr<hello_printer>(std::make_shared<hello_printer>()) {}

    hello_class(hello_class &rhs)
        : std::shared_ptr<hello_printer>(rhs->shared_from_this()) {}
};

int main() {
    // y points to a hello_printer
    std::shared_ptr<hello_printer> y = std::make_shared<hello_printer>();
    y->say_hello();
    std::cout << "y.get() = " << y.get() << std::endl;
    std::cout << "&y = " << &y << std::endl;

    // z will also point to the same object as y
    std::shared_ptr<hello_printer> y2 = y->shared_from_this();
    y2->say_hello();
    std::cout << "y2.get() = " << y2.get() << std::endl;
    std::cout << "&y2 = " << &y2 << std::endl;

    // the create function makes it more convenient to create a new pointer to a
    // hello_printer
    auto z = hello_printer::create();
    z->say_hello();
    std::cout << "z.get() = " << z.get() << std::endl;
    std::cout << "&z = " << &z << std::endl;

    // x IS a hello_printer (instead of just pointing to one)
    hello_printer x;
    x.say_hello();
    std::cout << "&x = " << &x << std::endl;

    // We cannot get a shared pointer from x because x is not a pointer. It is
    // an object on the stack.
    try {
        std::shared_ptr<hello_printer> x2 = x.shared_from_this();
        x2->say_hello();
        std::cout << "x2.get() = " << x2.get() << std::endl;
        std::cout << "&x2 = " << &x2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Cannot create a pointer from x: " << e.what()
                  << std::endl;
    }

    // However, we can encapsulate the basic hello_printer into another class
    // This second class object in the stack will look like it's not a pointer
    // But, in fact, it's just an usual pointer to a hello class
    // This is making C++ only work with references without the user knowing
    // about it
    hello_class x2;
    x2->say_hello();
    std::cout << "x2.get() = " << x2.get() << std::endl;
    std::cout << "&x2 = " << &x2 << std::endl;

    // x3 can now be copied from x2 because their are just wrappers from the
    // shared_ptrs the real thing is implemented in hello_printer
    hello_class x3 = x2;
    x3->say_hello();
    std::cout << "x3.get() = " << x3.get() << std::endl;
    std::cout << "&x3 = " << &x3 << std::endl;

    return 0;
}