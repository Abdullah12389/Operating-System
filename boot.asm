; boot.asm

MBOOT_PAGE_ALIGN equ 1<<0
MBOOT_MEM_INFO equ 1<<1
MBOOT_HEADER_MAGIC equ 0x1BADB002
MBOOT_HEADER_FLAGS equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

section .multiboot
    align 4
    dd MBOOT_HEADER_MAGIC
    dd MBOOT_HEADER_FLAGS
    dd MBOOT_CHECKSUM

section .text
    global start
    extern kernel_main

start:
    mov esp, stack_space
    call kernel_main
    cli

.hang:
    hlt 
    jmp .hang

section .bss
    resb 8192
stack_space: