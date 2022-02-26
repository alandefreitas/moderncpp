#[hello_world CMakeLists.txt
add_executable(hello_world hello_world.cpp)
#]

add_executable(cin cin.cpp)

add_executable(printing output.cpp)

add_executable(iomanip iomanip.cpp)

#[fmt Find and link fmt library
find_package(fmt QUIET)
if (NOT fmt_FOUND)
    FetchContent_Declare(
            fmt
            GIT_REPOSITORY https://github.com/fmtlib/fmt
            GIT_TAG        8.1.1
    )
    FetchContent_MakeAvailable(fmt)
endif()
add_executable(format format.cpp)
target_link_libraries(format fmt::fmt)
#]
