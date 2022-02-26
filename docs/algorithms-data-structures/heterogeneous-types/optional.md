# Optional

!!! note "Optional"

    The class template [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional) manages an optional 
    contained value, i.e. a value that may or may not be present.

    A common use case for optional is the return value of a function that may fail. As opposed to other approaches, 
    such as std::pair<T,bool>, optional handles expensive-to-construct objects well and is more readable, as the intent
    is expressed explicitly.

    Any instance of `optional<T>` at any given point in time either contains a value or does not contain a value.

{{ all_code_snippets("snippets/heterogeneous_types/optional.cpp") }}




