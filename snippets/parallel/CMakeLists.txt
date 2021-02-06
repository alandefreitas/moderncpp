#######################################################
### External Libraries                              ###
#######################################################
# Threads
find_package(Threads)

# ASIO
FetchContent_Declare(asio GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git GIT_TAG asio-1-18-1)
FetchContent_GetProperties(asio)
if (NOT asio_POPULATED)
    FetchContent_Populate(asio)
    add_library(asio INTERFACE)
    target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
    target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
    target_link_libraries(asio INTERFACE Threads::Threads)
endif ()

# Async++
# The build script has a problem because it assumes stdlib++
# whenever the platform is APPLE. The user might not be using stdlib++
if (EXPECTED_COMPILER)
    FetchContent_Declare(asyncplusplus GIT_REPOSITORY https://github.com/Amanieu/asyncplusplus.git GIT_TAG v1.1)
    FetchContent_MakeAvailable(asyncplusplus)
endif ()

#######################################################
### Parallel programming                            ###
#######################################################
add_executable(multithreading multithreading.cpp)
target_link_libraries(multithreading PUBLIC Threads::Threads)

# the executors libraries in ASIO do not have lots of convenience functions
# but they are a good reference for the executor proposal coming to C++23
add_executable(executors executors.cpp)
target_link_libraries(executors asio)

add_executable(timers timers.cpp)
target_link_libraries(timers asio)

add_executable(signals signals.cpp)
target_link_libraries(signals asio)

# async++ has good convenience functions/algorithms for parallel computing
# But it's about to be completely replaced by the traditional executors in C++23
# Replace this library as soon as we have an alternative based on executors
if (EXPECTED_COMPILER)
    add_executable(async_pools async_pools.cpp)
    target_link_libraries(async_pools PUBLIC Async++)
endif ()
