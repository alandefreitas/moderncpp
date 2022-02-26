#[find_opengl Find OpenGL
find_package(OpenGL)
#]
if (NOT OPENGL_FOUND OR NOT EXPECTED_COMPILER)
    return()
endif ()

if (NOT TARGET glad AND EXPECTED_COMPILER)
    #[fetch_glad Fetch GLAD
    FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG df8e9e16110b305479a875399cee13daa0ccadd9)
    FetchContent_MakeAvailable(glad)
    #]
endif ()

if (NOT TARGET glfw AND EXPECTED_COMPILER)
    #[fetch_glfw Fetch GLFW
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.2)
    FetchContent_MakeAvailable(glfw)
    #]
    if (MSVC)
        # target_compile_options(glfw PUBLIC /Wno-pedantic)
    else ()
        target_compile_options(glfw PRIVATE -Wno-pedantic -Wno-missing-field-initializers -Wno-unused-parameter)
    endif ()
endif ()

if (EXPECTED_COMPILER)
    #[link_glfw Link GLFW
    add_executable(opengl_hello opengl_hello.cpp)
    target_link_libraries(opengl_hello PUBLIC glad glfw)
    #]
endif ()