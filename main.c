#include "lib/io/io.h"
#include "lib/io/serial.h"
#include "lib/vga/vga.h"
#include "lib/vga/screen.h"

void init()
{
    vmem_clean();
    print_line("Tiny-kernel | Hello, world!");

    serial_init();
    serial_write("hello");
}
