#include <asio.hpp>
#include <future>
#include <iostream>

int main() {
    //[io_context Create io_context executor
    asio::io_context io_context;
    //]

    // Sync timer
    std::cout << "Setting sync timer" << '\n';
    //[sync_timer Setting a synchronous timer
    asio::steady_timer t(io_context, std::chrono::seconds(3));
    t.wait();
    std::cout << "Sync Timer expired" << '\n';
    //]

    // Async Steady timer

    //[sync_steady_timer Create a steady timer
    asio::steady_timer t1(io_context, std::chrono::seconds(3));
    //]
    std::cout << "Setting timers" << '\n';

    //[async_steady_timer_callback Setting steady timer asynchronous callback
    t1.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 1 expired" << '\n';
        } else {
            std::cout << "Timer 1 error" << '\n';
        }
    });
    //]

    // Async System timer
    //[system_timer Creating a system timer
    asio::system_timer t2(io_context, std::chrono::seconds(3));
    //]

    //[system_timer_call Setting asynchronous steady timer callback
    t2.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 2 expired" << '\n';
        } else {
            std::cout << "Timer 2 error" << '\n';
        }
    });
    //]

    // Async High-resolution timer
    //[high_resolution_timer Creating a high-resolution timer
    asio::high_resolution_timer t3(io_context, std::chrono::seconds(3));
    //]

    //[high_res_timer_call Setting asynchronous high-resolution timer callback
    t3.async_wait([](std::error_code ec) {
        if (!ec) {
            std::cout << "Timer 3 expired" << '\n';
        } else {
            std::cout << "Timer 3 error" << '\n';
        }
    });
    //]

    //[dequeue Dequeue tasks from io_context executor
    asio::thread_pool pool;
    for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
        asio::post(pool, [&io_context] { io_context.run(); });
    }
    //]
}
