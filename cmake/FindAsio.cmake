#[=======================================================================[.rst:
FindAsio
-------

This script is intended as a modern CMake replacement for manual configuration.
It exposes for the main libraries that might be linked in the install directory as targets.
However, the script returns values that might be deprecated if asio ever produces a
asio-config.cmake with its installation.

About generated files
^^^^^^^^^^^^^^^^^^^^^

Note that find_package is case-sensitive while manifest package names are always lowercase.
- Default CMake package names tend to include lower and uppercase characters (i.e., "OpenCV")
  so there might be conflicts even in the generated package names. Thus, by default, if CMake provides
  a module FindFoo.cmake or the package provides its own foo-config.cmake, we don't generate any
  generated FindFoo.cmake. This is one more reason why the API of find modules might break if a
  generated package starts providing its own configuration files.
- However, find_package(foo) will also look for FindFoo.cmake, where the first char is uppercase.
  Thus, the generated file names uppercase the first char of package names to keep this CMake convention
  while the find_package command can still be find_package(foo). It's important to notice these scripts
  will always return lowercase targets to ensure consistency so you can later link foo::foo without
  worrying about case sensitivity.

User options
^^^^^^^^^^^^

Users should use the find_package command to use this file.

The minimal signature is:

find_package(Asio)

The basic signature is:

find_package(<PackageName>
             [version]
             [EXACT]
             [QUIET]
             [MODULE]
             [REQUIRED]
             [[COMPONENTS] [components...]]
             [OPTIONAL_COMPONENTS components...]
             [NO_POLICY_SCOPE]
)

- VERSION: a single version "major[.minor[.patch[.tweak]]]" or a range "versionMin...[<]versionMax"
    - This file was generated because no Asio-config.cmake was provided, which means a Asio-version.cmake
      is very unlikely to be available.
    - If no config-file-version.cmake is provided, the configuration is assumed incompatible with any version requested
    - The only exception is when we have a cpp_modules directory layout, where this module will try to infer the
      version from the cpp_modules directory suffix. For instance, a package found in libgit/<version>/install
      is assumed to have version <version>.
    - Also note that CMake only supports core portion "major.minor.patch" of semver versions
      "major.minor.patch-pre-build" so only the core portion of semver version can be considered.
      This means there might some conflicts if the pre-release and release versions of the library with the
      same core are available.
    - This script can also infer the library version from a manifest file is installed in the <root>, <root>/shared,
      or <root>/lib directories.

The complete signature is:

find_package(<PackageName> [version] [EXACT] [QUIET]
             [REQUIRED] [[COMPONENTS] [components...]]
             [OPTIONAL_COMPONENTS components...]
             [CONFIG|NO_MODULE]
             [NO_POLICY_SCOPE]
             [NAMES name1 [name2 ...]]
             [CONFIGS config1 [config2 ...]]
             [HINTS path1 [path2 ... ]]
             [PATHS path1 [path2 ... ]]
             [PATH_SUFFIXES suffix1 [suffix2 ...]]
             [NO_DEFAULT_PATH]
             [NO_PACKAGE_ROOT_PATH]
             [NO_CMAKE_PATH]
             [NO_CMAKE_ENVIRONMENT_PATH]
             [NO_SYSTEM_ENVIRONMENT_PATH]
             [NO_CMAKE_PACKAGE_REGISTRY]
             [NO_CMAKE_BUILDS_PATH] # Deprecated; does nothing.
             [NO_CMAKE_SYSTEM_PATH]
             [NO_CMAKE_SYSTEM_PACKAGE_REGISTRY]
             [CMAKE_FIND_ROOT_PATH_BOTH |
              ONLY_CMAKE_FIND_ROOT_PATH |
              NO_CMAKE_FIND_ROOT_PATH])

The meaning of these parameters is available at: https://cmake.org/cmake/help/latest/command/find_package.html

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``Asio::asio``
  The Asio library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``Asio_FOUND``
  True if the system has the asio library.
