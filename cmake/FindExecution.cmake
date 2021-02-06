include(CheckCXXSourceCompiles)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    find_package(TBB QUIET)
    if (NOT TBB_FOUND)
        set(Execution_FOUND OFF)
        return()
    else()
        add_library(std::execution INTERFACE IMPORTED)
        target_link_libraries(std::execution INTERFACE tbb)
    endif()
endif ()

check_cxx_source_compiles("
        #include <execution>
        #include <vector>
        int main() {
            std::vector<int> x{5,7,6,4,8,2};
            std::sort(std::execution::par, x.begin(), x.end());
            return 0;
        }
" Execution_FOUND)

if (Execution_FOUND AND NOT (TARGET std::execution))
    add_library(std::execution INTERFACE IMPORTED)
endif ()