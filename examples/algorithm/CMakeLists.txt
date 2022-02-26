find_package(Matplot++ QUIET)
if (Matplot++_FOUND)
    add_executable(algorithm_example algorithm.cpp)
    target_link_libraries(algorithm_example PRIVATE Matplot++::matplot)

    add_executable(searching_benchmark searching.cpp)
    target_link_libraries(searching_benchmark PRIVATE Matplot++::matplot)

    add_executable(sorting_benchmark sorting.cpp)
    target_link_libraries(sorting_benchmark PRIVATE Matplot++::matplot)
endif ()



