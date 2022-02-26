# Memory resources

!!! note "Memory resources"

    The class std::pmr::memory_resource is an abstract interface to an unbounded set of classes encapsulating memory 
    resources. The class template [std::pmr::polymorphic_allocator](https://en.cppreference.com/w/cpp/memory/polymorphic_allocator)
    is an `Allocator` which exhibits different allocation behavior depending upon the std::pmr::memory_resource from 
    which it is constructed. This allows us to control how a given container allocates memory. 

    Since memory_resource uses runtime polymorphism to manage allocations, different container instances 
    with polymorphic_allocator as their static allocator type are interoperable, but can behave as if they had 
    different allocator types.

    Not all compilers implement PMR yet, even though it's a C++17 feature. We need a CMake script such as 
    [`FindPMR.cmake`](https://github.com/alandefreitas/moderncpp/blob/master/cmake/FindPMR.cmake) to identify if your 
    compiler implements it. Another option is using [`__has_include`](https://en.cppreference.com/w/cpp/preprocessor/include)
    to identify if the appropriate headers are available.

{{ code_snippet("snippets/data_structures/CMakeLists.txt", "pmr", "cmake") }}

<hr>

{{ all_code_snippets("snippets/data_structures/memory_resources.cpp") }}

     




