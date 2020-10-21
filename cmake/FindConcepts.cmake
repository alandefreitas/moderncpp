# Adapted from: https://github.com/scylladb/seastar/blob/master/cmake/FindConcepts.cmake

include(CheckCXXSourceCompiles)

# Set the concepts flag
set(CMAKE_REQUIRED_FLAGS -fconcepts)

# Try to compile
check_cxx_source_compiles("#if __cpp_concepts == 201507
#include <concepts>
#include <type_traits>
template <typename T> concept Number = std::is_arithmetic_v<T>;
int main() { return 0; }
#endif" Concepts_FOUND)

# If compiled correctly (concepts found)
if (Concepts_FOUND AND NOT (TARGET Concepts::concepts))
    # Create concepts interface target
    add_library (Concepts::concepts INTERFACE IMPORTED)

    # Set -fconcepts flag publicly
    set_target_properties (Concepts::concepts
            PROPERTIES
            INTERFACE_COMPILE_OPTIONS $<$<COMPILE_LANGUAGE:CXX>:-fconcepts>)
endif ()