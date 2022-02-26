# PCG

!!!note "PCG"

    The [PCG library](https://www.pcg-random.org/) provides a number of better random number generators.

    The library has a interface that resembles standard C++ number generators with generators that:
    
    - Do not fail statistical tests for randomness 
    - Ensure unpredictability and safety 
    - Are fast and don't require large amounts of memory 
    - Provide useful features such as "jump ahead" 

{{ code_snippet("snippets/random/CMakeLists.txt", "pcg", "cmake") }}

<hr>

{{ all_code_snippets("snippets/random/pcg.cpp") }}

