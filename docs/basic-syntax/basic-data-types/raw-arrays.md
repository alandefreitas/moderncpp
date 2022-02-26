# Raw arrays

!!!note "Raw arrays"

    An array is a sequence of objects of the same type that occupy a contiguous area of memory. 

    Traditional C-style arrays, or Raw Arrays, are the source of many bugs, but are still common, especially in older
    code bases. 

    In modern C++, we strongly recommend using `std::vector` or `std::array` instead of C-style arrays.

{{ all_code_snippets("snippets/basic_types/raw_arrays.cpp") }}







