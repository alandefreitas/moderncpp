# Span

!!! note "Span"

    The class template [`span`](https://en.cppreference.com/w/cpp/container/span) describes an object that can refer 
    to a contiguous sequence of objects with the first element of the sequence at position zero. 

    A span can either have a static extent, in which case the number of elements in the sequence is known at 
    compile-time and encoded in the type, or a dynamic extent.

{{ code_snippet("snippets/data_structures/CMakeLists.txt", "span", "cmake") }}

<hr>

{{ all_code_snippets("snippets/data_structures/span.cpp") }}

     




