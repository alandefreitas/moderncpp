# Regex

!!! note "Regex"

    The [regular expressions library](https://en.cppreference.com/w/cpp/regex) provides a class that represents 
    regular expressions, which are a kind of mini-language used to perform pattern matching within strings.

    The regex library was originally developed as 
    [boost.regex](https://www.boost.org/doc/libs/1_78_0/libs/regex/doc/html/index.html), was published as the 
    technical specification [ISO/IEC DTR 19768](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1836.pdf),
    and finally merged to ISO C++ as of C++11. 

    The boost implementation is currently available on more compilers and platforms than the C++17 library. It 
    typically also provides better performance than the standard implementations.


{{ all_code_snippets("snippets/utilities/regex.cpp") }}

