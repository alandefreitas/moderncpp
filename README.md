# Modern C++: Snippets and Examples

> GitHub Pages with snippets for Modern C++

<!-- START mdsplit-ignore -->
[![](docs/img/banner.png)](https://alandefreitas.github.io/moderncpp/)
<!-- END mdsplit-ignore -->

<br/>

* We often need to copy and paste some snippets to code more productively. 
* Snippets can help us when it's not easy to remember all high levels features Modern C++ has to offer. 
* This repository contains lots of organized, reusable, and safe snippets for Modern C++.
* All snippets are available in [GitHub pages](https://alandefreitas.github.io/moderncpp/) in a convenient way for copying and pasting.

<br/>

<!-- START mdsplit-ignore -->

<h2>

[EXPLORE THE SNIPPETS HERE](https://alandefreitas.github.io/moderncpp/)

</h2>

<!-- END mdsplit-ignore -->

<br/>

<!-- https://github.com/bradvin/social-share-urls -->
[![Facebook](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+Facebook&logo=facebook)](https://www.facebook.com/sharer/sharer.php?t=ModernCpp%20Snippets%20and%20Examples&u=https://github.com/alandefreitas/moderncpp/)
[![QZone](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+QZone&logo=qzone)](http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?url=https://github.com/alandefreitas/moderncpp/&title=ModernCpp%20Snippets%20and%20Examples&summary=ModernCpp%20Snippets%20and%20Examples)
[![Weibo](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+Weibo&logo=sina-weibo)](http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?url=https://github.com/alandefreitas/moderncpp/&title=ModernCpp%20Snippets%20and%20Examples&summary=ModernCpp%20Snippets%20and%20Examples)
[![Reddit](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+Reddit&logo=reddit)](http://www.reddit.com/submit?url=https://github.com/alandefreitas/moderncpp/&title=ModernCpp%20Snippets%20and%20Examples)
[![Twitter](https://img.shields.io/twitter/url/http/shields.io.svg?label=Share+on+Twitter&style=social)](https://twitter.com/intent/tweet?text=ModernCpp%20Snippets%20and%20Examples&url=https://github.com/alandefreitas/moderncpp/&hashtags=Cpp,Snippets,ModernCpp,ScientificComputing,Examples,Developers)
[![LinkedIn](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+LinkedIn&logo=linkedin)](https://www.linkedin.com/shareArticle?mini=false&url=https://github.com/alandefreitas/moderncpp/&title=ModernCpp%20Snippets%20and%20Examples)
[![WhatsApp](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+WhatsApp&logo=whatsapp)](https://api.whatsapp.com/send?text=ModernCpp%20Snippets%20and%20Examples:+https://github.com/alandefreitas/moderncpp/)
[![Line.me](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+Line.me&logo=line)](https://lineit.line.me/share/ui?url=https://github.com/alandefreitas/moderncpp/&text=ModernCpp%20Snippets%20and%20Examples)
[![Telegram.me](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+Telegram.me&logo=telegram)](https://telegram.me/share/url?url=https://github.com/alandefreitas/moderncpp/&text=ModernCpp%20Snippets%20and%20Examples)
[![HackerNews](https://img.shields.io/twitter/url/http/shields.io.svg?style=social&label=Share+on+HackerNews&logo=y-combinator)](https://news.ycombinator.com/submitlink?u=https://github.com/alandefreitas/moderncpp/&t=ModernCpp%20Snippets%20and%20Examples)

<br/>


<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
<details>
<summary>Table of Contents</summary>

- [Quick Start](#quick-start)
- [Basic Syntax](#basic-syntax)
  - [Input / Output](#input--output)
  - [Control flow](#control-flow)
  - [Data types](#data-types)
  - [Basic Data Types](#basic-data-types)
  - [Pointers](#pointers)
  - [Functions](#functions)
  - [Files](#files)
- [Algorithms / Data Structures](#algorithms--data-structures)
  - [Date and time](#date-and-time)
  - [Random](#random)
  - [Template](#template)
  - [Algorithm](#algorithm)
  - [Data structures](#data-structures)
  - [Heterogeneous Types](#heterogeneous-types)
- [Programming Paradigms](#programming-paradigms)
  - [Basic Paradigms](#basic-paradigms)
  - [Parallelism](#parallelism)
- [Utilities](#utilities)
  - [Regular Expressions](#regular-expressions)
  - [Networking](#networking)
- [GUIs](#guis)
  - [Build script](#build-script)
  - [Qt](#qt)
  - [OpenGL + SDL](#opengl--sdl)
  - [OpenGL + GLFW](#opengl--glfw)
  - [IMGUI](#imgui)
  - [Webview](#webview)
  - [System tray](#system-tray)
- [Testing](#testing)
  - [Build script](#build-script-1)
  - [Catch2](#catch2)
  - [boost.ut](#boostut)
  - [Source Location](#source-location)
  - [Plots](#plots)
- [CMake functions](#cmake-functions)
- [Installing a C++20 compiler](#installing-a-c20-compiler)
  - [Linux](#linux)
  - [Mac OS](#mac-os)
  - [Windows](#windows)
- [FAQ](#faq)
- [Get involved](#get-involved)

</details>
<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Quick Start

This is how this repository works:

* The [`snippets`](./snippets/CMakeLists.txt) directory has lots of short programs with useful C++20 snippets
* The [`examples`](./examples/CMakeLists.txt) directory has lots of short tasks using these snippets
* [GitHub actions](https://github.com/alandefreitas/moderncpp/actions?query=workflow%3ABuild) ensures all snippets are working on GCC, MSVC, and Clang
* We generate GitHub pages with all snippets by groups of tasks using [mkdocs material](https://squidfunk.github.io/mkdocs-material/) and [mdsplit](https://alandefreitas.github.io/mdsplit/)

<br/>

**Libraries**

We give preference to libraries in this order:

1. Libraries [supported](https://en.cppreference.com/w/cpp/compiler_support) by most C++ compilers
2. Libraries [accepted](https://timsong-cpp.github.io/cppwp/n4861/) into the C++ standard
3. Libraries [likely to be accepted](https://eel.is/c++draft/) into the next C++ standard
4. Libraries representative of existing practice

<br/>

**External Libraries**

For external libraries, we also include a short CMake snippet in the build script with:

* [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) to find, setup, and link the large external libraries
* [`FetchContents`](https://cmake.org/cmake/help/latest/module/FetchContent.html) to download, build, and link the external library

<br/>

**Snippets and Examples**

The snippets, as they are, might seem like they are examples in the sense that they are in long files sometimes. What makes them snippets is that, at the source file level, they represent lots of independent short tasks separated by comments. Unlike in the examples, the tasks separated by comments are unrelated. You can just copy and paste the snippets between pairs of comments.

<br/>

**GitHub Pages**

We generate GitHub pages with all snippets:

* The GitHub pages are generated with [mkdocs material](https://squidfunk.github.io/mkdocs-material/) and [mdsplit](https://alandefreitas.github.io/mdsplit/)
* Snippets organized are categorized by groups of tasks
* Sections are easy to explore, copy, and paste

<br/>

**Why use C++20**

C++ has always been a great language for Scientific Computing, High-Performance Computing, and Data Analysis:

* Most programmers are familiar with its basic syntax; 
* It's been among the most popular languages over last 40 years; 
* Access to hundreds of thousands of high-performance libraries; 
* Performance level [almost no other language](http://tempesta-tech.com/blog/fast-programming-languages-c-cpp-rust-assembly) can achieve; 
* Complex abstractions with [zero-overhead](https://en.cppreference.com/w/cpp/language/Zero-overhead_principle); 
* [Easy access to parallelism](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t); 
* [Numerous compilers](https://www.stroustrup.com/compilers.html) with great [optimization](https://queue.acm.org/detail.cfm?id=3372264) options available; 
* Innumerable target platforms, from [microcontrollers](https://www.arduino.cc), to [GPUs](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html), to [mobile](https://github.com/leetal/ios-cmake), to [webassembly](https://emscripten.org); 
* Does not rely on any virtual machine; 
* Easy bindings from/to virtually any other programming language _([Python](https://github.com/pybind/pybind11), [Javascript](https://github.com/Chobolabs/jsbind), [PHP](http://www.php-cpp.com), [R](http://www.rcpp.org), [Java](https://www.baeldung.com/jni), [Matlab](https://www.mathworks.com/solutions/matlab-and-c.html), [Rust](https://rust-lang.github.io/rust-bindgen/cpp.html), [Swift](https://medium.com/@anuragajwani/how-to-consume-c-code-in-swift-b4d64a04e989), [Julia](https://github.com/JuliaInterop/CxxWrap.jl), [C](https://isocpp.org/wiki/faq/mixing-c-and-cpp), ... you name it); 
* Great tools for [static analysis](https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis#C,_C++) to avoid bugs; 
* Avoids the [two-languages problem](https://www.quora.com/What-is-the-2-language-problem-in-data-science) in scientific computing: one for prototyping and one to reimplement all the work once the experiments are successful;
* No need for special licenses to distribute your compiled code, like it is common in technical languages that rely on virtual machines; 
* Allows saving tons of money and extra-security for applications to be run in the cloud or dedicated servers.

<br/>

**Why use Modern C++**

Many people have move from C++ over the last decade and might not be aware that the Modern C++ ecosystem has evolved to cover almost all use cases that made C++ inconvenient for certain tasks in the past: 

* Efficient [interpreters](https://cling.web.cern.ch) with beautiful [IDEs](http://xeus-cling.readthedocs.io); 
* Cross-platform [build systems](http://cmake.org), including [microcontrollers](https://www.arduino.cc), [GPUs](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html), [mobile](https://github.com/leetal/ios-cmake) and [webassembly](https://emscripten.org); 
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
* [Structured bindings](https://en.cppreference.com/w/cpp/language/structured_binding) and [tuples](https://en.cppreference.com/w/cpp/utility/tuple); 
* [Ranges](https://en.cppreference.com/w/cpp/ranges); 
* [Move semantics](https://en.cppreference.com/w/cpp/language/move_assignment). 
  
By incentivizing and highlighting modern [C++ features in instructional content](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-160), it's also possible to combine the familiar syntax of C and old C++ to achieve high levels of abstraction with a gentle learning curve.

## Installing C++20

### Linux / GCC

Many operating systems don't come with a C++20 compiler by default. Follow these instructions to install C++20.

Update GCC:

```bash
sudo apt install build-essential
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt install gcc-10
sudo apt install g++-10
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10
```

Set your default compiler with:

```bash
update-alternatives --config g++
```

### Mac OS / Clang

Many operating systems don't come with a C++20 compiler by default. Follow these instructions to install C++20.

Download a [recent version](https://releases.llvm.org/download.html) of Clang.

```bash
curl --output clang.tar.xz -L https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
mkdir clang
tar -xvJf clang.tar.xz -C clang
```

Copy the files to `usr/local/`:

```bash
cd clang/clang+llvm-11.0.0-x86_64-apple-darwin
sudo cp -R * /usr/local/
```

Let CMake know that's the compiler you want to use.

If you want this to be your default compiler, you can set the `CXX` environment variable:

```bash
export CXX=/usr/local/bin/clang++
```

If you want to use this compiler in a single project, run CMake with these options:

```bash
-DCMAKE_C_COMPILER=/usr/local/bin/clang -DCMAKE_CXX_COMPILER=/usr/local/bin/clang++
```

Or tell you IDE to pass these options to CMake:

![](docs/img/set_compiler.png)

### Windows / MSVC

Many operating systems don't come with a C++20 compiler by default. Follow these instructions to install C++20.

Update your [Visual Studio](https://visualstudio.microsoft.com) Compiler.

The most recent version of Visual Studio should include C++20.

!!! warning "Help wanted"
We still don't know of a script for installing C++20 on Windows from the terminal.

    This would be especially useful for our [build workflow](./.github/workflows/build.yml), which has not been testing MSVC since we moved to C++20.

    Please let us know or open a PR if you know of such a script.

### WebAssembly / Emscripten

If you are programming for the web, a common option for C++ and WebAssembly is [emscripten](https://emscripten.org/docs/getting_started/index.html).

You can install emscripten from most package managers for [Windows](https://chocolatey.org/packages/emscripten), [Linux](https://pkgs.org/search/?q=emscripten), or [Mac OS](https://formulae.brew.sh/formula/emscripten). You can also follow the [instructions](https://emscripten.org/docs/getting_started/downloads.html) on their website to build from source.

Then follow [these instructions](https://emscripten.org/docs/getting_started/Tutorial.html) to compile your first "Hello World!" for the web.

### Interpreter / Cling

If you are using C++ for scientific computing or learning C++, it's often useful to have a C++ interpreter for short experiments.

You can install Cling from most package managers for [Linux](https://pkgs.org/download/cling) or [Mac OS](https://formulae.brew.sh/formula/cling). You can also follow the [instructions](https://root.cern/cling/cling_build_instructions/) on their website to download the binaries or to build it from source.

Although you can use `cling` directly, it is much more convenient to use the interpreter as a Jupyter notebook kernel. You can follow [these instructions](https://jupyter.org/install.html) to install Jupyter Lab, and [these instructions](https://xeus-cling.readthedocs.io/en/latest/installation.html) to install the `xeus-cling` kernel.

### IDEs

These are the IDEs and text editors [mostly commonly used](http://blog.davidecoppola.com/2018/02/market-share-most-used-c-cpp-ides-in-2018-statistics-estimates/) for C++ programming:

| IDE or Text Editor | Users | Notes             |
|--------------------|-------|-------------------|
| Visual Studio      | 28%   | Windows           |
| Vim                | 17%   | (Text Editor)     |
| Qt Creator         | 12%   | Best for Qt Users |
| Visual Studio Code | 10%   |                   |
| CLion              | 9%    |                   |
| Emacs              | 7%    | (Text Editor)     |
| Xcode              | 4%    | Mac OS            |
| Eclipse            | 4%    |                   |
| Others             | 9%    |                   |

!!! warning
    These numbers are constantly changing.

## Basic Syntax

### Input / Output

#### Build script

```cmake
--8<-- "snippets/input_output/CMakeLists.txt"
```

#### Hello World

```cpp
--8<-- "snippets/input_output/hello_world.cpp"
```

#### Input

```cpp
--8<-- "snippets/input_output/cin.cpp"
```

#### Output

```cpp
--8<-- "snippets/input_output/printing.cpp"
```

Related examples:

* [`examples/datetime/flushtime.cpp`](examples/datetime/flushtime.cpp)

!!! info "Some people told me `std::endl` is evil. Is that true?"

    The reason people say that is because std::endl costs more than `'\n'`. But it costs more because it does not do the same thing. It exists for a reason. There are [some situations](https://en.cppreference.com/w/cpp/io/manip/flush) where it makes sense to flush the stream.

    On the other hand, some people will simply say `std::endl` is evil, but this is a little misleading. They are usually generalizing from benchmarks that explore specific edge cases to prove a point. These benchmarks are usually meant to show the difference between `'\n'` and `std::endl` and not as proof that `std::endl` is evil per se, or significantly more expensive than `'\n'` in all possible use cases.

    In the end, I can't tell which is always better because they do different things. But I can tell you their differences and their cost. So here are some differences:

    * The definitions:
    
        * The buffer: The streams usually store the data in a buffer, which is meant to make things more efficient. The buffer reduces the number of trips to their final destination.
    
        * Flushing: Once the buffer is full, then the data goes to its final destination, which is usually the console or a file. For convenience, when that happens, we say the stream is flushing the buffer.

        * Commands: C++ gives you the option to flush what is in the buffer immediately or you might wait for the stream to flush automatically according to some internal heuristic.

        * Automatically flushing: This heuristic is usually when the buffer is full, or when the buffer is about to be destructed. Sometimes, it flushes automatically when it sees a new line. That depends on the kind of stream.

    * What the commands mean: Flushing does have a semantic meaning different from `'\n'`, and this might be a good convention for some pieces of code, especially when you want to make sure you will see the output immediately. Particularly for `std::cout`:
        * `'\n'` means "put a newline in the buffer"
        * `std::flush` means "show me what's in the buffer now"
        * `std::endl` means "put a newline in the buffer and then show me what's in the buffer now"
    * Their cost: By the definition above, std::endl logically costs more than `'\n'` because it's doing what `'\n'` does plus one more thing. Some people often use examples and benchmarks flushing files often as evidence that `std::endl` is evil per se. But there's a catch here:
        * There's very little reason to flush to files because we don't usually care if the data gets in the file a little later.
        * Flushing to files is much more comparatively expensive than flushing to `std::cout`.
        * If you benchmark this difference, you will see the time difference of flushing std::cout to the console (not files!) is negligible:
            * *GCC -O2: Flush: 2.32234e-06 / Don't Flush: 2.26303e-06*
            * *Clang -O2: Flush: 2.33343e-06 / Don't Flush: 2.23031e-06*
        * Besides this small difference flushing to console is much more likely to be useful than flushing to a file.
        * Also, this difference is almost certainly even smaller in a real application. Almost no application is spending more time flushing than calculating things to flush. Unless it's a flushing benchmark like the one above.

    In the end, flushing to a file is almost always a bad idea. Flushing to the console won't probably have any significant impact. In that second case, if not flushing can cause you any problems, just flush.


#### Format

```cpp
--8<-- "snippets/input_output/format.cpp"
```

#### Tabulate

```cpp
--8<-- "snippets/input_output/tabulate.cpp"
```

### Control flow

#### Build script

```cmake
--8<-- "snippets/control_flow/CMakeLists.txt"
```

#### Sequential

```cpp
--8<-- "snippets/control_flow/sequential.cpp"
```

#### Conditional

```cpp
--8<-- "snippets/control_flow/conditional.cpp"
```

#### Loops

```cpp
--8<-- "snippets/control_flow/loops.cpp"
```

### Data types

#### Build script

```cmake
--8<-- "snippets/data_types/CMakeLists.txt"
```

#### Fundamental Data Types

```cpp
--8<-- "snippets/data_types/data_types.cpp"
```

#### Operators

```cpp
--8<-- "snippets/data_types/operators.cpp"
```

#### Auto

```cpp
--8<-- "snippets/data_types/auto.cpp"
```

#### Constants

```cpp
--8<-- "snippets/data_types/constants.cpp"
```

### Basic Data Types

#### Build script

```cmake
--8<-- "snippets/basic_types/CMakeLists.txt"
```

#### Raw arrays

```cpp
--8<-- "snippets/basic_types/raw_arrays.cpp"
```

#### Arrays

```cpp
--8<-- "snippets/basic_types/arrays.cpp"
```

#### Vectors

```cpp
--8<-- "snippets/basic_types/vectors.cpp"
```

#### Strings

```cpp
--8<-- "snippets/basic_types/strings.cpp"
```

#### Move

```cpp
--8<-- "snippets/basic_types/move.cpp"
```

#### Aggregate initialization

```cpp
--8<-- "snippets/basic_types/aggregate_initialization.cpp"
```

#### Structured binding

```cpp
--8<-- "snippets/basic_types/structured_binding.cpp"
```

### Pointers

#### Build script

```cmake
--8<-- "snippets/pointers/CMakeLists.txt"
```

#### Raw Pointers

```cpp
--8<-- "snippets/pointers/raw_pointers.cpp"
```

#### Smart pointers

```cpp
--8<-- "snippets/pointers/smart_pointers.cpp"
```

### Functions

#### Build script

```cmake
--8<-- "snippets/functions/CMakeLists.txt"
```

#### Function

```cpp
--8<-- "snippets/functions/functions.cpp"
```

Related examples:

* [`examples/functions/recursive_bench.cpp`](examples/functions/recursive_bench.cpp)

#### Lambda

```cpp
--8<-- "snippets/functions/lambda.cpp"
```

### Files

#### Build script

```cmake
--8<-- "snippets/files/CMakeLists.txt"
```

FindFilesystem.cmake:

```cmake
--8<-- "cmake/FindFilesystem.cmake"
```

#### File streams

```cpp
--8<-- "snippets/files/files.cpp"
```

#### Filesystem

```cpp
--8<-- "snippets/files/filesystem.cpp"
```

## Algorithms / Data Structures

### Date and time

#### Build script

```cmake
--8<-- "snippets/datetime/CMakeLists.txt"
```

#### Clock

```cpp
--8<-- "snippets/datetime/clock.cpp"
```

Related examples:

* [`examples/datetime/flushtime.cpp`](examples/datetime/flushtime.cpp)

#### Datetime

```cpp
--8<-- "snippets/datetime/datetime.cpp"
```

### Random

#### Build script

```cmake
--8<-- "snippets/random/CMakeLists.txt"
```

#### Random

```cpp
--8<-- "snippets/random/random.cpp"
```

#### PCG

```cpp
--8<-- "snippets/random/pcg.cpp"
```

### Template

#### Build script

```cmake
--8<-- "snippets/templates/CMakeLists.txt"
```

#### Template function

```cpp
--8<-- "snippets/templates/template_functions.cpp"
```

#### Template aliases

```cpp
--8<-- "snippets/templates/template_alias.cpp"
```

#### Concepts

```cpp
--8<-- "snippets/templates/concepts.cpp"
```

FindConcepts.cmake:

```cmake
--8<-- "cmake/FindConcepts.cmake"
```

#### SFINAE

```cpp
--8<-- "snippets/templates/sfinae.cpp"
```


### Algorithm

#### Build script

```cmake
--8<-- "snippets/algorithm/CMakeLists.txt"
```

#### Searching

```cpp
--8<-- "snippets/algorithm/searching.cpp"
```

#### Sorting

```cpp
--8<-- "snippets/algorithm/sorting.cpp"
```

#### Basic Algorithms

```cpp
--8<-- "snippets/algorithm/algorithms.cpp"
```

#### Ranges

```cpp
--8<-- "snippets/algorithm/ranges.cpp"
```

### Data structures

#### Build script

```cmake
--8<-- "snippets/data_structures/CMakeLists.txt"
```

#### Sequential Containers

```cpp
--8<-- "snippets/data_structures/sequential_containers.cpp"
```

#### Associative Containers

```cpp
--8<-- "snippets/data_structures/associative_containers.cpp"
```

#### Memory resource

```cpp
--8<-- "snippets/data_structures/memory_resource.cpp"
```

FindPMR.cmake:

```cmake
--8<-- "cmake/FindPMR.cmake"
```

#### Span

```cpp
--8<-- "snippets/data_structures/span.cpp"
```

#### Bitset

```cpp
--8<-- "snippets/data_structures/bitset.cpp"
```

#### Spatial Containers

```cpp
--8<-- "snippets/data_structures/spatial_containers.cpp"
```

### Heterogeneous Types

#### Build script

```cmake
--8<-- "snippets/heterogeneous_types/CMakeLists.txt"
```

#### Tuples

```cpp
--8<-- "snippets/heterogeneous_types/tuples.cpp"
```

#### Any

```cpp
--8<-- "snippets/heterogeneous_types/any.cpp"
```

#### Optional

```cpp
--8<-- "snippets/heterogeneous_types/optional.cpp"
```

#### Variant

```cpp
--8<-- "snippets/heterogeneous_types/variant.cpp"
```

## Programming Paradigms

### Basic Paradigms

#### Build script

```cmake
--8<-- "snippets/paradigms/CMakeLists.txt"
```

#### Polymorphism

```cpp
--8<-- "snippets/paradigms/polymorphism.cpp"
```

#### Shared from this

```cpp
--8<-- "snippets/paradigms/shared_from_this.cpp"
```

#### Metaprogramming

```cpp
--8<-- "snippets/paradigms/metaprogramming.cpp"
```

#### CRTP

```cpp
--8<-- "snippets/paradigms/CRTP.cpp"
```

#### SFINAE

```cpp
--8<-- "snippets/paradigms/SFINAE.cpp"
```

### Parallelism

#### Build script

```cmake
--8<-- "snippets/parallel/CMakeLists.txt"
```

#### Execution Policies

```cpp
--8<-- "snippets/parallel/policies.cpp"
```

#### Threads

```cpp
--8<-- "snippets/parallel/multithreading.cpp"
```

#### Executors

```cpp
--8<-- "snippets/parallel/executors.cpp"
```

#### Timers

```cpp
--8<-- "snippets/parallel/timers.cpp"
```

#### Signals

```cpp
--8<-- "snippets/parallel/signals.cpp"
```

#### Async++

```cpp
--8<-- "snippets/parallel/async_pools.cpp"
```

## Utilities

### Regular Expressions

#### Build script

```cmake
--8<-- "snippets/utilities/CMakeLists.txt"
```

#### Regex

```cpp
--8<-- "snippets/utilities/regex.cpp"
```

### Networking

#### Build script

```cmake
--8<-- "snippets/networking/CMakeLists.txt"
```

#### Network

```cpp
--8<-- "snippets/networking/network.cpp"
```

#### Async Network

```cpp
--8<-- "snippets/networking/network_async.cpp"
```

#### Http server

main.cpp

```cpp
--8<-- "snippets/networking/server/main.cpp"
```

server.hpp

```cpp
--8<-- "snippets/networking/server/server.hpp"
```

connection_manager.hpp

```cpp
--8<-- "snippets/networking/server/connection_manager.hpp"
```

connection.hpp

```cpp
--8<-- "snippets/networking/server/connection.hpp"
```

header.hpp

```cpp
--8<-- "snippets/networking/server/header.hpp"
```

reply.hpp

```cpp
--8<-- "snippets/networking/server/reply.hpp"
```

request.hpp

```cpp
--8<-- "snippets/networking/server/request.hpp"
```

request_parser.hpp

```cpp
--8<-- "snippets/networking/server/request_parser.hpp"
```

mime_types.hpp

```cpp
--8<-- "snippets/networking/server/mime_types.hpp"
```

request_handler.hpp

```cpp
--8<-- "snippets/networking/server/request_handler.hpp"
```

mime_types.cpp

```cpp
--8<-- "snippets/networking/server/mime_types.cpp"
```

request_parser.cpp

```cpp
--8<-- "snippets/networking/server/request_parser.cpp"
```

reply.cpp

```cpp
--8<-- "snippets/networking/server/reply.cpp"
```

request_handler.cpp

```cpp
--8<-- "snippets/networking/server/request_handler.cpp"
```

connection.cpp

```cpp
--8<-- "snippets/networking/server/connection.cpp"
```

connection_manager.cpp

```cpp
--8<-- "snippets/networking/server/connection_manager.cpp"
```

server.cpp

```cpp
--8<-- "snippets/networking/server/server.cpp"
```

## GUIs

### Build script

```cmake
--8<-- "snippets/gui/CMakeLists.txt"
```

### Qt

```cpp
--8<-- "snippets/gui/qt/qt_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/qt/CMakeLists.txt"
```

### OpenGL + SDL

```cpp
--8<-- "snippets/gui/opengl/sdl/sdl_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/opengl/sdl/CMakeLists.txt"
```

### OpenGL + GLFW

```cpp
--8<-- "snippets/gui/opengl/glfw/opengl_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/opengl/glfw/CMakeLists.txt"
```

### IMGUI

```cpp
--8<-- "snippets/gui/imgui/imgui_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/imgui/CMakeLists.txt"
```

### Webview

```cpp
--8<-- "snippets/gui/webview/webview_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/webview/CMakeLists.txt"
```

### System tray

```cpp
--8<-- "snippets/gui/tray/tray_hello.cpp"
```

Build script: 

```cmake
--8<-- "snippets/gui/tray/CMakeLists.txt"
```

## Testing

### Build script

```cmake
--8<-- "snippets/tests/CMakeLists.txt"
```

### Catch2

```cpp
--8<-- "snippets/tests/unit_tests_catch.cpp"
```

### boost.ut

```cpp
--8<-- "snippets/tests/unit_tests_ut.cpp"
```

### Source Location

```cpp
--8<-- "snippets/tests/source_location.cpp"
```

### Plots

```cpp
--8<-- "snippets/tests/plots.cpp"
```

## CMake Functions

### Project Flags

```cmake
--8<-- "cmake/functions/project_flags.cmake"
```

### Target Options

```cmake
--8<-- "cmake/functions/sanitizers.cmake"
```

### Sanitizers

```cmake
--8<-- "cmake/functions/target_options.cmake"
```

### Qt Helpers

```cmake
--8<-- "cmake/functions/qt_helpers.cmake"
```

## FAQ

**Where are the examples? Are the snippets examples?**

The complete examples are in the [`examples`](./examples) directory, but they not explicitly replicated in the docs because they are much longer than the snippets.

<br/>

**What's the difference between snippets and examples?**

Examples are often long and don't represent independent tasks you can copy and paste. Snippets represent independent
tasks between pairs of comments that you can copy and paste.

<br/>

**Shouldn't the snippet files be short files?**

The snippets could go into a new category level and we could separate them at their lowest level by file, but that would
make them difficult to explore if the resolution is too high, like 3-4 lines of code per file. Also, because snippets
have pre-conditions and post-conditions, it would make it much harder to test all snippets.

<br/>

**Why not get my snippets directly from cppreference or cplusplus.com?**

The cppreference is not meant for snippets and this repository is not meant to be a reference for the C++ standard. Some
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
    * Mix simple and complex concepts to make a point

<br/>

**Why do you use `std::endl` so much in the snippets? Isn't it evil?**

The snippets usually use `std::endl` instead of `'\n'`:

* Flushing *does* have a [semantic meaning](https://en.cppreference.com/w/cpp/io/manip/flush) different from `'\n` which is a nice convention for small snippets (please show me what's in the buffer vs. put a newline in the buffer)
* Most snippets require creating variables first and using them later so that we can test the snippets with GitHub Actions. The flushing part is not what you are going to copy and paste in a snippet.
* The time difference of flushing `std::cout` to the console (not files!) is [negligible](./examples/datetime/flushtime.cpp)
* Almost no application is spending more time flushing than calculating things to flush. Unless it's a flushing benchmark.

## Get involved

* After getting started with this library, please complete this [survey](http://www.alandefreitas.com/survey/alandefreitas/moderncpp) to let us know how we can improve your experience.
* Discussions are concentrated on our GitHub [discussions](https://github.com/alandefreitas/moderncpp/discussions) page. Don't refrain from asking questions and proposing ideas.
* If you are a programmer with good ideas, please [share](https://github.com/alandefreitas/moderncpp/discussions/new) these ideas with us.
* Academic collaboration is more than welcome.

<br/>

**Contributing**

Feel free to contribute with new snippets to this repository. For complex features and changes, consider [getting feedback](https://github.com/alandefreitas/moderncpp/discussions/new) from the community first.

There are many ways in which you can contribute to this library:

* Testing the library in new environments
* Contributing with interesting snippets and examples
* Finding problems in the documentation
* Finding bugs in general
* Whatever idea seems interesting to you

The only thing we ask you is to make sure your contribution is not destructive. Some contributions in which we are not interested are:

* "I don't like this optional feature so I removed/deprecated it"
* "I removed this feature to support older versions of C++" but have not provided an equivalent alternative. This repository is focused on Modern C++.
* "I removed this feature so I don't have to install/update ______" but have not provided an equivalent alternative
* "I'm creating this high-cost promise that we'll support ________ forever" but I'm not sticking around to keep that promise

In doubt, please open a [discussion](https://github.com/alandefreitas/moderncpp/discussions) first.

<br/>

**Guidelines**

If contributing with code, please leave the pedantic mode ON (`-DBUILD_WITH_PEDANTIC_WARNINGS=ON`), use [cppcheck](http://cppcheck.sourceforge.net/), and [clang-format](https://clang.llvm.org/docs/ClangFormat.html).

<details>
    <summary>Example: CLion</summary>

![CLion Settings with Pedantic Mode](docs/img/pedantic_clion.png)

</details>

If contributing to the documentation, please edit [`README.md`](README.md) directly, as the files in this documentation are automatically generated with [mdsplit](https://github.com/alandefreitas/mdsplit).
