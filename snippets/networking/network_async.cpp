#include "asio.hpp"
#include <iostream>
#include <memory>
#include <utility>

// https://think-async.com/Asio/asio-1.16.1/src/examples/cpp11/echo/async_tcp_echo_server.cpp
class session : public std::enable_shared_from_this<session> {
  public:
    // Create a session to a client
    // The session just wraps a socket to communicate with the client
    explicit session(asio::ip::tcp::socket socket)
        : socket_(std::move(socket)) {}

    // Start the session
    void start() { do_read(); }

  private:
    // Read whatever the client sent us
    void do_read() {
        // Create another pointer to this session
        // - These pointers are useful to make sure there is always
        //   some shared pointer pointing to this session object
        auto self(shared_from_this());

        // Read some data from the client
        // - We read little by little to make sure everything is OK
        // - This is better than reading all at once
        // - We read max_length bytes at a time
        // - We can also use a future instead of a callback:
        //   std::future<size_t> r =
        //      socket_.async_read_some(asio::buffer(...), asio::use_future);
        socket_.async_read_some(
            asio::buffer(data_, max_length),
            [this, self](std::error_code ec, std::size_t length) {
                // If there was no error reading the message,
                // write a response to the client
                if (!ec) {
                    std::cout << "Client sent: " << std::endl;
                    std::cout << data_ << std::endl << std::endl;
                    do_write(length);
                }
            });
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    void do_write(std::size_t length) {
        // Create another shared pointer to this to make sure it does die
        auto self(shared_from_this());

        // Write a response asynchronously
        // - In this example, we write the same data back to the client
        asio::async_write(
            socket_, asio::buffer(data_, length),
            [this, self](std::error_code ec, std::size_t /*length*/) {
                // If there is no error
                if (!ec) {
                    std::cout << "Server replied with: " << std::endl;
                    std::cout << data_ << std::endl << std::endl;
                    // Starting reading from the client again
                    do_read();
                }
            });
    }

    // Socket representing connection to client
    asio::ip::tcp::socket socket_;

    // Max length of the messages
    static constexpr size_t max_length = 1024;

    // Array to keep messages
    char data_[max_length]{};
};

// Class to manage the acceptor
class server {
  public:
    // Construct server on a port
    // - The server just wraps the acceptor and starts a session whenever
    //   the client connects
    server(asio::io_context &io_context, short port)
        : acceptor_(io_context,
                    asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)) {
        do_accept();
    }

  private:
    // Listen for connection
    void do_accept() {
        std::cout << "Listening on http://localhost:"
                  << acceptor_.local_endpoint().port() << std::endl;
        // Wait for connection
        // - Wait for a connection
        // - Open http://localhost:8080 in your browser
        acceptor_.async_accept(
            [this](std::error_code ec, asio::ip::tcp::socket socket) {
                // If there is no error, create a socket and reply
                // - The session object wraps the a socket to create response
                // - The session will manage a single connection to a user
                if (!ec) {
                    // Start the session
                    std::make_shared<session>(std::move(socket))->start();
                }

                // Accept another connection
                // - The session will work asynchronously
                // - While the session will start to read the message,
                //   the server already starts listening no another connection.
                do_accept();
            });
    }

  private /* members */:
    // The only member we need is an acceptor for the server
    asio::ip::tcp::acceptor acceptor_;
};

int main() {
    try {
        // Create io_context as usual
        asio::io_context io_context;

        // We put all the logic inside a server object
        // - Nothing forbids us from organizing the server
        //   in any other way.
        server s(io_context, 8080);

        // Run the io_context
        // - The server async functions will queue tasks in the io_context
        // - This function runs the io_context while there's work to do
        // - There is always going to be work to do because the server
        //   is always listening
        asio::thread_pool pool;
        for (unsigned i = 0; i < std::thread::hardware_concurrency(); ++i) {
            asio::post(pool, [&] {
                // We run the io_context from the threads
                // - This allows us the io_context to send work to whatever
                //   thread seems best
                io_context.run();
            });
        }
    } catch (std::exception &e) {
        // Report any exceptions
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}