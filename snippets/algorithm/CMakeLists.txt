add_executable(algorithms algorithms.cpp)

# Failing on Clang-13:
# associated_types.hpp:270:60: error: too many template arguments for class template '__iterator_traits'
if (NOT CLANG)
    #[ranges CMakeLists.txt
    # Ranges in C++20: https://en.cppreference.com/w/cpp/ranges
    # Use range-v3 for now: https://github.com/ericniebler/range-v3
    find_package(range-v3 QUIET)
    if (NOT range-v3_FOUND)
        FetchContent_Declare(range-v3 URL https://github.com/ericniebler/range-v3/archive/0.11.0.zip)
        FetchContent_GetProperties(range-v3)
        if (NOT range-v3_POPULATED)
            FetchContent_Populate(range-v3)
            add_library(range-v3 INTERFACE IMPORTED)
            target_include_directories(range-v3 INTERFACE "${range-v3_SOURCE_DIR}/include")
        endif ()
    endif()
    add_executable(ranges ranges.cpp)
    target_link_libraries(ranges PUBLIC range-v3)
    #]
endif()

add_executable(searching searching.cpp)

add_executable(sorting sorting.cpp)

