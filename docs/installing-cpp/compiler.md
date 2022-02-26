## Windows + MSVC

Update your [Visual Studio](https://visualstudio.microsoft.com) Compiler. The most recent version of Visual Studio
should include C++20.

## Linux + GCC

Update GCC:

```bash
# Repository
sudo apt install build-essential
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
# Install
sudo apt install gcc-11
sudo apt install g++-11
# Install as compiler alternative
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 11
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 11
```

Set your default compiler with:

```bash
update-alternatives --config g++
```

## Mac OS + Clang

Download a [recent version](https://releases.llvm.org/download.html) of Clang:

```bash
curl --output clang.tar.xz -L https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.1/clang+llvm-13.0.1-x86_64-apple-darwin.tar.xz
mkdir clang
tar -xvJf clang.tar.xz -C clang
```

Copy these files to `usr/local/`:

```bash
cd clang/clang+llvm-13.0.1-x86_64-apple-darwin
sudo cp -R * /usr/local/
```

