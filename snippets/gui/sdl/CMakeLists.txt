find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

if (NOT TARGET glad)
    CPMAddPackage(NAME glad GIT_REPOSITORY https://github.com/Dav1dde/glad GIT_TAG df8e9e16110b305479a875399cee13daa0ccadd9 VERSION 0.1.33)
endif()

if (SDL2_FOUND)
    add_executable(sdl_hello sdl_hello.cpp)
    target_link_libraries(sdl_hello PUBLIC ${SDL2_LIBRARIES} glad)
endif()