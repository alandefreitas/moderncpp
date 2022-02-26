# Smart pointers

!!!note "Smart pointers"

    Use smart pointers instead of raw pointer whenever possible:

    - But you can't do it without understanding raw pointers
    - Recur to raw *non-owning* pointers if they are needed

    In general, use:

    1) No pointers at all
    
    2) Raw non-owning pointers or references if they are needed
    
    3) Smart pointers IF owning pointers can not be averted
    
    4) Owning raw pointers if you know exactly what you are doing
           and need them (e.g. interfacing with C code).

    There are 2 important types of smart pointers:
    
    - Unique pointer: 
        - Only one pointer can point to an address
        - Deletes data automatically when the pointer is destroyed
    - Shared pointer: 
        - More than one pointer can point to the same address
        - Deletes data automatically when the last pointer is destroyed
        - More expensive than unique pointers

{{ all_code_snippets("snippets/pointers/smart_pointers.cpp") }}



