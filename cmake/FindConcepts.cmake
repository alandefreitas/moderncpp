include(CheckCXXSourceCompiles)

check_cxx_source_compiles("
    #include <concepts>
    #include <type_traits>
    template <typename T> concept Number = std::is_arithmetic_v<T>;
    int main() { return 0; }
" Concepts_FOUND)

if (Concepts_FOUND AND NOT (TARGET std::concepts))
    add_library (std::concepts INTERFACE IMPORTED)
    set_target_properties (std::concepts
            PROPERTIES
            INTERFACE_COMPILE_OPTIONS $<$<COMPILE_LANGUAGE:CXX>:-fconcepts>)
endif ()