//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "server.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    try {
        // Check command line arguments.
        if (argc != 4) {
            std::cout << "Usage: http_server <address> <port> <doc_root>\n";
            std::cout << "  For IPv4, try: ";
            std::cout << "    receiver 0.0.0.0 80 .\n";
            std::cout << "  For IPv6, try: ";
            std::cout << "    receiver 0::0 80 .\n";
        }

        // Initialise the server
        std::string address = argc > 1 ? argv[1] : "0.0.0.0";
        std::string port = argc > 2 ? argv[2] : "80";
        std::string doc_root = argc > 3 ? argv[3] : ".";
        std::cout << "Server address: http://" << address << ":" << port
                  << '\n';
        http::server::server s(address, port, doc_root);

        // Run the server until stopped.
        s.run();
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
