FetchContent_Declare(tabulate GIT_REPOSITORY https://github.com/p-ranav/tabulate.git GIT_TAG v1.4)
FetchContent_MakeAvailable(tabulate)
add_executable(recursive_bench recursive_bench.cpp)
target_link_libraries(recursive_bench PRIVATE tabulate)