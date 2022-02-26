# Datetime

!!!note "Datetime"

    C++20 includes [date and time utilities](https://en.cppreference.com/w/cpp/chrono) in the chrono library.

    These utilities were originally developed as the [date](https://github.com/HowardHinnant/date) library,
    and were finally merged to ISO C++ as of C++20. 

    date.h contains chrono extensions to deal with dates:
    - https://howardhinnant.github.io/date/date.html
    - https://howardhinnant.github.io/date/tz.html

    The date library implementation is currently available on more compilers and platforms than the C++20 library.

{{ code_snippet("snippets/datetime/CMakeLists.txt", "datetime", "cmake") }}

<hr>

{{ all_code_snippets("snippets/datetime/datetime.cpp") }}

