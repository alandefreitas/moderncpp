//
// connection_manager.cpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "connection_manager.hpp"

namespace http::server {

    //[connection_manager_connection_manager Default construct
    connection_manager::connection_manager() = default;
    //]

    //[connection_manager_start Start a connection
    void connection_manager::start(connection_ptr c) {
        connections_.insert(c);
        c->start();
    }
    //]

    //[connection_manager_stop Stop a connection
    void connection_manager::stop(connection_ptr c) {
        connections_.erase(c);
        c->stop();
    }
    //]

    //[connection_manager_stop_all Stop all connections
    void connection_manager::stop_all() {
        for (auto c : connections_) {
            c->stop();
        }
        connections_.clear();
    }
    //]

} // namespace http::server