``Asio_VERSION``
  The version of the asio library which was found.
``Asio_INCLUDE_DIRS``
  Include directories needed to use asio.
``Asio_LIBRARIES``
  Libraries needed to link to asio.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``Asio_INCLUDE_DIR``
  The directory containing ``foo.h``.
``Asio_LIBRARY``
  The path to the asio library.

@see https://cmake.org/cmake/help/latest/manual/cmake-developer.7.html

#]=======================================================================]

#######################################################
### Dev instructions: USER INPUT                    ###
#######################################################
# Users can set variables in the parent script to manipulate the behavior of
# find_package. Thus, these variables that should NOT be changed in this script.
# Besides the user parameters provided to find_package, this script will also
# consider these variables from the parent script.
# Asio_DIR: The directory where we can find asio
# CMAKE_FIND_PACKAGE_SORT_ORDER: The preference order for versions (NONE, NAME (lexographically), NATURAL (VERSION_GREATER))
# CMAKE_FIND_PACKAGE_SORT_DIRECTION: How to order packager versions (DEC (default) or ASC (will return min version found))
# Variables that should NOT be used (users need them to manipulate behavior)
# Asio_LIBRARY: The path of the library
# Asio_Yy_LIBRARY: The path of library Yy provided by the module Xxx
# Asio_INCLUDE_DIR: Where to find headers for using the library
# Asio_Yy_INCLUDE_DIR: Where to find headers for using the library component Yy

#######################################################
### Dev instructions: CMAKE INPUT                   ###
#######################################################
# CMake transforms the user parameters given to find_packages into these variables
# CMAKE_FIND_PACKAGE_NAME: The <PackageName> which is searched for asio
# Asio_FIND_REQUIRED: True if REQUIRED option was given
# Asio_FIND_COMPONENTS: Required components
# Asio_FIND_REQUIRED_<c>: True if component <c> was required
# Asio_FIND_QUIETLY: True if QUIET option was given
# Asio_CONSIDERED_CONFIGS: Config files considered by CMake
# Asio_CONSIDERED_VERSIONS: Versions considered by CMake

# When a version is required:
# Asio_FIND_VERSION: Full requested version string
# Asio_FIND_MAJOR: Major version if requested, else 0
# Asio_FIND_MINOR: Minor version if requested, else 0
# Asio_FIND_PATCH: Patch version if requested, else 0
# Asio_FIND_TWEAK: Tweak version if requested, else 0
# Asio_FIND_VERSION_COUNT: Number of version components, 0 to 4
# Asio_FIND_VERSION_EXACT: True if EXACT option was given

# When a version range was required:
# Asio_FIND_VERSION_RANGE: Full requested version range string
# Asio_FIND_VERSION_RANGE_MIN: Lower end point of the version range
# Asio_FIND_VERSION_RANGE_MAX: Upper end point of the version range
# Asio_FIND_VERSION_MIN: Full requested version string of the lower end point of the range
# Asio_FIND_VERSION_MIN_MAJOR: Major version of the lower end point if requested (or 0)
# Asio_FIND_VERSION_MIN_MINOR: Minor version of the lower end point if requested (or 0)
# Asio_FIND_VERSION_MIN_PATCH: Patch version of the lower end point if requested (or 0)
# Asio_FIND_VERSION_MIN_TWEAK: Major version of the lower end point if requested (or 0)
# Asio_FIND_VERSION_MIN_COUNT: Number of version components in lower end point, 0 to 4
# Asio_FIND_VERSION_RANGE_MAX: Lower end point of the version range
# Asio_FIND_VERSION_RANGE_MAX: Upper end point of the version range
# Asio_FIND_VERSION_MAX: Full requested version string of the upper end point of the range
# Asio_FIND_VERSION_MAX_MAJOR: Major version of the upper end point if requested (or 0)
# Asio_FIND_VERSION_MAX_MINOR: Minor version of the upper end point if requested (or 0)
# Asio_FIND_VERSION_MAX_PATCH: Patch version of the upper end point if requested (or 0)
# Asio_FIND_VERSION_MAX_TWEAK: Major version of the upper end point if requested (or 0)
# Asio_FIND_VERSION_MAX_COUNT: Number of version components in upper end point, 0 to 4
# Asio_FIND_VERSION_COMPLETE: full requested version string as specified (single or range)

