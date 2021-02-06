# This is just an example of how an HTTP server could be implemented with asio
# For proper HTTP servers, it's more recommendable to use a library for that
add_executable(http_server
        connection.cpp
        connection.hpp
        connection_manager.cpp
        connection_manager.hpp
        header.hpp
        main.cpp
        mime_types.cpp
        mime_types.hpp
        reply.cpp
        reply.hpp
        request.hpp
        request_handler.cpp
        request_handler.hpp
        request_parser.cpp
        request_parser.hpp
        server.cpp
        server.hpp)
target_link_libraries(http_server asio)
