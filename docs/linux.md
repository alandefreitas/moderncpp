---
layout: default
title: Linux
nav_order: 3
has_children: false
has_toc: false
---
# Linux

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




<!-- Generated with mdsplit: https://github.com/alandefreitas/mdsplit -->
