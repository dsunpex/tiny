build: main.asm main.c link.ld
	nasm -f elf32 main.asm -o main_asm.o
	gcc -c main.c -o main_c.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
	ld -m elf_i386 -T link.ld -o kernel main_asm.o main_c.o

run:
	qemu-system-x86_64 -kernel kernel -serial file:"serial.out"

clean:
	rm -rf *.o kernel

full: main.asm main.c link.ld
	nasm -f elf32 main.asm -o main_asm.o
	gcc -c main.c -o main_c.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs
	ld -m elf_i386 -T link.ld -o kernel main_asm.o main_c.o
	qemu-system-x86_64 -kernel kernel -serial file:"serial.out"
	make clean
