# Modern C++: Snippets and Examples

We often need to copy and paste some snippets to code more productively. Snippets can help us when it's not easy to
remember all high levels features Modern C++ has to offer. This repository contains lots of organized, reusable, and
safe snippets for Modern C++. All snippets are available in GitHub pages in a way convenient for copying and pasting.

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
<details>
<summary>Table of Contents</summary>

- [Quick Start](#quick-start)
- [Data types](#data-types)
  - [Fundamental Data Types](#fundamental-data-types)
  - [Auto](#auto)
  - [Constants](#constants)
  - [Raw arrays](#raw-arrays)
  - [Arrays](#arrays)
  - [Vectors](#vectors)
  - [Strings](#strings)
  - [Raw Pointers](#raw-pointers)
  - [Smart pointers](#smart-pointers)
  - [Move](#move)
  - [Aggregate initialization](#aggregate-initialization)
  - [Structured binding](#structured-binding)
- [Control flow](#control-flow)
  - [Hello World](#hello-world)
  - [Sequential](#sequential)
  - [Input](#input)
  - [Output](#output)
  - [Format](#format)
  - [Operators](#operators)
  - [Conditional](#conditional)
  - [Loops](#loops)
- [Functions](#functions)
  - [Function](#function)
  - [Lambda](#lambda)
- [Files](#files)
  - [File streams](#file-streams)
  - [Filesystem](#filesystem)
- [Template](#template)
  - [Template function](#template-function)
  - [Template aliases](#template-aliases)
  - [Concepts](#concepts)
  - [SFINAE](#sfinae)
- [Date and time](#date-and-time)
  - [Clock](#clock)
  - [Datetime](#datetime)
- [Random](#random)
  - [Random](#random-1)
- [Algorithm](#algorithm)
  - [Basic Algorithms](#basic-algorithms)
  - [Ranges](#ranges)
  - [Sorting](#sorting)
  - [Searching](#searching)
- [Data structures](#data-structures)
  - [Sequential Containers](#sequential-containers)
  - [Associative Containers](#associative-containers)
  - [Memory resource](#memory-resource)
  - [Tuples](#tuples)
  - [Any](#any)
  - [Optional](#optional)
  - [Variant](#variant)
  - [Span](#span)
  - [Bitset](#bitset)
- [Paradigms](#paradigms)
  - [Polymorphism](#polymorphism)
  - [Shared from this](#shared-from-this)
  - [Metaprogramming](#metaprogramming)
  - [CRTP](#crtp)
  - [SFINAE](#sfinae-1)
- [Parallel](#parallel)
  - [Threads](#threads)
  - [Executors](#executors)
  - [Timers](#timers)
  - [Signals](#signals)
  - [Async++](#async)
- [Networking](#networking)
  - [Network](#network)
  - [Async Network](#async-network)
  - [Http server](#http-server)
- [Utilities](#utilities)
  - [Regex](#regex)
- [GUI](#gui)
  - [Qt](#qt)
  - [OpenGL + SDL](#opengl--sdl)
  - [OpenGL + GLFW](#opengl--glfw)
  - [IMGUI](#imgui)
  - [Webview](#webview)
  - [System tray](#system-tray)
- [Tests](#tests)
  - [Catch2](#catch2)
  - [boost.ut](#boostut)
  - [Source Location](#source-location)
  - [Plots](#plots)
- [Installing C++20](#installing-c20)
  - [Linux](#linux)
  - [Mac OS](#mac-os)
  - [Windows](#windows)

</details>
<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Quick Start

This is how this repository works:

* The `snippets` directory has lots of short programs with useful C++20 snippets
* The `examples` directory has lots of short tasks using these snippets
* GitHub actions ensures all snippets are working on GCC, MSVC, and Clang
* We generate GitHub pages with all snippets by groups of tasks

**External Libraries**

For external libraries, we also include a short CMake snippet in the build script with:

* `find_package` to find, setup, and link the large external libraries
* `FetchContents` to download, build, and link the external library

We give preference for external libraries in this order:

1) Libraries that supported by all C++ compilers in the build workflow
2) Libraries that have been accepted into the C++ standard
3) Libraries likely to be accepted into C++23
4) Libraries representative of existing practice

**GitHub Pages**

We generate GitHub pages with all snippets:

* The GitHub pages are generated with mkdocs material and mdsplit
* Snippets organized in sections by groups of tasks
* Sections are easy to explore, copy, and paste

## Data types

### Fundamental Data Types

```cpp
--8<-- "snippets/data_types/data_types.cpp"
```

### Auto

```cpp
--8<-- "snippets/data_types/auto.cpp"
```

### Constants

```cpp
--8<-- "snippets/data_types/constants.cpp"
```

### Raw arrays

```cpp
--8<-- "snippets/data_types/raw_arrays.cpp"
```

### Arrays

```cpp
--8<-- "snippets/data_types/arrays.cpp"
```

### Vectors

```cpp
--8<-- "snippets/data_types/vectors.cpp"
```

### Strings

```cpp
--8<-- "snippets/data_types/strings.cpp"
```

### Raw Pointers

```cpp
--8<-- "snippets/data_types/raw_pointers.cpp"
```

### Smart pointers

```cpp
--8<-- "snippets/data_types/smart_pointers.cpp"
```

### Move

```cpp
--8<-- "snippets/data_types/move.cpp"
```

### Aggregate initialization

```cpp
--8<-- "snippets/data_types/aggregate_initialization.cpp"
```

### Structured binding

```cpp
--8<-- "snippets/data_types/structured_binding.cpp"
```

## Control flow

### Hello World

```cpp
--8<-- "snippets/control_flow/hello_world.cpp"
```

### Sequential

```cpp
--8<-- "snippets/control_flow/sequential.cpp"
```

### Input

```cpp
--8<-- "snippets/control_flow/cin.cpp"
```

### Output

```cpp
--8<-- "snippets/control_flow/printing.cpp"
```

### Format

```cpp
--8<-- "snippets/control_flow/format.cpp"
```

### Operators

```cpp
--8<-- "snippets/control_flow/operators.cpp"
```

### Conditional

```cpp
--8<-- "snippets/control_flow/conditional.cpp"
```

### Loops

```cpp
--8<-- "snippets/control_flow/loops.cpp"
```

## Functions

### Function

```cpp
--8<-- "snippets/functions/functions.cpp"
```

### Lambda

```cpp
--8<-- "snippets/functions/lambda.cpp"
```

## Files

### File streams

```cpp
--8<-- "snippets/files/files.cpp"
```

### Filesystem

```cpp
--8<-- "snippets/files/filesystem.cpp"
```

## Template

### Template function

```cpp
--8<-- "snippets/templates/template_functions.cpp"
```

### Template aliases

```cpp
--8<-- "snippets/templates/template_alias.cpp"
```

### Concepts

```cpp
--8<-- "snippets/templates/concepts.cpp"
```

### SFINAE

```cpp
--8<-- "snippets/templates/sfinae.cpp"
```

## Date and time

### Clock

```cpp
--8<-- "snippets/datetime/clock.cpp"
```

### Datetime

```cpp
--8<-- "snippets/datetime/datetime.cpp"
```

## Random

### Random

```cpp
--8<-- "snippets/random/random.cpp"
```

## Algorithm

### Basic Algorithms

```cpp
--8<-- "snippets/algorithm/algorithms.cpp"
```

### Ranges

```cpp
--8<-- "snippets/algorithm/ranges.cpp"
```

### Sorting

```cpp
--8<-- "snippets/algorithm/sorting.cpp"
```

### Searching

```cpp
--8<-- "snippets/algorithm/searching.cpp"
```

## Data structures

### Sequential Containers

```cpp
--8<-- "snippets/data_structures/sequential_containers.cpp"
```

### Associative Containers

```cpp
--8<-- "snippets/data_structures/associative_containers.cpp"
```

### Memory resource

```cpp
--8<-- "snippets/data_structures/memory_resource.cpp"
```

### Tuples

```cpp
--8<-- "snippets/data_structures/tuples.cpp"
```

### Any

```cpp
--8<-- "snippets/data_structures/any.cpp"
```

### Optional

```cpp
--8<-- "snippets/data_structures/optional.cpp"
```

### Variant

```cpp
--8<-- "snippets/data_structures/variant.cpp"
```

### Span

```cpp
--8<-- "snippets/data_structures/span.cpp"
```

### Bitset

```cpp
--8<-- "snippets/data_structures/bitset.cpp"
```

## Paradigms

### Polymorphism

```cpp
--8<-- "snippets/paradigms/polymorphism.cpp"
```

### Shared from this

```cpp
--8<-- "snippets/paradigms/shared_from_this.cpp"
```

### Metaprogramming

```cpp
--8<-- "snippets/paradigms/metaprogramming.cpp"
```

### CRTP

```cpp
--8<-- "snippets/paradigms/cRTP.cpp"
```

### SFINAE

```cpp
--8<-- "snippets/paradigms/sFINAE.cpp"
```

## Parallel

### Threads

```cpp
--8<-- "snippets/parallel/multithreading.cpp"
```

### Executors

```cpp
--8<-- "snippets/parallel/executors.cpp"
```

### Timers

```cpp
--8<-- "snippets/parallel/timers.cpp"
```

### Signals

```cpp
--8<-- "snippets/parallel/signals.cpp"
```

### Async++

```cpp
--8<-- "snippets/parallel/async_pools.cpp"
```

## Networking

### Network

```cpp
--8<-- "snippets/networking/network.cpp"
```

### Async Network

```cpp
--8<-- "snippets/networking/network_async.cpp"
```

### Http server

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

## Utilities

### Regex

```cpp
--8<-- "snippets/utilities/regex.cpp"
```

## GUI

### Qt

```cpp
--8<-- "snippets/gui/qt/qt_hello.cpp"
```

### OpenGL + SDL

```cpp
--8<-- "snippets/gui/opengl/sdl/sdl_hello.cpp"
```

### OpenGL + GLFW

```cpp
--8<-- "snippets/gui/opengl/glfw/opengl_hello.cpp"
```

### IMGUI

```cpp
--8<-- "snippets/gui/imgui/imgui_hello.cpp"
```

### Webview

```cpp
--8<-- "snippets/gui/webview/webview_hello.cpp"
```

### System tray

```cpp
--8<-- "snippets/gui/tray/tray_hello.cpp"
```

## Tests

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

## Installing C++20

Many operating systems don't use C++20 by default yet. Follow these instructions to install C++20.

### Linux

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

### Mac OS

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

### Windows

Update your [Visual Studio](https://visualstudio.microsoft.com) Compiler.

The most recent version of Visual Studio should include C++20.

!!! warning We still don't know of a script for installing C++20 on Windows from the terminal.