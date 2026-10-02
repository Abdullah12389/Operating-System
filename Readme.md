How to run the code

Compile the  bootfile
1. nasm -f elf32 boot.asm -o boot.o

Compile the C code by using no prebuild linkers and with optimization
2. i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O0 -Wall -Wextra

Linking everything together in minos.bin
3. i686-elf-ld -T linker.ld -o minos.bin boot.o kernel.o

Run the operating System
4. qemu-system-i386 -kernel minos.bin
