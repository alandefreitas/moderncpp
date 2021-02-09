# @brief Try to find and add the QT directories to CMAKE_PREFIX_PATH
# - You should add the Qt directory directly in CMAKE_PREFIX_PATH
# - If you fail to do so, this macro will look for this path
#   using reasonable hints
macro(add_qt_to_cmake_paths)
    # This script looks for Qt5 only
    # - Change this variable to adapt the script
    set(QT_VERSION 5)

    # Reasonable paths to look for Qt
    set(QT_PATH_HINTS
            /usr/local/qt/
            /usr/local/Cellar/qt/
            "C:\\Qt\\"
            )

    # Reasonable paths to look for the Qt CMake scripts
    set(QT_CMAKE_PATH_POSTFIX_HINTS
            lib/cmake/
            lib/cmake/Qt${QT_VERSION}
            )

    # Look for Qt paths
    foreach (QT_PATH_HINT ${QT_PATH_HINTS})
        if (EXISTS ${QT_PATH_HINT} AND IS_DIRECTORY ${QT_PATH_HINT})
            message("Found Qt hint path ${QT_PATH_HINT}")
            # Explore children directories
            file(GLOB QT_PATH_HINT_CHILDREN RELATIVE ${QT_PATH_HINT} ${QT_PATH_HINT}/*)
            foreach (QT_PATH_HINT_CHILD ${QT_PATH_HINT_CHILDREN})
                set(FULL_QT_PATH_HINT_CHILD ${QT_PATH_HINT}${QT_PATH_HINT_CHILD})
                if (IS_DIRECTORY ${FULL_QT_PATH_HINT_CHILD})
                    message("Found child directory ${FULL_QT_PATH_HINT_CHILD}")
                    # Check if it matches the pattern of version numbers
                    if (QT_PATH_HINT_CHILD MATCHES "[0-9]+\\.?[0-9]*\\.?[0-9]*")
                        message("${QT_PATH_HINT_CHILD} follows the version pattern")
                        if (NOT ${FULL_QT_PATH_HINT_CHILD} IN_LIST CMAKE_PREFIX_PATH)
                            message("Adding new Qt hint child ${FULL_QT_PATH_HINT_CHILD} to CMAKE_PREFIX_PATH")
                            list(APPEND CMAKE_PREFIX_PATH ${FULL_QT_PATH_HINT_CHILD})
                        endif ()
                        # Explore possible path postfixes for CMake scripts
                        foreach (QT_CMAKE_PATH_POSTFIX_HINT ${QT_CMAKE_PATH_POSTFIX_HINTS})
                            set(FULL_QT_CMAKE_PATH ${FULL_QT_PATH_HINT_CHILD}/${QT_CMAKE_PATH_POSTFIX_HINT})
                            message("Testing ${FULL_QT_CMAKE_PATH}")
                            if (EXISTS ${FULL_QT_CMAKE_PATH} AND IS_DIRECTORY ${FULL_QT_CMAKE_PATH})
                                message("Found ${FULL_QT_CMAKE_PATH}")
                                if (NOT ${FULL_QT_CMAKE_PATH} IN_LIST CMAKE_PREFIX_PATH)
                                    message("Adding ${FULL_QT_CMAKE_PATH} to CMAKE_PREFIX_PATH")
                                    list(APPEND CMAKE_PREFIX_PATH ${FULL_QT_CMAKE_PATH})
                                else ()
                                    message("Already found ${FULL_QT_CMAKE_PATH} in CMAKE_PREFIX_PATH")
                                endif ()
                            endif ()
                        endforeach ()
                    endif ()
                endif ()
            endforeach ()
        endif ()
    endforeach ()
endmacro()
