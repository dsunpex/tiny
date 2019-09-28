#include "vmem.h"

void vmem_clean(void)
{
  char *vidptr = (char*)0xb8000;
  unsigned int i = 0;
  unsigned int j = 0;

  while(j < 80 * 25 * 2) {
      vidptr[j] = ' ';
      vidptr[j+1] = 0x07;
      j = j + 2;
  }
}

void vmem_print(char *str, int i, int j, enum vga_color col)
{
  char *vidptr = (char*)0xb8000;

  while(str[j] != '\0') {
      vidptr[i] = str[j];
      vidptr[i+1] = col;
      ++j;
      i = i + 2;
  }
}

void init(void)
{
    vmem_clean();

    vmem_print("something there", 0, 0, COLOR_WHITE);
    vmem_print("and there :)", 46, 0, COLOR_WHITE);

    return;
}
