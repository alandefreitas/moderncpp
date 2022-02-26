# Type deduction

!!!note "Type deduction"

    The `auto` keyword declares a variable whose type is deduced from the initialization expression in its declaration.

    Auto for fundamental data types:

    - Avoid using `auto` for fundamental data types!
      - This is a bad place for `auto`
      - It does not avoid a long type name
      - It creates ambiguity
        - `auto x = 87` could *semantically* be any number type
    - This is somewhat equivalent to:
      - swift:  `var dont_do_that = 87`
      - rust:   `let mut dont_do_that = 87`

    On the other hand, `auto` is very useful in generic functions where there types are not ambiguous.

{{ all_code_snippets("snippets/data_types/auto.cpp") }}