#######################################################
### Macros                                          ###
#######################################################
# Print message if not in quiet mode
macro(Asio_message _MSG)
    if (NOT Asio_FIND_QUIETLY)
        message(STATUS
                "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
    endif ()
endmacro()

macro(throw)
    message(FATAL_ERROR "asio not found")
endmacro()

macro(throw_if_required)
    if (Asio_FIND_REQUIRED)
        throw()
    else ()
        Asio_message("asio not found")
        return()
    endif ()
endmacro()

function(is_subdirectory BASEDIR SUBDIR RESULT)
    # Calculate absolute dirs
    file(REAL_PATH ${BASEDIR} BASEDIR)
    file(REAL_PATH ${SUBDIR} SUBDIR)
    # Check if subdir begins with basedir
    string(FIND ${SUBDIR} ${BASEDIR} SUBSTR_POS)
    if (SUBSTR_POS EQUAL 0)
        set(${RESULT} TRUE PARENT_SCOPE)
    else ()
        set(${RESULT} FALSE PARENT_SCOPE)
    endif ()
endfunction()

#######################################################
### Set some hint paths                             ###
#######################################################
# Initial hints
set(Asio_INCLUDE_PATHS)
set(Asio_INCLUDE_HINTS)

# If the user is using this script, it's very likely that it's also using cppm
# or a library that used cppm. This means Asio_INSTALL_HINT should be set
# at this point and we also use it as a hint path.
if (Asio_INSTALL_HINT)
    set(Asio_INCLUDE_HINTS ${Asio_INCLUDE_HINTS} ${Asio_INSTALL_HINT} ${Asio_INSTALL_HINT}/include ${Asio_INSTALL_HINT}/asio/include)
endif ()

# Get some more hints from PkgConfig, if available
if (Asio_FIND_QUIETLY)
    find_package(PkgConfig QUIET)
else ()
    find_package(PkgConfig)
endif ()
if (PKG_CONFIG_FOUND)
    # PKG_CONFIG_EXECUTABLE and PKG_CONFIG_VERSION_STRING should be set at this point

    # Check and maybe set the pkgconfig path
    if ($ENV{PKG_CONFIG_PATH})
        Asio_message("PKG_CONFIG_PATH=$ENV{PKG_CONFIG_PATH}")
    elseif (Asio_INSTALL_HINT)
        # If PKG_CONFIG_PATH is empty and we have an installation hint with a package config file
        if (EXISTS ${Asio_INSTALL_HINT}/lib/pkgconfig)
            set(ENV{PKG_CONFIG_PATH} ${Asio_INSTALL_HINT}/lib/pkgconfig)
        endif ()
    endif ()

    # Run pkgconfig
    pkg_check_modules(PC_asio QUIET asio)
    set(Asio_INCLUDE_PATHS ${Asio_INCLUDE_PATHS} ${PC_Asio_INCLUDE_DIRS})
endif ()

#######################################################
### Look for packages candidates                    ###
#######################################################
find_path(Asio_INCLUDE_DIR
        NAMES asio.hpp
        HINTS ${Asio_INCLUDE_HINTS}
        PATHS ${Asio_INCLUDE_PATHS}
        PATH_SUFFIXES include
        )

if (NOT Asio_INCLUDE_DIR)
    throw_if_required()
endif ()

#######################################################
### Check versions                                  ###
#######################################################
# The package version might be available from pkgconfig or from the cppm directory layout
if (NOT Asio_VERSION)
    if (PC_Asio_VERSION)
        set(Asio_VERSION ${PC_Asio_VERSION})
    endif ()
endif ()

if (NOT Asio_VERSION)
    if (Asio_INSTALL_HINT)
        is_subdirectory(${Asio_INSTALL_HINT} ${Asio_INCLUDE_DIR} is_cppm_subdir)
        if (is_cppm_subdir)
            get_filename_component(Asio_ALL_INSTALLS_PATH ${Asio_INSTALL_HINT} DIRECTORY)
            get_filename_component(Asio_VERSION_PATH ${Asio_ALL_INSTALLS_PATH} DIRECTORY)
            get_filename_component(Asio_VERSION ${Asio_VERSION_PATH} NAME)
            if (NOT Asio_VERSION VERSION_GREATER_EQUAL 0.0.0)
                unset(Asio_VERSION)
            endif ()
        endif ()
    endif ()
endif ()

#######################################################
### Results                                         ###
#######################################################
# A find module should check if the values found are OK and set the following variables.
# FindPackageHandleStandardArgs will make most of the work here.
# Result variables find_package inherits from the from config script (returned to the user)
# Found:
#    Asio_FOUND: Whether we found the module
#    Asio_NOT_FOUND_MESSAGE: A message when not found. Use this instead of a message.
#    Asio_Yy_FOUND: Whether we found the component Yy
#    Asio_ROOT_DIR: Where to find the base directory of the module
# Headers:
#    Asio_INCLUDE_DIRS: Optionally, the final set of include directories listed in one variable
#    Asio_INCLUDE_DIR:
# Libraries
#     Asio_RUNTIME_LIBRARY_DIRS: Optionally, PATH on windows or LD_LIBRARY_PATH on UNIX
#     Asio_LIBRARIES: The libraries to use with the module
#     Asio_LIBRARY_DIRS: Optionally, the final set of library directories listed in one variable for use by client code
# Definitions
#     Asio_DEFINITIONS: The compile definitions to use when compiling code that uses the module
# Executables
#     Asio_EXECUTABLE: The full absolute path to an executable.
#     Asio_YYY_EXECUTABLE: The full absolute path to another executable where YYY is the tool name.
# Versions (if acceptable)
#     Asio_VERSION: The version we found
#     Asio_VERSION_VV: Variables of this form specify whether the Xxx module being provided is version VV of the module
#     Asio_VERSION_MAJOR: major version component
#     Asio_VERSION_MINOR: minor version component
#     Asio_VERSION_PATCH: patch version component
#     Asio_VERSION_TWEAK: tweak version component
#     Asio_VERSION_COUNT: count of version components (0 to 4)

# FindPackageHandleStandardArgs will check if values are correct
# It ensures REQUIRED_VARS have valid values and Asio_VERSION matches the requirements
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Asio
        FOUND_VAR Asio_FOUND
        REQUIRED_VARS
        Asio_INCLUDE_DIR
        VERSION_VAR Asio_VERSION
        )

#######################################################
### Variable results                                ###
#######################################################
# Provide variables the user can user can use to link the library
if (Asio_FOUND)
    set(Asio_INCLUDE_DIRS ${Asio_INCLUDE_DIR})
endif ()

#######################################################
### Target results                                  ###
#######################################################
# Provide targets the user can user can use to link the library
if (Asio_FOUND AND NOT TARGET asio::asio)
    # Imported targets can be of unknown type
    add_library(asio::asio INTERFACE IMPORTED)
    set_target_properties(asio::asio PROPERTIES
            # IMPORTED_LOCATION "${Asio_LIBRARY}"
            # INTERFACE_COMPILE_OPTIONS "${PC_Asio_CFLAGS_OTHER}"
            INTERFACE_INCLUDE_DIRECTORIES "${Asio_INCLUDE_DIR}"
            )
endif ()

# Hide cache variables
mark_as_advanced(
        Asio_INCLUDE_DIR
)