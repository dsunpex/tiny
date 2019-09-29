#ifndef VGA_HEADER
#define VGA_HEADER

#define LINES 25
#define COLUMNS 80
#define BYTES_FEEL 2 // bytes for each element
#define SCREENSIZE BYTES_FEEL * COLUMNS * LINES

char *vidptr = (char*)0xb8000;
unsigned int line_size = 160; // max pos = line size * 24
int last_line = 0;
int last_pos = 0;

enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

int text_output_color = COLOR_WHITE; // default is COLOR_LIGHT_GREY

enum lines_pos
{
	LINE_0 = 0,
	LINE_1 = 160,
	LINE_2 = 320,
	LINE_3 = 480,
	LINE_4 = 640,
	LINE_5 = 800,
	LINE_6 = 960,
	LINE_7 = 1120,
	LINE_8 = 1280,
	LINE_9 = 1440,
	LINE_10 = 1600,
	LINE_11 = 1760,
	LINE_12 = 1920,
	LINE_13 = 2080,
	LINE_14 = 2240,
	LINE_15 = 2400,
	LINE_16 = 2560,
	LINE_17 = 2720,
	LINE_18 = 2880,
	LINE_19 = 3040,
	LINE_20 = 3200,
	LINE_21 = 3360,
	LINE_22 = 3520,
	LINE_23 = 3680,
	LINE_24 =	3840,
};

void vmem_clean()
{
  unsigned int i = 0;
  while (i < SCREENSIZE) {
    vidptr[i++] = ' ';
    vidptr[i++] = 0x07;
  }
	last_line = 0;
}

void vmem_print(char *str, enum vga_color col, int pos)
{
  unsigned int j = 0;
  while(str[j] != '\0') {
      vidptr[pos] = str[j];
      vidptr[pos+1] = col;
      ++j;
      pos = pos + 2;
  }
}


#endif
