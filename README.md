# Modern C++: Snippets and Examples

* [Control Flow](snippets/control_flow)
    * [Hello World](C++/modern_cpp/snippets/control_flow/hello_world.cpp)
    * [Sequential](snippets/control_flow/sequential.cpp)
    * [Conditional](snippets/control_flow/conditional.cpp)
    * [Loops](snippets/control_flow/loops.cpp)
* [Data Types](snippets/data_types)
    * [Data Types](snippets/data_types/data_types.cpp)
    * [Auto](snippets/data_types/auto.cpp)
    * [Constants](snippets/data_types/constants.cpp)
    * [Raw Arrays](snippets/data_types/raw_arrays.cpp)
    * [Arrays](snippets/data_types/arrays.cpp)
    * [Vectors](snippets/data_types/vectors.cpp)
    * [Strings](snippets/data_types/strings.cpp)
    * [Move](snippets/data_types/move.cpp)
    * [Raw Pointers](snippets/data_types/raw_pointers.cpp)
    * [Smart Pointers](snippets/data_types/smart_pointers.cpp)
    * [Structured Binding](snippets/data_types/structured_binding.cpp)
    * [Vectors](snippets/data_types/vectors.cpp)
* [Functions](snippets/functions)
    * [Functions](snippets/functions/functions.cpp)
    * [Lambda](snippets/functions/lambda.cpp)
* [Files](snippets/files)
    * [File Input/Output](snippets/files/files.cpp)
    * [Manage Files](snippets/files/filesystem.cpp)
* [Templates](snippets/templates/)
    * [Template Functions](snippets/templates/template_functions.cpp)
    * [Template Alias](snippets/templates/template_alias.cpp)
    * [Concepts](snippets/templates/concepts.cpp)
    * [SFINAE](snippets/templates/sfinae.cpp)
* [Algorithms](snippets/algorithm/)
    * [Searching](snippets/algorithm/searching.cpp)
    * [Sorting](snippets/algorithm/sorting.cpp)
    * [Algorithms](snippets/algorithm/algorithms.cpp)
    * [Ranges](snippets/algorithm/ranges.cpp)
* [Data Structures](snippets/data_structures/)
    * [Sequential Containers](snippets/data_structures/sequential_containers.cpp)
    * [Associative Containers](snippets/data_structures/associative_containers.cpp)
    * [Tuples](snippets/data_structures/tuples.cpp)
    * [Variant](snippets/data_structures/variant.cpp)
    * [Any](snippets/data_structures/any.cpp)
    * [Bitset](snippets/data_structures/bitset.cpp)
    * [Optional](snippets/data_structures/optional.cpp)
* [Programming Paradigms](snippets/paradigms/)
    * [CRTP](snippets/paradigms/CRTP.cpp)
    * [Polymorphism](snippets/paradigms/polymorphism.cpp)
    * [Polymorphism Cast](snippets/paradigms/polymorphism_cast.cpp)
    * [Metaprogramming](snippets/paradigms/metaprogramming.cpp)
    * [SFINAE](snippets/paradigms/SFINAE.cpp)
    * [Metaprogramming](snippets/paradigms/metaprogramming.cpp)
* [Utilities](snippets/utilities/)
    * [Clock](snippets/utilities/clock.cpp)
    * [Random](snippets/utilities/random.cpp)
    * [Regex](snippets/utilities/regex.cpp)
    * [Multithreading](snippets/utilities/multithreading.cpp)
    * [Async Pools](snippets/utilities/async_pools.cpp)
    * [Format](snippets/utilities/format.cpp)
    * [Network](snippets/utilities/network.cpp)
    * [Network Async](snippets/utilities/network_async.cpp)
* [GUI](snippets/gui/)
    * [Qt](snippets/gui/qt/qt_hello.cpp)
    * [Webview](snippets/gui/webview/webview_hello.cpp)
    * [Opengl](snippets/gui/opengl/)
        * [GLFW](snippets/gui/opengl/glfw/opengl_hello.cpp)
        * [SDL](snippets/gui/opengl/sdl/sdl_hello.cpp)
    * [SDL](snippets/gui/sdl/sdl_hello.cpp)
    * [Imgui](snippets/gui/imgui/imgui_hello.cpp)
    * [Tray](snippets/gui/tray/tray_hello.cpp)
* [Tests](snippets/tests/)
    * [Source Location](snippets/tests/source_location.cpp)
    * [Unit Tests](snippets/tests/unit_tests.cpp)
    * [Plots](snippets/tests/plots.cpp)

# Installing C++20

Many operating systems don't use C++20 by default yet. Follow these instructions to install C++20.

## Linux

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

## Mac OS

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

If you want to use this compiler in a single project, run cmake with these options:

```bash
-DCMAKE_C_COMPILER=/usr/local/bin/clang -DCMAKE_CXX_COMPILER=/usr/local/bin/clang++
```

Or tell you IDE to pass these options to CMake:

![](docs/img/set_compiler.png)

## Windows

Update your [Visual Studio](https://visualstudio.microsoft.com) Compiler.

The most recent version of Visual Studio should include C++20.