# @brief Set variable indicating if this is a master project
# - This is important to avoid building tests and examples when project is not master
macro(set_master_project_booleans)
    if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
        set(MASTER_PROJECT ON)
    else ()
        set(MASTER_PROJECT OFF)
    endif ()
endmacro()

# @brief Set variables indicating if mode is Debug or Release
# - The mode might be neither of them
macro(set_debug_booleans)
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
endmacro()

# @brief Create booleans GCC and CLANG to identify the compiler more easily
# - A boolean for MSVC already exists by default
macro(set_compiler_booleans)
    set(CLANG OFF)
    set(GCC OFF)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        set(CLANG ON)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(GCC ON)
    endif ()
endmacro()