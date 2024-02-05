# Broswer OS

## Development Setup

Ubuntu 

```
$ sudo apt update
$ sudo apt install llvm clang lld python3-pip qemu-system gdb-multiarch git
$ pip3 install --user -r tools/requirements.txt
```

macOS Sonoma

```
$ brew install llvm python3 qemu riscv-software-src/riscv/riscv-tools
$ pip3 install --user -r tools/requirements.txt
```

## Build & Exe
```
$ make -j8              # OSをビルドする
$ make -j8 V=1          # OSをビルドする (詳細なビルドログを出力)
$ make -j8 RELEASE=1    # OSをビルドする (コンパイラのより高度な最適化を有効化)
$ make -j8 run          # OSをビルドしてQEMUで実行する (シングルコア)
$ make -j8 run CPUS=4   # OSをビルドしてQEMUで実行する (4コア)
```

