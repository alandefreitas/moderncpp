# Ranges

!!! note "Ranges"

    The [ranges library](https://en.cppreference.com/w/cpp/ranges) is an extension and generalization of the algorithms
    and iterator libraries that makes them more powerful by making them composable and less error-prone.

    All algorithms that take iterator pairs have overloads that accept ranges (e.g ranges::sort).

    The library creates and manipulates range views, lightweight objects that indirectly represent iterable sequences
    (ranges). Ranges are an abstraction on top of [begin, end) iterator pairs, e.g. ranges made by implicit conversion 
    from containers. 

    The ranges library was originally developed as the  
    [range-v3 library](https://github.com/ericniebler/range-v3), and was finally merged to ISO C++ as of C++20.
    The range-v3 implementation is currently available on more compilers and platforms than the C++20 library.


{{ code_snippet("snippets/algorithm/CMakeLists.txt", "ranges", "cmake") }}

<hr>

{{ all_code_snippets("snippets/algorithm/ranges.cpp") }}




