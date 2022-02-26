# Random

!!!note "Random"

    The [random number library](https://en.cppreference.com/w/cpp/numeric/random) provides classes that generate random
    and pseudo-random numbers. These classes include:

    - Uniform random bit generators (URBGs), which include both random number engines, which are pseudo-random number
      generators that generate integer sequences with a uniform distribution, and true random number generators if 
      available;
    - Random number distributions (e.g. uniform, normal, or poisson distributions) which convert the output of URBGs 
      into various statistical distributions

    URBGs and distributions are designed to be used together to produce random values. All of the random number engines 
    may be specifically seeded, serialized, and deserialized for use with repeatable simulators.

{{ all_code_snippets("snippets/random/random.cpp") }}

