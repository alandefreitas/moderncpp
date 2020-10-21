# Project information
cmake_minimum_required(VERSION 3.14)
project(moderncpp VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

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
option(BUILD_WITH_PEDANTIC_WARNINGS "Use pedantic warnings. This is useful for developers because many of these warnings will be in continuous integration anyway." OFF)

# Libraries
if (UNIX AND NOT APPLE)
    find_package(Threads)
endif()

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

if (MSVC)
    add_compile_options(/EHsc)
endif()

if (BUILD_SNIPPETS)
    add_subdirectory(snippets)
endif()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()