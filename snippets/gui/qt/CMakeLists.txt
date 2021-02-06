# If the user has not set the Qt prefix path
if (NOT CMAKE_PREFIX_PATH)
    # Loop through some reasonable candidates
    # This code can be improved a lot
    foreach (QT_V1_CANDIDATE 5 4)
        foreach (QT_V2_CANDIDATE 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0)
            foreach (QT_V3_CANDIDATE 10 9 8 7 6 5 4 3 2 1 0)
                set(QT_VERSION_CANDIDATES ${QT_VERSION_CANDIDATES} ${QT_V1_CANDIDATE}.${QT_V2_CANDIDATE}.${QT_V2_CANDIDATE})
            endforeach ()
        endforeach ()
    endforeach ()
    set(QT_PATH_CANDIDATES
            /usr/local/qt/
            /usr/local/Cellar/qt/
            "C:\\Qt\\"
            )
    foreach (QT_PATH_CANDIDATE ${QT_PATH_CANDIDATES})
        if (EXISTS ${QT_PATH_CANDIDATE})
            foreach (QT_VERSION_CANDIDATE ${QT_VERSION_CANDIDATES})
                set(FULL_PATH_CANDIDATE ${QT_PATH_CANDIDATE}/${QT_VERSION_CANDIDATE})
                if (EXISTS ${FULL_PATH_CANDIDATE})
                    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${FULL_PATH_CANDIDATE})
                endif ()
                set(FULL_PATH_CANDIDATE ${QT_PATH_CANDIDATE}/${QT_VERSION_CANDIDATE}/lib/cmake/Qt5)
                if (EXISTS ${FULL_PATH_CANDIDATE})
                    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${FULL_PATH_CANDIDATE})
                endif ()
            endforeach ()
        endif ()
    endforeach ()
endif ()

# If we still don't have a CMAKE_PREFIX_PATH
if (NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
    message("find_package(Qt5) is probably not going to work. Set the CMAKE_PREFIX_PATH "
            "environment variable to the install prefix of Qt 5, either on the command line as "
            "-DCMAKE_PREFIX_PATH=\"path/to/Qt5/lib/cmake\" or with set(CMAKE_PREFIX_PATH path/to/Qt5/lib/cmake)")
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