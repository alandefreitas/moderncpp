//
// connection.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "connection.hpp"
#include "connection_manager.hpp"
#include "request_handler.hpp"
#include <utility>
#include <vector>

namespace http::server {

    //[connection Construct a connection
    connection::connection(asio::ip::tcp::socket socket,
                           connection_manager &manager,
                           request_handler &handler)
        : socket_(std::move(socket)), connection_manager_(manager),
          request_handler_(handler) {}
    //]

    //[start Start connection by reading
    void connection::start() { schedule_read(); }
    //]

    //[stop Stop connection by closing socket
    void connection::stop() { socket_.close(); }
    //]

    //[schedule_read Schedule read operation
    void connection::schedule_read() {
        auto self(shared_from_this());
        socket_.async_read_some(
            asio::buffer(buffer_),
            [this, self](std::error_code ec, std::size_t bytes_transferred) {
                if (!ec) {
                    // Parse as an HTTP request
                    request_parser::result_type result;
                    std::tie(result, std::ignore) = request_parser_.parse(
                        request_, buffer_.data(),
                        buffer_.data() + bytes_transferred);

                    // Generate reply with the request handler and write it
                    if (result == request_parser::good) {
                        request_handler_.handle_request(request_, reply_);
                        schedule_write();
                    } else if (result == request_parser::bad) {
                        reply_ = reply::stock_reply(reply::bad_request);
                        schedule_write();
                    } else {
                        schedule_read();
                    }
                } else if (ec != asio::error::operation_aborted) {
                    connection_manager_.stop(shared_from_this());
                }
            });
    }
    //]

    //[schedule_write schedule_write operation
    void connection::schedule_write() {
        auto self(shared_from_this());
        asio::async_write(socket_, reply_.to_buffers(),
                          [this, self](std::error_code ec, std::size_t) {
                              if (!ec) {
                                  // Initiate graceful connection closure.
                                  asio::error_code ignored_ec;
                                  socket_.shutdown(
                                      asio::ip::tcp::socket::shutdown_both,
                                      ignored_ec);
                              }

                              if (ec != asio::error::operation_aborted) {
                                  connection_manager_.stop(shared_from_this());
                              }
                          });
    }
    //]

} // namespace http::server
