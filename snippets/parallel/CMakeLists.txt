# https://stackoverflow.com/questions/66881657/ubuntu-18-gcc-9-failed-to-link-tbb-library-for-execution-policy-in-standard-lib
#[policies CMakeLists.txt
find_package(Threads)
find_package(Execution)
find_library(TBB_LIBRARY NAMES tbb)
if (Execution_FOUND AND TBB_LIBRARY)
    add_executable(policies policies.cpp)
    target_link_libraries(policies PUBLIC std::execution Threads::Threads ${TBB_LIBRARIES})
endif ()
#]

#[threads CMakeLists.txt
find_package(Threads)
add_executable(multithreading multithreading.cpp)
target_link_libraries(multithreading PUBLIC Threads::Threads)
#]

#[find_asio Find ASIO
find_package(Asio 1.21.0 QUIET)
if (NOT Asio_FOUND)
    FetchContent_Declare(asio GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git GIT_TAG asio-1-21-0)
    FetchContent_GetProperties(asio)
    if (NOT asio_POPULATED)
        FetchContent_Populate(asio)
        add_library(asio INTERFACE)
        target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
        target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
        target_link_libraries(asio INTERFACE Threads::Threads)
    endif ()
endif()
#]

# The executor libraries in ASIO do not have lots of convenience functions
# but they are a good reference for the executor proposal
#[executors CMakeLists.txt
add_executable(executors executors.cpp)
target_link_libraries(executors asio)
#]

#[timers CMakeLists.txt
add_executable(timers timers.cpp)
target_link_libraries(timers asio)
#]

#[signals CMakeLists.txt
add_executable(signals signals.cpp)
target_link_libraries(signals asio)
#]

# Async++ has good convenience functions/algorithms for parallel computing
# But it's about to be completely replaced by the traditional executors in C++23
# Replace this library as soon as we have an alternative based on executors
# Async++
# The build script has a few problems
# - stdlib++ whenever the platform is APPLE. The user might not be using stdlib++
# - it doesn't seem to be working on more recent MSVC compilers
# - it doesn't seem to be working on more recent Clang compilers
if (GCC)
    #[asyncplusplus CMakeLists.txt
    FetchContent_Declare(asyncplusplus GIT_REPOSITORY https://github.com/Amanieu/asyncplusplus.git GIT_TAG v1.1)
    FetchContent_MakeAvailable(asyncplusplus)
    add_executable(async_pools async_pools.cpp)
    target_link_libraries(async_pools PUBLIC Async++)
    target_compile_features(async_pools PUBLIC cxx_std_17)
    #]
endif ()
