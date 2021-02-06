add_executable(clock clock.cpp)

set(BUILD_TZ_LIB ON CACHE BOOL "Build tz library" FORCE)
FetchContent_Declare(date GIT_REPOSITORY https://github.com/HowardHinnant/date.git GIT_TAG v3.0.0)
FetchContent_MakeAvailable(date)
target_compile_options(date-tz PUBLIC -Wno-error=deprecated-declarations)
add_executable(datetime datetime.cpp)
target_link_libraries(datetime date date-tz)