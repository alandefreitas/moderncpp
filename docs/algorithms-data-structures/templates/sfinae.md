# Substitution Failure Is Not An Error

!!!note "Substitution Failure Is Not An Error"

    This [rule](https://en.cppreference.com/w/cpp/language/sfinae) applies during overload resolution of function 
    templates: When substituting the explicitly specified or deduced type for the template parameter fails, the 
    specialization is discarded from the overload set instead of causing a compile error.

    Because the attempted substitution is not an error, SFINAE is used as alternative to concepts in compilers
    that do not support C++20. The technique specifies the template parameters is such a way that only the intended
    template types are instanciated.

{{ all_code_snippets("snippets/templates/sfinae.cpp") }}





