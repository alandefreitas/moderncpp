#######################################################
### Utilities for testing                           ###
#######################################################
# Print source location
add_executable(source_location source_location.cpp)

# Unit tests in C++20 only
# boost.ut
FetchContent_Declare(boost.ut GIT_REPOSITORY https://github.com/boost-ext/ut GIT_TAG v1.1.8)
FetchContent_MakeAvailable(boost.ut)
add_executable(unit_tests unit_tests_ut.cpp)
target_link_libraries(unit_tests PRIVATE boost.ut)
target_compile_options(unit_tests PRIVATE -Wno-comma)

# Unit tests
FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2 GIT_TAG v3.0.0-preview3)
FetchContent_MakeAvailable(Catch2)
add_executable(unit_tests_catch unit_tests_catch.cpp)
target_link_libraries(unit_tests_catch PRIVATE Catch2::Catch2WithMain)

# Plots
if (EXPECTED_COMPILER)
    find_package(Matplot++ QUIET)
    if (Matplot++_FOUND)
        add_executable(plots plots.cpp)
        target_link_libraries(plots PRIVATE Matplot++::matplot)
    endif ()
endif ()