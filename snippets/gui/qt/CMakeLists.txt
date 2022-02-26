# Try to add Qt path to CMAKE_PREFIX_PATH
add_qt_to_cmake_paths()

# If we still don't have a CMAKE_PREFIX_PATH
#[throw Show message if Qt5Widgets_DIR is not set
if (NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)
    message("CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")

    message("CMAKE_PREFIX_PATH is not defined."
            "find_package(Qt5) is probably not going to work. "
            " Set the CMAKE_PREFIX_PATH environment variable to the install prefix of Qt 5"
            " - Set it in the command line as -DCMAKE_PREFIX_PATH=\"path/to/Qt5/lib/cmake\""
            " - Or set it in your build script with set(CMAKE_PREFIX_PATH path/to/Qt5/lib/cmake)")
endif ()
#]

#[find Find Qt
find_package(Qt5 COMPONENTS Widgets QUIET)
#]
if (NOT Qt5_FOUND)
    return()
endif ()

#[enable_moc Enable MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#]

#[link_qt Link Qt
add_executable(qt_helloworld qt_hello.cpp)
target_link_libraries(qt_helloworld Qt5::Widgets)
#]

#[disable_moc Disable MOC
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)
#]