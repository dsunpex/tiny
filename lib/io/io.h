#ifndef IO_HEADER
#define IO_HEADER

//outb and inb
extern char port_read(unsigned short port);
extern void port_write(unsigned short port, unsigned char data);
extern void idt_load(unsigned long *idt_ptr);

#endif
