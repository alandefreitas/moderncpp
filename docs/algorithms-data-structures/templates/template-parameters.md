# Template Parameters

!!!note "Template Parameters"

    A template defines a family of functions and classes. A template by itself is not a type, or a function, or 
    any other entity. No code is generated from a source file that contains only template definitions. 

    In order for any code to appear, a template must be instantiated: the template arguments must be determined so 
    that the compiler can generate an actual function (or class, from a class template).

    Templates allow us to reuse the logic of algorithms for different data types. Without templates, our alternative
    for generic algorithms would be type erasing types.

{{ all_code_snippets("snippets/templates/template_functions.cpp") }}



