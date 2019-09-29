#!/bin/sh
nasm -f elf32 main.asm -o main_asm.o
gcc -c main.c -o main_c.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
#gcc -c vga.c -o vga_c.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
ld -m elf_i386 -T link.ld -o kernel main_asm.o main_c.o
qemu-system-x86_64 -kernel kernel -serial file:"debug_serial.out"
rm -rf *.o kernel
