add_executable(template_functions template_functions.cpp)
add_executable(template_alias template_alias.cpp)

find_package(Concepts)
if (Concepts_FOUND)
    add_executable(concepts concepts.cpp)
else ()
    message(WARNING "Your compiler does not support *concepts* yet")
endif ()

add_executable(sfinae sfinae.cpp)