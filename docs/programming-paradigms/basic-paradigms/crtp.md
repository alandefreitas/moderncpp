# Curiously Recurring Template Pattern

!!! note "Curiously Recurring Template Pattern"

    The [Curiously Recurring Template Pattern](https://en.cppreference.com/w/cpp/language/crtp) is an idiom in which
    a class `X` derives from a class template `Y`, taking a template parameter `Z`, where `Y` is instantiated with `Z=X`. 

    CRTP may be used to implement "compile-time polymorphism", when a base class exposes an interface, and derived 
    classes implement such interface.

{{ all_code_snippets("snippets/paradigms/CRTP.cpp") }}


