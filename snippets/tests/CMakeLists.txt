add_executable(source_location source_location.cpp)

CPMAddPackage(NAME ut GIT_REPOSITORY https://github.com/boost-ext/ut/ VERSION 1.1.8)
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE boost.ut)
target_compile_options(unit_tests PRIVATE -Wno-comma)

find_package(Matplot++)
if (Matplot++_FOUND)
    add_executable(plots plots.cpp)
    target_link_libraries(plots PRIVATE Matplot++::matplot)
endif ()