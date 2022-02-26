#######################################################
### Utilities for testing                           ###
#######################################################
# Print source location
add_executable(source_location source_location.cpp)
target_compile_features(source_location PRIVATE cxx_std_20)

# Unit tests in C++20 only
# Still failing on MSVC:
# - ut.hpp(9,1): a declaration can be exported only from a module interface unit; and
# - 'log': ambiguous symbol
if (NOT WIN32)
    # boost.ut
    #[fetch_boostut Fetch boost.ut
    FetchContent_Declare(boost.ut GIT_REPOSITORY https://github.com/boost-ext/ut GIT_TAG v1.1.8)
    FetchContent_MakeAvailable(boost.ut)
    #]
    #[link_boostut Link boost.ut
    add_executable(unit_tests unit_tests_ut.cpp)
    target_link_libraries(unit_tests PRIVATE boost.ut)
    #]
    if (NOT MSVC)
        target_compile_options(unit_tests PRIVATE -Wno-comma)
    endif()
endif()

# Unit tests
#[find_catch2 Find Catch2
find_package(Catch2 CONFIG)
if (Catch2_FOUND)
    include(${Catch2_DIR}/Catch.cmake)
else ()
    FetchContent_Declare(Catch2 URL https://github.com/catchorg/Catch2/archive/refs/tags/v2.13.6.zip)
    FetchContent_GetProperties(Catch2)
    if (NOT Catch2_POPULATED)
        FetchContent_Populate(Catch2)
        set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
        set(CATCH_USE_VALGRIND OFF) # "Perform SelfTests with Valgrind"
        set(CATCH_BUILD_TESTING OFF) # "Build SelfTest project"
        set(CATCH_BUILD_EXAMPLES OFF) # "Build documentation examples"
        set(CATCH_BUILD_EXTRA_TESTS OFF) # "Build extra tests"
        set(CATCH_BUILD_STATIC_LIBRARY OFF) # "Builds static library from the main implementation. EXPERIMENTAL"
        set(CATCH_ENABLE_COVERAGE OFF) # "Generate coverage for codecov.io"
        set(CATCH_ENABLE_WERROR OFF) # "Enable all warnings as errors"
        set(CATCH_INSTALL_DOCS OFF) # "Install documentation alongside library"
        set(CATCH_INSTALL_HELPERS ON) # "Install contrib alongside library"
        add_subdirectory(${catch2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/catch2)
        include(${catch2_SOURCE_DIR}/contrib/Catch.cmake)
    endif ()
endif ()
#]
#[link_catch2 Link Catch2
add_executable(unit_tests_catch unit_tests_catch.cpp)
target_link_libraries(unit_tests_catch PRIVATE Catch2::Catch2)
#]

# Plots
if (EXPECTED_COMPILER)
    #[find_matplot Find Matplot++
    find_package(Matplot++ QUIET)
    #]
    #[link_matplot Link Matplot++
    if (Matplot++_FOUND)
        add_executable(plots plots.cpp)
        target_link_libraries(plots PRIVATE Matplot++::matplot)
    endif ()
    #]
endif ()