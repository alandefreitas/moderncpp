cmake_minimum_required(VERSION 3.12)
project(moderncpp)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)

if (${UNIX} AND NOT ${APPLE})
    find_package(Threads)
endif()

add_subdirectory(snippets)
add_subdirectory(examples)