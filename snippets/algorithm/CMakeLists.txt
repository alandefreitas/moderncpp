add_executable(algorithms algorithms.cpp)

# Ranges in C++20: https://en.cppreference.com/w/cpp/ranges
# Use range-v3 for now: https://github.com/ericniebler/range-v3
FetchContent_Declare(range-v3 URL https://github.com/ericniebler/range-v3/archive/0.11.0.zip)
FetchContent_GetProperties(range-v3)
if (NOT range-v3_POPULATED)
    FetchContent_Populate(range-v3)
    add_library(range-v3 INTERFACE IMPORTED)
    target_include_directories(range-v3 INTERFACE "${range-v3_SOURCE_DIR}/include")
endif ()
add_executable(ranges ranges.cpp)
target_link_libraries(ranges PUBLIC range-v3)

add_executable(searching searching.cpp)

add_executable(sorting sorting.cpp)


