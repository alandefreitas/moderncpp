add_executable(random random.cpp)

# PCG is failing on windows: pcg_uint128.hpp(74,1) - Unable to determine target endianness
# It's not that complicated to find a workaround and set this macro manually
if (NOT WIN32)
    #[pcg Find PCG
    find_package(pcg-cpp QUIET)
    if (NOT pcg-cpp_FOUND)
        FetchContent_Declare(pcg-cpp GIT_REPOSITORY https://github.com/imneme/pcg-cpp.git GIT_TAG v0.98.1)
        FetchContent_GetProperties(pcg-cpp)
        if (NOT pcg-cpp_POPULATED)
            FetchContent_Populate(pcg-cpp)
            # Create header-only library with pcg-cpp include files
            add_library(pcg-cpp INTERFACE)
            target_include_directories(pcg-cpp INTERFACE ${pcg-cpp_SOURCE_DIR}/include)
        endif ()
    endif()
    add_executable(pcg pcg.cpp)
    target_link_libraries(pcg pcg-cpp)
    #]
endif()