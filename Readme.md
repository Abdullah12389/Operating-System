# MinOS Build and Run Guide

Follow these steps to compile your bootloader, build the C kernel, link them together, and run the operating system in QEMU.

### 1. Compile the Bootfile
Assemble the assembly boot file into an ELF32 object file:
```bash
nasm -f elf32 boot.asm -o boot.o
```

### 2. Compile the C Code
Compile your kernel source code without standard library dependencies and with optimizations disabled:
```bash
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O0 -Wall -Wextra
```

### 3. Link Everything Together
Combine your object files using your custom linker script to create the final binary:
```bash
i686-elf-ld -T linker.ld -o minos.bin boot.o kernel.o
```

### 4. Run the Operating System
Launch your compiled kernel inside the QEMU emulator:
```bash
qemu-system-i386 -kernel minos.bin
```

