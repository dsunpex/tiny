#!/bin/sh
nasm -f elf32 bootload.asm -o bl.o
gcc -m32 -c main.c -o km.o
ld -m elf_i386 -T link.ld -o kernel bl.o km.o
qemu-system-x86_64 -kernel kernel
rm *.o kernel
