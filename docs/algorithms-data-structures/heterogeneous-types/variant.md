# Variant

!!! note "Variant"

    The class template [`std::variant`](https://en.cppreference.com/w/cpp/utility/variant) (C++17) represents a 
    type-safe union. An instance of `std::variant` at any given time either holds a value of one of its alternative 
    types, or in the case of error - no value.

    If we define a variant `v` including lots of types, including booleans and lists, this would be somewhat similar to:
    
    - PHP:         `$v = 3.14;`    // see https://bit.ly/3cVuJvb
    - Python:      `v = 3.14;`
    - Javascript:  `var v = 3.14;`

    As with unions, if a variant holds a value of some object type `T`, the object representation of `T` is allocated 
    directly within the object representation of the variant itself. Variant is not allowed to allocate additional
    (dynamic) memory.
    
    A variant is not permitted to hold references, arrays, or the type `void`. Empty variants are also ill-formed 
    (std::variant<std::monostate> can be used instead).
    
    A variant is permitted to hold the same type more than once, and to hold differently cv-qualified versions of the same type.
    
    Consistent with the behavior of unions during aggregate initialization, a default-constructed variant holds a value
    of its first alternative, unless that alternative is not default-constructible
    (in which case the variant is not default-constructible either). The helper class `std::monostate` can be used 
    to make such variants default-constructible.

{{ all_code_snippets("snippets/heterogeneous_types/variant.cpp") }}




