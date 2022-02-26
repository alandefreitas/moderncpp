#include "asio.hpp"
#include <ctime>
#include <iostream>
#include <string>

// Create the string to be sent back to the client
std::string make_daytime_string() {
    time_t now = time(nullptr);
    std::string r = ctime(&now);
    std::cout << "Time requested: " << r;
    return r;
}

int main() {
    try {
        //[io_context Create io_context executor
        // Object for network input and output
        // - All networking programs at least one io_context
        // - I/O execution context represents your program's link to the
        //   operating system's I/O services
        asio::io_context io_context;
        //]

        //[acceptor Create acceptor
        // The acceptor listens for connections
        // - Create the simplest server possible
        asio::ip::tcp::endpoint ep(asio::ip::tcp::v4(), 8080);
        asio::ip::tcp::acceptor acceptor(io_context, ep);
        //]

        //[socket Create connection socket
        // For loop listening to connections from client
        // - It will handle one connection at a time
        // - See the async example for more than one connection at a time
        while (true) {
            // Connection socket
            // - Represents the connection to the client
            asio::ip::tcp::socket socket(io_context);
            //]

            //[accept Wait for connection from client
            // - Wait for a connection
            // - Use socket to represent the new connection
            // - Open http://localhost:8080 in your browser
            acceptor.accept(socket);
            //]

            // Create message to be returned
            // - The message is the current time
            std::string message = make_daytime_string();

            //[write Write response to client
            // - Transfer this information to the client with the socket
            std::error_code error;
            asio::write(socket, asio::buffer(message), error);
            //]

            //[error Check for errors
            if (error) {
                std::cout << "Error " << error.value() << ": "
                          << error.message() << std::endl;
            }
        } // while (true)
        //]
    } catch (std::exception &e) {
        // Handle any possible exceptions
        std::cerr << e.what() << '\n';
    }

    return 0;
}
