//
// mime_types.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_MIME_TYPES_HPP
#define HTTP_MIME_TYPES_HPP

#include <string>

namespace http::server::mime_types {

    //[extension_to_type Convert a file extension into a MIME type.
    std::string extension_to_type(const std::string &extension);
    //]

} // namespace http::server::mime_types

#endif // HTTP_MIME_TYPES_HPP
