#include <asio.hpp>
#include <future>
#include <iostream>

int main() {
    // Timers are useful to applications that need to perform
    // some operations once every x time units, including timeouts
    // for servers
    asio::io_context io_context;

    // Sync timer
    std::cout << "Setting sync timer" << std::endl;
    asio::steady_timer t(io_context, std::chrono::seconds(3));
    t.wait();
    std::cout << "Sync Timer expired" << std::endl;

    // Async Steady timer
    asio::steady_timer t1(io_context, std::chrono::seconds(3));
    std::cout << "Setting timers" << std::endl;
    t1.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 1 expired" << std::endl;
        } else {
            std::cout << "Timer 1 error" << std::endl;
        }
    });

    // Async System timer
    asio::system_timer t2(io_context, std::chrono::seconds(3));
    t2.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 2 expired" << std::endl;
        } else {
            std::cout << "Timer 2 error" << std::endl;
        }
    });

    // Async High-resolution timer
    asio::high_resolution_timer t3(io_context, std::chrono::seconds(3));
    t3.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 3 expired" << std::endl;
        } else {
            std::cout << "Timer 3 error" << std::endl;
        }
    });

    asio::thread_pool pool;
    for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
        asio::post(pool, [&] { io_context.run(); });
    }
}
