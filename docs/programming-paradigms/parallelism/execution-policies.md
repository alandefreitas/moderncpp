# Execution Policies

!!! note "Execution Policies"

    Most algorithms have overloads that accept [execution policies](https://en.cppreference.com/w/cpp/algorithm). The 
    standard library algorithms support several execution policies, and the library provides corresponding execution
    policy types and objects. Users may select an execution policy statically by invoking a parallel algorithm with
    an execution policy object of the corresponding type.

{{ code_snippet("snippets/parallel/CMakeLists.txt", "policies", "cmake") }}

<hr>

{{ all_code_snippets("snippets/parallel/policies.cpp") }}




