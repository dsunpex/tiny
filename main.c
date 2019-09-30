#include "lib/io/io.h"
#include "lib/io/serial.h"
#include "lib/vga/vga.h"
#include "lib/vga/screen.h"
#include "lib/io/keyboard.h"

void init()
{
    vmem_clean();
    print_here("Tiny-kernel | Hello, world!");

    serial_init();
    serial_write("hello");

  	idt_init();
  	kb_init();
    while(1);

}
