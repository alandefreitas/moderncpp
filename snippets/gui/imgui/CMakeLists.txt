#[find_opengl Find OpenGL
find_package(OpenGL)
#]
if (NOT OPENGL_FOUND OR NOT EXPECTED_COMPILER)
    return()
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL Linux)
    find_package(X11 REQUIRED)
    if (NOT X11_Xi_FOUND)
        message(FATAL_ERROR "X11 Xi library is required")
    endif ()
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
        # target_compile_options(glfw PRIVATE /Wno-pedantic)
    else ()
        target_compile_options(glfw PRIVATE -Wno-pedantic -Wno-missing-field-initializers -Wno-unused-parameter)
    endif ()
endif ()

set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

#[fetch_imgui Fetch ImGUI
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.77
)
FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
    set(IMGUI_INCLUDE_DIR ${imgui_SOURCE_DIR}/)
    file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
    file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
    add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_SOURCES} ${imgui_SOURCE_DIR}/examples/imgui_impl_glfw.cpp ${imgui_SOURCE_DIR}/examples/imgui_impl_opengl3.cpp)
    add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
    #]
    #[link_imgui Link ImGUI
    target_include_directories(imgui PUBLIC ${IMGUI_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR})
    target_link_libraries(imgui ${OPENGL_LIBRARIES} glfw glad)
endif ()
#]

if (EXPECTED_COMPILER)
    add_executable(imgui_hello imgui_hello.cpp)
    target_link_libraries(imgui_hello PUBLIC imgui)
endif ()