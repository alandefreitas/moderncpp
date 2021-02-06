include(CheckCXXSourceCompiles)

# Try to compile code with PMR
check_cxx_source_compiles("
        #include <cstdlib>
        #include <vector>
        #include <memory_resource>

        int main() {
            std::pmr::unsynchronized_pool_resource pool;
            std::pmr::vector<char> vec{ &pool };
            printf(\"%d\", vec.size());
            return EXIT_SUCCESS;
        }
" PMR_FOUND)

# If compiled correctly (concepts found)
if (PMR_FOUND AND NOT (TARGET PMR::concepts))
    # Create concepts interface target
    add_library(PMR::concepts INTERFACE IMPORTED)

    # Set -fconcepts flag publicly
    set_target_properties(PMR::concepts
            PROPERTIES
            INTERFACE_COMPILE_OPTIONS $<$<COMPILE_LANGUAGE:CXX>:-fconcepts>)
endif ()