add_executable(searching searching.cpp)
add_executable(sorting sorting.cpp)
add_executable(algorithms algorithms.cpp)

# Download ranges for C++17
# Ranges are in C++20: https://en.cppreference.com/w/cpp/ranges
CPMAddPackage(NAME range-v3 URL https://github.com/ericniebler/range-v3/archive/0.11.0.zip VERSION 0.11.0 DOWNLOAD_ONLY TRUE)
add_library(range-v3 INTERFACE IMPORTED)
target_include_directories(range-v3 INTERFACE "${range-v3_SOURCE_DIR}/include")
add_executable(ranges ranges.cpp)
target_link_libraries(ranges PUBLIC range-v3)
