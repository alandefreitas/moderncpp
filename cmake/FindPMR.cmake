include(CheckCXXSourceCompiles)

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
if (PMR_FOUND AND NOT (TARGET std::pmr))
    add_library(std::pmr INTERFACE IMPORTED)
endif ()