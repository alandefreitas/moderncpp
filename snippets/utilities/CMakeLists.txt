add_executable(clock clock.cpp)
add_executable(filesystem filesystem.cpp)
add_executable(random random.cpp)
add_executable(regex regex.cpp)

find_package(Threads)
add_executable(multithreading multithreading.cpp)
target_link_libraries(multithreading PUBLIC Threads::Threads)

CPMAddPackage(NAME asyncplusplus GIT_REPOSITORY https://github.com/Amanieu/asyncplusplus VERSION 1.1)
add_executable(async_pools async_pools.cpp)
target_link_libraries(async_pools PUBLIC Async++)

CPMAddPackage(NAME fmt GIT_TAG 6.1.2 GITHUB_REPOSITORY fmtlib/fmt)
add_executable(format format.cpp)
target_link_libraries(format fmt)

CPMAddPackage(NAME asio VERSION 1.16.1 GITHUB_REPOSITORY chriskohlhoff/asio GIT_TAG asio-1-16-1)
add_library(asio INTERFACE)
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

add_executable(network network.cpp)
target_link_libraries(network asio)

add_executable(network_async network_async.cpp)
target_link_libraries(network_async asio)
