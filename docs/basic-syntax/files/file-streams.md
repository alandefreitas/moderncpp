# File streams

!!!note "File streams"

    C++ provides file streams to perform output and input of characters to/from files. These classes are derived
    directly or indirectly from the classes std::istream and std::ostream. 

    We have already used objects whose types were these classes: `std::cin` is an object of class `std::istream` and 
    `std::cout` is an object of class ostream. 

    We can use our file streams the same way we are already used to use `std::cin` and `std::cout`, with the only 
    difference that we have to associate these streams with physical files.:

{{ all_code_snippets("snippets/files/files.cpp") }}


