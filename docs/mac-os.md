---
layout: default
title: Mac OS
nav_order: 4
has_children: false
has_toc: false
---
# Mac OS

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

![](img/set_compiler.png)




<!-- Generated with mdsplit: https://github.com/alandefreitas/mdsplit -->
