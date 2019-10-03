; Tiny-kernel assembly initializer

BITS 32
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002              ;magic
        dd 0x00                    ;flags
        dd - (0x1BADB002 + 0x00)   ;checksum. m+f+c should be zero

global start
global port_write
global port_read
global idt_load
global keyboard_handler
extern init
extern keyboard_handler_main

port_read:
    mov edx, [esp + 4]
    in al, dx
    ret

port_write:
    mov   edx, [esp + 4]
    mov   al, [esp + 4 + 4]
    out   dx, al
    ret

idt_load:
    mov edx, [esp + 4]
    lidt [edx]
    sti 				;turn on interrupts
    ret

keyboard_handler:
    call    keyboard_handler_main
	  iretd

start:
  	cli
  	mov esp, stack_space
    ;mov ax,19 ; here select which mode you want
    ;int 16      ; this calls EGA/VGA/VESA BIOS
  	call init
  	hlt

section .bss
resb 8192 ; stack in bytes
stack_space:
