#include "lib/vga/vga.h"
#include "lib/vga/screen.h"

void init()
{
    vmem_clean();
    print_line("Tiny-kernel | Hello, world!");
}
