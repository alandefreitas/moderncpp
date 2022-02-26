# Shared from this

!!! note "Shared from this"

    [`std::enable_shared_from_this`](https://en.cppreference.com/w/cpp/memory/enable_shared_from_this) allows an 
    object `t` that is currently managed by a `std::shared_ptr` named `pt` to safely generate additional 
    `std::shared_ptr` instances `pt1`, `pt2`, ... that all share ownership of `t` with `pt`.

    Publicly inheriting from `std::enable_shared_from_this<T>` provides the type `T` with a member function 
    `shared_from_this`. If an object `t` of type `T` is managed by a `std::shared_ptr<T>` named `pt`, then calling 
    `T::shared_from_this` will return a new `std::shared_ptr<T>` that shares ownership of `t` with `pt`.

{{ all_code_snippets("snippets/paradigms/shared_from_this.cpp") }}


