# This hasn't been tested on all OSs
if (NOT APPLE OR NOT EXPECTED_COMPILER)
    return()
endif ()


# Library: https://github.com/zserge/tray
# Patch:   https://github.com/wormyrocks/tray
# - GUIs with system tray_ icons are great for deamons
# - This is a C99 library that seems to be abandoned
# - wormyrocks/tray includes a patch fixing some issues
# - So far, there is no good C++ library for the same task
# - The library is quite simple though
# - This can serve as inspiration for a C++ implementation
FetchContent_Declare(
        tray
        GIT_REPOSITORY https://github.com/wormyrocks/tray.git
        GIT_TAG 3e4a1447bff413e6907c5e43ac8d65e36866fdfd
)
FetchContent_GetProperties(tray)
if (NOT tray_POPULATED)
    FetchContent_Populate(tray)
    add_library(tray INTERFACE)
    target_sources(tray INTERFACE ${tray_SOURCE_DIR}/tray.h)
    target_include_directories(tray INTERFACE ${tray_SOURCE_DIR})
    if (WIN32)
        target_compile_definitions(tray INTERFACE TRAY_WINAPI)
    elseif (APPLE)
        target_compile_definitions(tray INTERFACE TRAY_APPKIT)
        target_link_libraries(tray INTERFACE "-framework Cocoa")
        # Some warnings the library doesn't deal with
        target_compile_options(tray INTERFACE -Wno-unused-parameter)
        target_compile_options(tray INTERFACE -Wno-unused-variable)
        target_compile_options(tray INTERFACE -Wno-writable-strings)
        target_compile_options(tray INTERFACE -Wno-misleading-indentation)
    elseif (UNIX)
        target_compile_definitions(tray INTERFACE TRAY_APPINDICATOR)
        target_link_libraries(tray INTERFACE "$(shell pkg-config --cflags appindicator3-0.1 --libs appindicator3-0.1)")
        # Some warnings the library doesn't deal with
        target_compile_options(tray INTERFACE -Wno-unused-parameter)
        target_compile_options(tray INTERFACE -Wno-unused-variable)
        target_compile_options(tray INTERFACE -Wno-writable-strings)
        target_compile_options(tray INTERFACE -Wno-misleading-indentation)
    endif ()
endif ()

# Create example
add_executable(tray_helloworld tray_hello.cpp)
target_link_libraries(tray_helloworld tray)

# Copy icons
if (WIN32)
    file(COPY ${tray_SOURCE_DIR}/icon.ico DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
elseif (APPLE)
    file(COPY ${tray_SOURCE_DIR}/icon.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif ()