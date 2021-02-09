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