#include <asio.hpp>
#include <future>
#include <iostream>

int main() {
    // Signals are important to properly stop asynchronous operations
    asio::io_context io_context;

    // Create a signal that sets stop timer to true
    std::atomic<bool> stop_timer = false;
    asio::signal_set signals(io_context, SIGINT, SIGTERM);
    signals.async_wait([&](const asio::error_code &ec, int signal_number) {
        if (!ec) {
            std::cout << "Signal number " << signal_number << std::endl;
            std::cout << "Gracefully stopping the timer and exiting"
                      << std::endl;
            stop_timer.store(true);
        } else {
            std::cout << "Error " << ec.value() << " - " << ec.message()
                      << " - Signal number - " << signal_number << std::endl;
        }
    });

    // Create a timer that keeps counting until we have a signal
    int count = 0;
    asio::steady_timer t(io_context, asio::chrono::seconds(1));
    std::function<void(asio::error_code)> timer_callback;
    timer_callback = [&](asio::error_code ec) {
        if (!ec) {
            if (count < 30 && !stop_timer.load()) {
                std::cout << count << std::endl;
                ++count;
                t.expires_at(t.expiry() + std::chrono::seconds(1));
                t.async_wait(timer_callback);
            } else {
                std::cout << "Reached " << count << std::endl;
            }
        } else {
            std::cout << "Timer Error" << std::endl;
        }
    };
    t.async_wait(timer_callback);

    asio::thread_pool pool;
    for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
        asio::post(pool, [&] { io_context.run(); });
    }
}
