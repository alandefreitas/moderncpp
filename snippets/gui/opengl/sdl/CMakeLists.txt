if (NOT EXPECTED_COMPILER)
    return()
endif ()

find_package(SDL2)

if (SDL2_FOUND)
    if (NOT TARGET glad AND EXPECTED_COMPILER)
        FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG df8e9e16110b305479a875399cee13daa0ccadd9)
        FetchContent_MakeAvailable(glad)
    endif ()

    if (SDL2_FOUND AND EXPECTED_COMPILER)
        add_executable(sdl_hello sdl_hello.cpp)
        target_link_libraries(sdl_hello PUBLIC ${SDL2_LIBRARIES} glad)
        target_include_directories(sdl_hello PRIVATE ${SDL2_INCLUDE_DIRS})
    endif ()
endif ()