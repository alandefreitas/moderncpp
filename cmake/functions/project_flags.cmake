# @brief Set variable indicating if this is a master project
# - This is important to avoid building tests and examples when project is not master
macro(set_master_project_booleans)
    #[set_master_project_booleans Set variable indicating if this is a master project
    if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
        set(MASTER_PROJECT ON)
    else ()
        set(MASTER_PROJECT OFF)
    endif ()
    #]
endmacro()

# @brief Set variables indicating if mode is Debug or Release
# - The mode might be neither of them
macro(set_debug_booleans)
    #[set_debug_booleans Set variables indicating if mode is Debug or Release
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(DEBUG_MODE ON)
        set(NOT_DEBUG_MODE OFF)
        set(RELEASE_MODE OFF)
        set(NOT_RELEASE_MODE ON)
    else ()
        set(DEBUG_MODE OFF)
        set(NOT_DEBUG_MODE ON)
        set(RELEASE_MODE ON)
        set(NOT_RELEASE_MODE OFF)
    endif ()
    #]
endmacro()

# @brief Create booleans GCC and CLANG to identify the compiler more easily
# - A boolean for MSVC already exists by default
macro(set_compiler_booleans)
    #[set_compiler_booleans Create booleans GCC and CLANG to identify the compiler more easily
    set(CLANG OFF)
    set(GCC OFF)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        set(CLANG ON)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(GCC ON)
    endif ()
    #]

    # Check if we are using the "expected" compilers, which are usually
    # Win+MSVC, Linux+GCC, Mac+Clang
    set(EXPECTED_COMPILER OFF)
    if (WIN32 AND MSVC)
        set(EXPECTED_COMPILER ON)
    elseif (APPLE AND CLANG)
        set(EXPECTED_COMPILER ON)
    elseif (UNIX AND NOT APPLE AND GCC)
        set(EXPECTED_COMPILER ON)
    endif ()
endmacro()

# @brief Create booleans to identify if this is a master project or just a dependency
macro(set_master_project_vars)
    if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
        set(MASTER_PROJECT ON)
    else ()
        set(MASTER_PROJECT OFF)
    endif ()
endmacro()

# @brief Set the default optimization flags in case the user didn't
#        explicitly choose it with -DCMAKE_CXX_FLAGS
macro(set_optimization_flags)
    #[set_optimization_flags Set the default optimization flags
    # This will set the flags only if the user didn't explicitly choose them with -DCMAKE_CXX_FLAGS
    if (NOT CMAKE_CXX_FLAGS)
        if (CMAKE_BUILD_TYPE STREQUAL "Debug")
            if (MSVC)
                list(APPEND CMAKE_CXX_FLAGS "/O0")
            else ()
                list(APPEND CMAKE_CXX_FLAGS "-O0")
            endif ()
        else ()
            if (MSVC)
                list(APPEND CMAKE_CXX_FLAGS "/O2")
            else ()
                list(APPEND CMAKE_CXX_FLAGS "-O2")
            endif ()
        endif ()
        message("Setting CXX flags to default for ${CMAKE_BUILD_TYPE} mode (${CMAKE_CXX_FLAGS})")
    else ()
        message("CXX flags are already set to ${CMAKE_CXX_FLAGS}")
    endif ()
    #]
endmacro()
