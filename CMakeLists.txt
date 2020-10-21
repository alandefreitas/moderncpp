# Project information
cmake_minimum_required(VERSION 3.14)
project(moderncpp VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)

# To find or download packages
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(cmake/CPM.cmake)
option(CPM_USE_LOCAL_PACKAGES "Try `find_package` before downloading dependencies" ON)

# Options
option(BUILD_SNIPPETS "Build snippets" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# The tray library is not being frequently maintained
# This example is not good for all operating systems
option(BUILD_TRAY "Build tray snippets" OFF)

# Libraries
if (UNIX AND NOT APPLE)
    find_package(Threads)
endif()

if (BUILD_SNIPPETS)
    add_subdirectory(snippets)
endif()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()