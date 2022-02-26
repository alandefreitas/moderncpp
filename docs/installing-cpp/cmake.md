## CMake

CMake is the most common build system for C++. Instead of using the compiler directly, CMake controls the compilation
process through platform independent configuration files.

## Install CMake

CMake can be downloaded from [cmake.org](https://cmake.org/) or from a package manager:

=== "apt-get"

    ```console
    sudo apt-get -y install cmake
    ```

=== "Homebrew"

    ```console
    brew install cmake
    ```

## Configuration files

There should be a file named `CMakeLists.txt` in the root directory of your project. A starting point is:

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name
project(my_project_name)

# add the executable
add_executable(my_project_name main.cpp)
```

## Building with CMake

Create a build directory:

```bash
mkdir build
```

Navigate to the build directory and run CMake:

```bash
cd build
cmake ..
```

This will configure the project and generate a native build system scripts.

Then call that build system to actually compile/link the project:

```bash
cmake --build .
```

The executable file must have been generated. Note how CMake abstracts the differences between compilers and platforms.

## Configure compiler

Set the variable `CMAKE_CXX_COMPILER` from the command line to let CMake know what compiler to use: 

```bash
cmake -D CMAKE_C_COMPILER="/path/to/your/c/compiler/executable" -D CMAKE_CXX_COMPILER "/path/to/your/cpp/compiler/executable" /path/to/directory/containing/CMakeLists.txt
```

If you want this to be your default compiler, you can set the `CXX` environment variable:

```bash
export CXX=/path/to/your/cpp/compiler/executable
```

If you want to use this compiler in a single project, always run CMake with these options:

```bash
-DCMAKE_C_COMPILER=/path/to/your/c/compiler/executable -DCMAKE_CXX_COMPILER=/path/to/your/cpp/compiler/executable
```

Or tell your IDE to pass these options to CMake:

![](../img/set_compiler.png)

