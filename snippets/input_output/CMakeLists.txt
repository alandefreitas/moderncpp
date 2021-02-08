add_executable(hello_world hello_world.cpp)

add_executable(cin cin.cpp)

add_executable(printing printing.cpp)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG 6.1.2)
FetchContent_MakeAvailable(fmt)
add_executable(format format.cpp)
target_link_libraries(format fmt)

