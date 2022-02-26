#include <asio.hpp>
#include <future>
#include <iostream>

int main() {
    //[io_context Create io_context executor
    asio::io_context io_context;
    //]

    //[signal_set Create signal_set responding to SIGINT and SIGTERM
    asio::signal_set signals(io_context, SIGINT, SIGTERM);
    //]

    //[signal_cb Set the signal set callback
    // The signals will set stop_timer to true
    std::atomic<bool> request_stop_timer = false;
    signals.async_wait([&](const asio::error_code &ec, int signal_number) {
        if (!ec) {
            std::cout << "Signal number " << signal_number << std::endl;
            std::cout << "Gracefully stopping the timer and exiting"
                      << std::endl;
            request_stop_timer.store(true);
        } else {
            std::cout << "Error " << ec.value() << " - " << ec.message()
                      << " - Signal number - " << signal_number << std::endl;
        }
    });
    //]

    //[timer Create a timer that keeps counting until we have a signal
    asio::steady_timer t(io_context, asio::chrono::seconds(1));
    //]

    //[timer_cb Set timer callback
    int count = 0;
    std::function<void(asio::error_code)> timer_callback;
    timer_callback = [&](asio::error_code ec) {
        if (!ec) {
            if (count < 30 && !request_stop_timer.load()) {
                // Increase counter
                std::cout << count << std::endl;
                ++count;
                // Set the timer again
                t.expires_at(t.expiry() + std::chrono::seconds(1));
                t.async_wait(timer_callback);
            } else {
                std::cout << "Reached " << count << std::endl;
            }
        } else {
            std::cout << "Timer Error" << std::endl;
        }
    };
    //]

    //[timer_wait Push timer waiting task to io_context
    t.async_wait(timer_callback);
    //]

    //[dequeue Execute tasks from io_context
    asio::thread_pool pool;
    for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
        asio::post(pool, [&io_context] { io_context.run(); });
    }
    //]
}
