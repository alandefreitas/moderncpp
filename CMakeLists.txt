#######################################################
### Modern C++ / Snippets and examples              ###
#######################################################
# Project information
cmake_minimum_required(VERSION 3.14)
project(moderncpp
        VERSION 1.0.0
        DESCRIPTION "Modern C++ Snippets"
        HOMEPAGE_URL "https://alandefreitas.github.io/moderncpp/"
        )
set(CMAKE_CXX_STANDARD 20)

#######################################################
### CMake Functions                                 ###
#######################################################
# Put ./cmake directory in our include paths
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# Include our custom cmake functions
include(cmake/functions.cmake)
# Include FetchContent scripts
include(FetchContent)

#######################################################
### Options                                         ###
#######################################################
set_debug_booleans()
set_master_project_booleans()
set_optimization_flags()

# What to build
option(BUILD_SNIPPETS "Build snippets" ON)
option(BUILD_EXAMPLES "Build examples" ON)
# How to build
option(BUILD_WITH_PEDANTIC_WARNINGS "Use pedantic warnings." ${DEBUG_MODE})
option(BUILD_WITH_SANITIZERS "Use pedantic warnings." ${DEBUG_MODE})
option(BUILD_WITH_EXCEPTIONS "Add compiler flags to use exceptions." ON)

# Apply options
if (BUILD_WITH_PEDANTIC_WARNINGS)
    add_pedantic_warnings()
endif ()

if (BUILD_WITH_SANITIZERS)
    add_sanitizers()
endif ()

if (MSVC AND BUILD_WITH_EXCEPTIONS)
    add_compile_options(/EHsc)
endif ()

# Some external build scripts assume Win/MSVC, MacOS/Clang, Unix/GCC
# This may cause problems, so we skip these examples
set_compiler_booleans()
set(EXPECTED_COMPILER OFF)
if (WIN32 AND MSVC)
    set(EXPECTED_COMPILER ON)
elseif (APPLE AND CLANG)
    set(EXPECTED_COMPILER ON)
elseif (UNIX AND NOT APPLE AND GCC)
    set(EXPECTED_COMPILER ON)
endif ()

# Find package we need for threads
# Some systems don't require this package at all
# but will still give us errors trying to link
# to a target that doesn't exist
find_package(Threads)
if (NOT Threads_FOUND)
    add_library(Threads INTERFACE)
    add_library(Threads::Threads ALIAS Threads)
endif()


#######################################################
### Snippets and examples                           ###
#######################################################
if (BUILD_SNIPPETS)
    message("Configuring snippets")
    add_subdirectory(snippets)
endif ()

if (BUILD_EXAMPLES)
    message("Configuring examples")
    add_subdirectory(examples)
endif ()

#######################################################
### Final messages if everything is OK              ###
#######################################################
message(STATUS "🥳 Project configured successfully")
message(STATUS "❤️ Would you like to show some love by starring the repo?")
message(STATUS "🟡 Visit https://github.com/alandefreitas/moderncpp ⭐️")
message(STATUS "🙏 Thanks! It means a lot to me!")
