# Quickstart

## Why C++

C++ has always been a great language for Scientific Computing, High-Performance Computing, and Data Analysis:

* Most programmers are familiar with its basic syntax;
* It's been among the most popular languages over last 40 years;
* Access to hundreds of thousands of high-performance libraries;
* Performance
  level [almost no other language](http://tempesta-tech.com/blog/fast-programming-languages-c-cpp-rust-assembly) can
  achieve;
* Complex abstractions with [zero-overhead](https://en.cppreference.com/w/cpp/language/Zero-overhead_principle);
* [Easy access to parallelism](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t);
* [Numerous compilers](https://www.stroustrup.com/compilers.html) with
  great [optimization](https://queue.acm.org/detail.cfm?id=3372264) options available;
* Innumerable target platforms, from [microcontrollers](https://www.arduino.cc),
  to [GPUs](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html),
  to [mobile](https://github.com/leetal/ios-cmake), to [webassembly](https://emscripten.org);
* Does not rely on any virtual machine;
* Easy bindings from/to virtually any other programming language ([Python](https://github.com/pybind/pybind11)
  , [Javascript](https://github.com/Chobolabs/jsbind), [PHP](http://www.php-cpp.com), [R](http://www.rcpp.org)
  , [Java](https://www.baeldung.com/jni), [Matlab](https://www.mathworks.com/solutions/matlab-and-c.html)
  , [Rust](https://rust-lang.github.io/rust-bindgen/cpp.html)
  , [Swift](https://medium.com/@anuragajwani/how-to-consume-c-code-in-swift-b4d64a04e989)
  , [Julia](https://github.com/JuliaInterop/CxxWrap.jl), [C](https://isocpp.org/wiki/faq/mixing-c-and-cpp), ... you name
  it);
* Great tools for [static analysis](https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis#C,_C++) to
  avoid bugs;
* Avoids the [two-languages problem](https://www.quora.com/What-is-the-2-language-problem-in-data-science) in scientific
  computing: one for prototyping and one to reimplement all the work once the experiments are successful;
* No need for special licenses to distribute your compiled code, like it is common in technical languages that rely on
  virtual machines;
* Allows saving tons of money and extra-security for applications to be run in the cloud or dedicated servers.

<br/>

## Why Modern C++

Many people have move from C++ over the last decade and might not be aware that the Modern C++ ecosystem has evolved to
cover almost all use cases that made C++ inconvenient for certain tasks in the past:

* Efficient [interpreters](https://cling.web.cern.ch) with beautiful [IDEs](http://xeus-cling.readthedocs.io);
* Cross-platform [build systems](http://cmake.org), including [microcontrollers](https://www.arduino.cc)
  , [GPUs](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html)
  , [mobile](https://github.com/leetal/ios-cmake) and [webassembly](https://emscripten.org);
* [Package managers](http://conan.io);
* [Type deduction](https://en.cppreference.com/w/cpp/language/auto);
* [Variant types](https://en.cppreference.com/w/cpp/header/variant);
* [Types for optional data](https://en.cppreference.com/w/cpp/utility/optional);
* Cheap automatic memory management via [smart pointers](https://en.cppreference.com/w/cpp/memory/shared_ptr);
* Numerous [data structures](https://en.cppreference.com/w/cpp/container) out of the box;
* [Modules](https://en.cppreference.com/w/cpp/language/modules);
* [Concepts](https://en.cppreference.com/w/cpp/language/constraints);
* [Functional programming](https://en.cppreference.com/w/cpp/language/lambda);
* Convenient [meta programming](https://www.modernescpp.com/index.php/c-core-guidelines-programming-at-compile-time-with-constexpr);
* [Structured bindings](https://en.cppreference.com/w/cpp/language/structured_binding)
  and [tuples](https://en.cppreference.com/w/cpp/utility/tuple);
* [Ranges](https://en.cppreference.com/w/cpp/ranges);
* [Move semantics](https://en.cppreference.com/w/cpp/language/move_assignment).

By incentivizing and highlighting
modern [C++ features in instructional content](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-160)
, it's also possible to combine the familiar syntax of C and old C++ to achieve high levels of abstraction with a gentle
learning curve.

## How this repository works

### Snippets

* The [`snippets`](https://github.com/alandefreitas/moderncpp/blob/master/snippets/CMakeLists.txt) directory has lots of
  short programs with useful C++ snippets
* [GitHub actions](https://github.com/alandefreitas/moderncpp/actions?query=workflow%3ABuild) ensures all snippets are
  working on GCC, MSVC, and Clang.
* We generate GitHub pages with all snippets by groups of tasks

<br/>

### Libraries

We give preference to libraries in this order:

1. Libraries [supported](https://en.cppreference.com/w/cpp/compiler_support) by most C++ compilers
2. Libraries [accepted](https://timsong-cpp.github.io/cppwp/n4861/) into the C++ standard
3. Libraries [likely to be accepted](https://eel.is/c++draft/) into the next C++ standard
4. Libraries representative of existing practice

### External Libraries

For external libraries, we also include a short CMake snippet in the build script with:

* [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) to find, setup, and link the large
  external libraries
* [`FetchContents`](https://cmake.org/cmake/help/latest/module/FetchContent.html) to download, build, and link the
  external library

### Snippets and Examples

Examples are often long and don't represent independent tasks you can copy and paste. Snippets represent independent
tasks you can copy and paste.

_Why not get my snippets directly from `cppreference` or `cplusplus.com`?_

`cppreference` is not meant for snippets and this repository is not meant to be a reference for the C++ standard. Some
implications are:

* The snippets:
    * Meant to list the commands you most often need in a library.
    * Lots of independent tasks for copying and pasting
    * Include corresponding build scripts when something more complex is required
    * Include external libraries when it's existing practice
    * Organized roughly in the order someone learning C++ might need them
* The examples in cppreference or cplusplus.com:
    * Meant to make points about the internals of the libraries.
    * A single task meant to prove a point
    * Has nothing to do with build scripts
    * Has nothing to do with external libraries
    * Might mix simple and complex concepts to make a point

### GitHub Pages

We generate GitHub pages with all snippets:

* The GitHub pages are generated with [mkdocs material](https://squidfunk.github.io/mkdocs-material/)
* Snippets are categorized by groups of tasks
* Sections are easy to explore, copy, and paste

