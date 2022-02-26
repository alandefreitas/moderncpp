add_executable(clock clock.cpp)

#[datetime Find datetime library
find_package(Date QUIET)
if (NOT Date_FOUND)
    # Find Threads library
    find_package(Threads)

    # Find Curl (to download timezone database)
    find_package(CURL QUIET)
    if (NOT CURL_FOUND)
        set(USE_SYSTEM_TZ_DB ON CACHE BOOL "Build tz library" FORCE)
    else ()
        set(USE_SYSTEM_TZ_DB OFF CACHE BOOL "Build tz library" FORCE)
    endif ()
    message("USE_SYSTEM_TZ_DB=${USE_SYSTEM_TZ_DB}")
    set(BUILD_TZ_LIB ON CACHE BOOL "Build tz library" FORCE)

    # Fetch date library
    FetchContent_Declare(date GIT_REPOSITORY https://github.com/HowardHinnant/date.git GIT_TAG v3.0.1)
    FetchContent_MakeAvailable(date)
endif ()

# Link library
add_executable(datetime datetime.cpp)
target_link_libraries(datetime date::date date::date-tz)
#]