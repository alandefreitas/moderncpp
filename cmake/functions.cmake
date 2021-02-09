# @brief Enable pedantic warnings for a target
# - This does not propagate to other targets
function(target_pedantic_warnings TARGET_NAME)
    # Set warning levels to about the same level for MSVC, GCC, and Clang
    if (MSVC)
        target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
    else ()
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
    endif ()
endfunction()

# @brief Sets pedantic compiler options for all target
# - In a more serious project, we would do that per target
# - Setting it for all targets unfortunately affects
# external libraries, which often lead to some warnings.
macro(add_pedantic_warnings)
    if (MSVC)
        add_compile_options(/W4 /WX)
    else ()
        add_compile_options(-Wall -Wextra -pedantic -Werror)
        #        if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        #            add_compile_options(-Wno-null-pointer-arithmetic -Wno-char-subscripts -Wno-c11-extensions)
        #        elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        #            add_compile_options(-Wno-error=class-memaccess -Wno-class-memaccess)
        #        else ()
        #            message(ERROR "Cannot disable the relevant warnings for ${CMAKE_CXX_COMPILER_ID}")
        #        endif ()
    endif ()
endmacro()

# @brief Enable compile options for MSVC only
# - Adding special compile options to make your code work on MSVC
#   is unfortunately very common, so this pattern becomes useful.
function(target_msvc_compile_options TARGET_NAME DEFINITION)
    if (MSVC)
        target_compile_options(${TARGET_NAME} PUBLIC ${DEFINITION})
    endif ()
endfunction()

# Enable exceptions for the target
function(target_exception_options TARGET_NAME)
    # MSVC requires this flag if the code uses C++ exception handling
    target_msvc_compile_options(${TARGET_NAME} PRIVATE /EHsc)
endfunction()

# @brief Enable big object files for the target
function(target_bigobj_options TARGET_NAME)
    # MSVC requires this flag if the file has a lot of code
    target_msvc_compile_options(${TARGET_NAME} PRIVATE /bigobj)
endfunction()

# @brief Set variable indicating if this is a master project
# - This is important to avoid building tests and examples when project is not master
function(set_master_project_booleans)
    if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
        set(MASTER_PROJECT ON PARENT_SCOPE)
    else ()
        set(MASTER_PROJECT OFF PARENT_SCOPE)
    endif ()
endfunction()

# @brief Set variables indicating if mode is Debug or Release
# - The mode might be neither of them
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

# @brief Create booleans GCC and CLANG to identify the compiler more easy
# - A boolean for MSVC already exists by default
function(set_compiler_booleans)
    set(CLANG OFF PARENT_SCOPE)
    set(GCC OFF PARENT_SCOPE)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        set(CLANG ON PARENT_SCOPE)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(GCC ON PARENT_SCOPE)
    endif ()
endfunction()

# @brief Add sanitizer flag for Clang and GCC to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_sanitizer flag)
    include(CheckCXXCompilerFlag)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        message("Looking for -fsanitize=${flag}")
        set(CMAKE_REQUIRED_FLAGS "-Werror -fsanitize=${flag}")
        check_cxx_compiler_flag(-fsanitize=${flag} HAVE_FLAG_SANITIZER)
        if (HAVE_FLAG_SANITIZER)
            message("Adding -fsanitize=${flag}")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=${flag} -fno-omit-frame-pointer")
            set(DCMAKE_C_FLAGS "${DCMAKE_C_FLAGS} -fsanitize=${flag} -fno-omit-frame-pointer")
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${flag}")
            set(DCMAKE_MODULE_LINKER_FLAGS "${DCMAKE_MODULE_LINKER_FLAGS} -fsanitize=${flag}")
        else ()
            message("-fsanitize=${flag} unavailable")
        endif ()
    endif ()
endmacro()

# @brief Add address sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_address_sanitizer)
    add_sanitizer("address")
endmacro()

# @brief Add thread sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_thread_sanitizer)
    add_sanitizer("thread")
endmacro()

# @brief Add undefined sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_undefined_sanitizer)
    add_sanitizer("undefined")
endmacro()

# @brief Add memory sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_memory_sanitizer)
    add_sanitizer("memory")
endmacro()

# @brief @brief Add leak sanitizer to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_leak_sanitizer)
    add_sanitizer("leak")
endmacro()

# @brief Add all sanitizers to all targets
# - You shouldn't use sanitizers in Release Mode
# - It's usually best to do that per target
macro(add_sanitizers)
    add_address_sanitizer()
    add_leak_sanitizer()
    add_undefined_sanitizer()
    # not allowed with address sanitizer
    # add_thread_sanitizer()
    # not supported
    # add_memory_sanitizer()
endmacro()