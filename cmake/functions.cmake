# Enable exceptions for the target
function(target_exception_options TARGET_NAME)
    if (MSVC)
        # MSVC requires this flag if the code uses C++ exception handling
        target_compile_options(${TARGET_NAME} PRIVATE /EHsc)
    endif ()
endfunction()

# Enable big object files for the target
function(target_bigobj_options TARGET_NAME)
    if (MSVC)
        # MSVC requires this flag if the file has a lot of code
        target_compile_options(${TARGET_NAME} PRIVATE /bigobj)
    endif ()
endfunction()

# Enable pedantic warnings for the target
function(target_pedantic_options TARGET_NAME)
    # Set warning levels to about the same level for MSVC, GCC, and Clang
    if (BUILD_WITH_PEDANTIC_WARNINGS)
        if (MSVC)
            target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
        else ()
            target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
        endif ()
    endif ()
endfunction()

# Enable compile options for MSVC only
function(target_msvc_compile_options TARGET_NAME DEFINITION)
    if (MSVC)
        target_compile_options(${TARGET_NAME} PUBLIC ${DEFINITION})
    endif ()
endfunction()

# Set variable indicating if this is a master project
function(set_master_project_booleans)
    if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
        set(MASTER_PROJECT ON PARENT_SCOPE)
    else ()
        set(MASTER_PROJECT OFF PARENT_SCOPE)
    endif ()
endfunction()

# Set variables indicating if Debug/Release
function(set_debug_booleans)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(DEBUG_MODE ON PARENT_SCOPE)
        set(NOT_DEBUG_MODE OFF PARENT_SCOPE)
        set(RELEASE_MODE OFF PARENT_SCOPE)
        set(NOT_RELEASE_MODE ON PARENT_SCOPE)
    else ()
        set(DEBUG_MODE OFF PARENT_SCOPE)
        set(NOT_DEBUG_MODE ON PARENT_SCOPE)
        set(RELEASE_MODE ON PARENT_SCOPE)
        set(NOT_RELEASE_MODE OFF PARENT_SCOPE)
    endif ()
endfunction()

# Add sanitizer flag for Clang and GCC
# You shouldn't use sanitizers in Release Mode
macro(add_sanitizer flag)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${flag} -fno-omit-frame-pointer")
        set(DCMAKE_C_FLAGS "${DCMAKE_C_FLAGS} -fsanitize=${flag} -fno-omit-frame-pointer")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${flag}")
        set(DCMAKE_MODULE_LINKER_FLAGS "${DCMAKE_MODULE_LINKER_FLAGS} -fsanitize=${flag}")
    endif ()
endmacro()

# Add address sanitizer
# You shouldn't use sanitizers in Release Mode
macro(add_address_sanitizer)
    add_sanitizer("address")
endmacro()

# Add thread sanitizer
# You shouldn't use sanitizers in Release Mode
macro(add_thread_sanitizer)
    add_sanitizer("thread")
endmacro()

# Add undefined sanitizer
# You shouldn't use sanitizers in Release Mode
macro(add_undefined_sanitizer)
    add_sanitizer("undefined")
endmacro()

# Add memory sanitizer
# You shouldn't use sanitizers in Release Mode
macro(add_memory_sanitizer)
    add_sanitizer("memory")
endmacro()

# Add leak sanitizer
# You shouldn't use sanitizers in Release Mode
macro(add_leak_sanitizer)
    add_sanitizer("leak")
endmacro()

# Add all sanitizers
# You shouldn't use sanitizers in Release Mode
macro(add_all_sanitizers)
    add_address_sanitizer()
    add_leak_sanitizer()
    add_undefined_sanitizer()
    # add_thread_sanitizer() # not allowed with address
    # add_memory_sanitizer() # not supported with darwin20.1.0
endmacro()