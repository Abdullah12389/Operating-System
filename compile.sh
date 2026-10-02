#!/bin/bash
nasm -f elf32 boot.asm -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O0 -Wall -Wextra
i686-elf-gcc -c printf.c -o printf.o -std=gnu99 -ffreestanding -O0 -Wall -Wextra
i686-elf-ld -T linker.ld -o minos.bin boot.o printf.o kernel.o