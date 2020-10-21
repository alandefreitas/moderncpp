add_executable(template_functions template_functions.cpp)
add_executable(template_alias template_alias.cpp)

try_compile(HAS_CONCEPTS ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/concepts.cpp)
if (HAS_CONCEPTS)
    add_executable(concepts concepts.cpp)
endif()

add_executable(sfinae sfinae.cpp)
