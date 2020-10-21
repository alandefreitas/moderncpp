#include "asio.hpp"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// Create the string to be sent back to the client
string make_daytime_string() {
    time_t now = time(0);
    std::cout << "Time: " << now << std::endl;
    return ctime(&now);
}

int main() {
    try {
        // Listen for connections
        // All programs that use asio need to have at least one io_context
        // object
        asio::io_context io_context;
        asio::ip::tcp::acceptor acceptor(
            io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 8080));

        // It will handle one connection at a time
        for (;;) {
            // Represent the connection to the client
            asio::ip::tcp::socket socket(io_context);

            // Wait for a connection
            acceptor.accept(socket);

            // Determine the current time
            string message = make_daytime_string();

            // Transfer this information to the client
            error_code ignored_error;
            asio::write(socket, asio::buffer(message), ignored_error);
        }
    } catch (exception &e) {
        // handle any exceptions
        cerr << e.what() << endl;
    }

    return 0;
}
