# Filesystem

!!!note "Filesystem"

    The Filesystem library provides facilities for performing operations on file systems and their components, such as 
    paths, regular files, and directories. 

    The filesystem library was originally developed as 
    [boost.filesystem](https://www.boost.org/doc/libs/1_78_0/libs/filesystem/doc/index.htm), was published as the 
    technical specification ISO/IEC TS 18822:2015, and finally merged to ISO C++ as of C++17. 

    The boost implementation is currently available on more compilers and platforms than the C++17 library.

{{ code_snippet("snippets/files/CMakeLists.txt", "find_filesystem", "cmake") }}

<hr>

{{ code_snippet("snippets/files/CMakeLists.txt", "find_boost_filesystem", "cmake") }}

<hr>

{{ code_snippet("snippets/files/CMakeLists.txt", "link_filesystem", "cmake") }}

<hr>

{{ all_code_snippets("snippets/files/filesystem.cpp") }}


