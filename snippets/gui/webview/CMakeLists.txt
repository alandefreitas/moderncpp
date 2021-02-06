# This hasn't been tested on all OSs
if (NOT APPLE OR NOT EXPECTED_COMPILER)
    return()
endif ()

# Library: https://github.com/zserge/tray
# - Webviews are great for GUIs to work cross-platform
# - They are also great for mobile GUIs
# - So far, there is no good pure C++ library for the same task
# - The C++ interface in this repository is still changing often
# - The library is quite simple though
# - This can serve as inspiration for a C++ implementation
# - There's no CMake build script for this library yet
# - There's a CMake build script in the master branch but
#   still does not work for some platforms
FetchContent_Declare(
        webview
        GIT_REPOSITORY https://github.com/webview/webview.git
        GIT_TAG 50e4bcc420abdc7be96a54b7c79934a000b76901
)
FetchContent_GetProperties(webview)
if (NOT webview_POPULATED)
    # Library does not have a CMake build script
    # We have to do it ourselves
    FetchContent_Populate(webview)
    add_library(webview INTERFACE)
    target_sources(webview INTERFACE ${webview_SOURCE_DIR}/webview.h)
    target_include_directories(webview INTERFACE ${webview_SOURCE_DIR})

    # Set compile options
    # See: https://github.com/webview/webview/blob/master/script/build.sh
    if (WIN32)
        target_compile_definitions(webview INTERFACE WEBVIEW_EDGE)
        # See: https://github.com/webview/webview/blob/master/script/build.bat
        target_link_libraries(webview INTERFACE "-mwindows -L./dll/x64 -lwebview -lWebView2Loader")
        # target_compile_options(...) ?
    elseif (APPLE)
        target_compile_definitions(webview INTERFACE WEBVIEW_COCOA)
        target_compile_definitions(webview INTERFACE "GUI_SOURCE_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\"")
        target_compile_options(webview INTERFACE -Wno-all -Wno-extra -Wno-pedantic -Wno-delete-non-abstract-non-virtual-dtor)
        target_link_libraries(webview INTERFACE "-framework WebKit")
    elseif (UNIX)
        target_compile_definitions(webview INTERFACE WEBVIEW_GTK)
        target_compile_options(webview INTERFACE -Wall -Wextra -Wpedantic)
        target_link_libraries(webview INTERFACE "$(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0)")
    endif ()
endif ()

# Create example
add_executable(webview_hello webview_hello.cpp)
target_link_libraries(webview_hello PUBLIC webview)