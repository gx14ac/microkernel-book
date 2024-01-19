# Broswer OS

Ubuntu 22.04 (Jammy)

```
$ sudo apt update
$ sudo apt install llvm clang lld python3-pip qemu-system gdb-multiarch git
$ pip3 install --user -r tools/requirements.txt
```

macOS 13 (Ventura)

```
$ brew install llvm python3 qemu riscv-software-src/riscv/riscv-tools
$ pip3 install --user -r tools/requirements.txt
```

## Build, Run

次のコマンドでビルドできます。`-j8` は8並列ビルドを意味します。CPUコア数程度を指定すると良いでしょう。`V=1`や`RELEASE=1`はビルドオプションで、組み合わせて使うことができます。

```
$ make -j8              # build os
$ make -j8 V=1          # build os (more specific build logs)
$ make -j8 RELEASE=1    # build os optimize compiler
$ make -j8 run          # build and run on qemu by single core
$ make -j8 run CPUS=4   # build and run on qemu by 4 core
```

## Debug

[Debug](./DEBUG.md)