# Async++

!!! note "Async++"

    There have been many proposals to extend the C++ model of futures. Most proposals involve the capability of 
    continuations without polling. One of this proposals is N3428, inspired by the Microsoft PPL library.
    [Async++](https://github.com/Amanieu/asyncplusplus) is a lightweight library that implements the concept.

{{ code_snippet("snippets/parallel/CMakeLists.txt", "asyncplusplus", "cmake") }}

<hr>

{{ all_code_snippets("snippets/parallel/async_pools.cpp") }}




