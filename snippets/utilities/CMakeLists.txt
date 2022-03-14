add_executable(regex regex.cpp)


# Unit tests
#[find_lyra Find Lyra
find_package(Lyra CONFIG)
if (NOT Lyra_FOUND)
    FetchContent_Declare(Lyra URL https://github.com/bfgroup/Lyra/archive/refs/tags/1.6.zip)
    FetchContent_GetProperties(Lyra)
    if (NOT Lyra_POPULATED)
        FetchContent_Populate(Lyra)
        add_library( lyra INTERFACE )
        target_include_directories(
                lyra
                INTERFACE
                $<BUILD_INTERFACE:${lyra_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>
        )
        add_library( bfg::lyra ALIAS lyra )
    endif ()
endif ()
#]
#[link_lyra Link Lyra
add_executable(lyra_cli lyra_cli.cpp)
target_link_libraries(lyra_cli PRIVATE bfg::lyra)
#]