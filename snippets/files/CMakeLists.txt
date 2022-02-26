add_executable(files files.cpp)

#[find_filesystem Find package
# Use CMake script to identify if Filesystem library is available
# This will look for the headers <filesystem> or <experimental/filesystem>
# See CMake Functions
find_package(Filesystem)
#]

#[find_boost_filesystem Find boost.filesystem if C++17 is not available
# See https://cmake.org/cmake/help/latest/module/FindBoost.html
if (NOT Filesystem_FOUND)
    find_package(Boost COMPONENTS filesystem)
endif()
#]

#[link_filesystem Use C++17 filesystem or Boost.Filesystem
add_executable(filesystem_manage filesystem.cpp)
if (Filesystem_FOUND)
    target_link_libraries(filesystem_manage PRIVATE std::filesystem)
    target_compile_definitions(filesystem_manage PRIVATE -DCXX_FILESYSTEM_HEADER=<${CXX_FILESYSTEM_HEADER}>)
    target_compile_definitions(filesystem_manage PRIVATE -DCXX_FILESYSTEM_NAMESPACE=${CXX_FILESYSTEM_NAMESPACE})
elseif(Boost_FOUND)
    target_link_libraries(filesystem_manage PRIVATE Boost::filesystem)
    target_compile_definitions(filesystem_manage PRIVATE -DCXX_FILESYSTEM_HEADER=<boost/filesystem.hpp>)
    target_compile_definitions(filesystem_manage PRIVATE -DCXX_FILESYSTEM_NAMESPACE=boost::filesystem)
endif()
#]