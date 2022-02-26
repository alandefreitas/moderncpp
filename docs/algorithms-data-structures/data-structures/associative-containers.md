# Associative Containers

!!! note "Associative Containers"

    [Associative containers](https://en.cppreference.com/w/cpp/container) implement sorted data structures that can
    be quickly searched (O(log n) complexity. They are usually implemented as binary trees.

    - set: collection of unique keys, sorted by keys
    - map: collection of key-value pairs, sorted by keys, keys are unique
    - multiset: collection of keys, sorted by keys
    - multimap: collection of key-value pairs, sorted by keys

    [Unordered associative containers](https://en.cppreference.com/w/cpp/container) implement unsorted (hashed) data 
    structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity). They are usually implemented
    as hash tables.

    - unordered_set (C++11): collection of unique keys, hashed by keys
    - unordered_map (C++11): collection of key-value pairs, hashed by keys, keys are unique
    - unordered_multiset (C++11): collection of keys, hashed by keys
    - unordered_multimap (C++11): collection of key-value pairs, hashed by keys

{{ all_code_snippets("snippets/data_structures/associative_containers.cpp") }}




