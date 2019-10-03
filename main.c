#include "lib/io/io.h"
//#include "lib/io/serial.h"
#include "lib/vga/charm.h"
//#include "lib/vga/screen.h"
#include "lib/io/keyboard.h"

void init()
{
    screen_clean();
    screen_print("Hello, world!");

    //serial_init();
    //serial_write("hello");

  	idt_init();
  	kb_init();
    while(1);

}
