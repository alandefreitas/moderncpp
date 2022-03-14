# Lyra

!!! note "Lyra"

    [Lyra](https://github.com/bfgroup/Lyra) is a simple to use, composable, command line parser
    for C++ 11 and beyond.

    It provides type conversions, composable parsers, variable binding, custom handling, error
    handling, options with multiple values, error propagation without exceptions, short and long
    option handlers, enumerations, argument cardinality, argument groups, and sub-commands.

{{ code_snippet("snippets/utilities/CMakeLists.txt", "find_lyra", "cmake") }}

<hr>

{{ code_snippet("snippets/utilities/CMakeLists.txt", "link_lyra", "cmake") }}

<hr>

{{ all_code_snippets("snippets/utilities/lyra_cli.cpp") }}

