# Metaprogramming

!!!note "Metaprogramming"

    [Template metaprogramming](https://en.cppreference.com/w/cpp/language/template_metaprogramming) is a family of
    techniques to create new types and compute values at compile time. C++ templates are Turing complete if there are
    no limits to the amount of recursive instantiations and the number of allowed state variables. 

    Erwin Unruh was the first to demonstrate template metaprogramming at a committee meeting by instructing the 
    compiler to print out prime numbers in error messages. The standard recommends an implementation support at least
    1024 levels of recursive instantiation, and infinite recursion in template instantiations is undefined behavior.

{{ all_code_snippets("snippets/templates/metaprogramming.cpp") }}
