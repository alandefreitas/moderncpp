---
layout: default
title: Output
nav_order: 4
has_children: false
parent: Input / Output
grand_parent: Basic Syntax
has_toc: false
---
# Output

{{ all_code_snippets("snippets/input_output/output.cpp") }}

!!! info "Some people told me `std::endl` is evil. Is that true?"

    Introductory snippets usually use `std::endl` instead of `'\n'`, while some guides recommend always using `'\n'`.

    * Flushing with `std::endl` *does* have a [semantic meaning](https://en.cppreference.com/w/cpp/io/manip/flush) 
      different from `'\n`, which is a nice convention for small snippets
    * `std::endl` means "please include a line break in the buffer and show me what's in the output buffer right now"
    * `'\n'` means "please include a line break in the buffer"

    The reason people correctly say that `std::endl` costs more than `'\n'`. But it costs more because it does not do
    the same thing. It exists for a reason. There are [some situations](https://en.cppreference.com/w/cpp/io/manip/flush) 
    where it makes sense to flush the stream. What's important is to be informed about what it does and how much it costs.

    * _When not working with files_, which in the common scenario of introductory snippets, the time difference between
      flushing `std::cout` to the console (not files!) tends to be [negligible](https://github.com/alandefreitas/moderncpp/blob/master/examples/datetime/flushtime.cpp)
    * Almost no application is spending more time flushing than calculating things to flush. Unless it's a
      flushing benchmark.

    On the other hand, some people will simply say `std::endl` is evil, but this is misleading. They are usually 
    generalizing from benchmarks that explore specific edge cases to prove a point. These benchmarks are usually meant
    to show the difference between `'\n'` and `std::endl` and not as proof that `std::endl` is evil per se, or 
    significantly more expensive than `'\n'` in all possible use cases.

    We can't tell you which is better because they do different things. But we can tell you their differences and their
    cost:

    * The definitions:
          * The buffer: The streams usually store the data in a buffer, which is meant to make things more efficient. 
            The buffer reduces the number of trips to their final destination.
          * Flushing: Once the buffer is full, then the data goes to its final destination, which is usually the console
            or a file. For convenience, when that happens, we say the stream is flushing the buffer.
          * Commands: C++ gives you the option to flush what is in the buffer immediately or you might wait for the 
            stream to flush automatically according to some internal heuristic.
          * Automatically flushing: This heuristic is usually when the buffer is full, or when the buffer is about to
            be destructed. Sometimes, it flushes automatically when it sees a new line. That depends on the implementation.
    * What the commands mean: 
          * Flushing does have a semantic meaning different from `'\n'`, and this might be a good convention for some 
            pieces of code, especially when you want to make sure you will see the output immediately, particularly for 
            `std::cout`.
          * `'\n'` means "put a newline in the buffer"
          * `std::flush` means "show me what's in the buffer now"
          * `std::endl` means "put a newline in the buffer and then show me what's in the buffer now"
    * Their cost: 
          * By the definition above, `std::endl` logically costs more than `'\n'` because it's doing what `'\n'` does
            plus one more thing. Some people often use examples and benchmarks flushing files as evidence that 
            `std::endl` is evil per se. But there's a catch here:
          * There's very little reason to flush to files because we don't usually care if the data gets in the file a
            little later.
          * Flushing to files is much more comparatively expensive than flushing to `std::cout`.
          * If you benchmark this difference, you will see the time difference of flushing `std::cout` to the console
            (not files!) is negligible:
              * *GCC -O2: Flush: 2.32234e-06 / Don't Flush: 2.26303e-06*
              * *Clang -O2: Flush: 2.33343e-06 / Don't Flush: 2.23031e-06*
          * Besides this small difference, flushing to console is much more likely to be useful than flushing to a file.
          * Also, this difference is almost certainly smaller in a real application. Almost no application is spending
            more time flushing than _calculating_ things to flush. Unless it's a flushing benchmark like the one above.

    In the end, flushing to a file is almost always a bad idea. Flushing to the console won't probably have any 
    significant impact on performance. In that second case, if not flushing can cause you any problems, just flush.

