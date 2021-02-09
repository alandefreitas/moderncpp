# Try to add Qt path to CMAKE_PREFIX_PATH
add_qt_to_cmake_paths()

# If we still don't have a CMAKE_PREFIX_PATH
if (NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")

    message("CMAKE_PREFIX_PATH is not defined."
            "find_package(Qt5) is probably not going to work. "
            " Set the CMAKE_PREFIX_PATH environment variable to the install prefix of Qt 5"
            " - Set it in the command line as -DCMAKE_PREFIX_PATH=\"path/to/Qt5/lib/cmake\""
            " - Or set it in your build script with set(CMAKE_PREFIX_PATH path/to/Qt5/lib/cmake)")
endif ()

# Try to find qt anyway
find_package(Qt5 COMPONENTS Widgets QUIET)
if (NOT Qt5_FOUND)
    return()
endif ()

# Create example
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(qt_helloworld qt_hello.cpp)
target_link_libraries(qt_helloworld Qt5::Widgets)

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)