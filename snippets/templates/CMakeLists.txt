add_executable(template_functions template_functions.cpp)
add_executable(template_alias template_alias.cpp)

find_package(Concepts)
if (Concepts_FOUND)
    #[concepts Find concepts
    add_executable(concepts concepts.cpp)
    target_compile_features(concepts PRIVATE cxx_std_20)
    #]
else ()
    message("Your compiler does not support *concepts* yet")
endif ()

add_executable(sfinae sfinae.cpp)

add_executable(metaprogramming metaprogramming.cpp)
