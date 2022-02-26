//
// mime_types.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "mime_types.hpp"

namespace http::server::mime_types {

    //[mappings Map MIME types
    constexpr struct mapping {
        const char *extension;
        const char *mime_type;
    } mappings[] = {{"gif", "image/gif"},
                    {"htm", "text/html"},
                    {"html", "text/html"},
                    {"jpg", "image/jpeg"},
                    {"png", "image/png"}};
    //]

    //[extension_to_type Convert file extension to type
    std::string extension_to_type(const std::string &extension) {
        for (mapping m : mappings) {
            if (m.extension == extension) {
                return m.mime_type;
            }
        }

        return "text/plain";
    }
    //]

} // namespace http::server::mime_types
