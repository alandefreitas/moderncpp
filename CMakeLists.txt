#######################################################
### Modern C++ / Snippets and examples              ###
#######################################################
# Project information
cmake_minimum_required(VERSION 3.14)
project(moderncpp VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
Include(FetchContent)

#######################################################
### Options                                         ###
#######################################################
option(BUILD_SNIPPETS "Build snippets" ON)
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_WITH_PEDANTIC_WARNINGS "Use pedantic warnings." OFF)

# Libraries
if (UNIX AND NOT APPLE)
    find_package(Threads)
endif ()

# Setting compiler options for snippets
# In a more serious project, we would do that per target
if (BUILD_WITH_PEDANTIC_WARNINGS)
    if (MSVC)
        add_compile_options(/W4 /WX)
    else ()
        add_compile_options(-Wall -Wextra -pedantic -Werror)
        if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
            add_compile_options(-Wno-null-pointer-arithmetic -Wno-char-subscripts -Wno-c11-extensions)
        elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            add_compile_options(-Wno-error=class-memaccess -Wno-class-memaccess)
        else ()
            message(ERROR "Cannot disable the relevant warnings for ${CMAKE_CXX_COMPILER_ID}")
        endif ()
    endif ()
endif ()

# Enable exceptions on windows
if (MSVC)
    add_compile_options(/EHsc)
endif ()

# Some external build script wrongly assume Win+MSVC, MacOS+Clang, Unix+GCC
# This may cause problems, so we need to skip these examples
set(EXPECTED_COMPILER OFF)
if (WIN32 AND MSVC)
    set(EXPECTED_COMPILER ON)
endif ()
if (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(EXPECTED_COMPILER ON)
endif ()
if (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
    set(EXPECTED_COMPILER ON)
endif ()

#######################################################
### Snippets and examples                           ###
#######################################################
if (BUILD_SNIPPETS)
    add_subdirectory(snippets)
endif ()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()