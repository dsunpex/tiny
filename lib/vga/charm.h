// VGA 80x25 int03h TEXT MODE

#ifndef VGA_CHARMODE_HEADER
#define VGA_CHARMODE_HEADER

#define LINES 25
#define COLUMNS 80
#define BYTES_FEEL 2 // bytes for each element
#define SCREENSIZE BYTES_FEEL * COLUMNS * LINES

enum color
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

// Screen buffer
char *vidptr = (char*)0xb8000;

// Last char position
int position = 0;

// Screen output text color
int default_color = COLOR_LIGHT_GREY;

void screen_clean()
{
  unsigned int i = 0;
  while (i < SCREENSIZE) {
    vidptr[i++] = ' ';
    vidptr[i++] = 0x07;
  }
  position = 0;
}

void screen_print(char *string)
{
    unsigned int charcount = 0;
    while (string[charcount] != '\0') {
        vidptr[position] = string[charcount];
        vidptr[position+1] = default_color;
        position = position + BYTES_FEEL;
        ++charcount;
    }
}

void screen_newline(void)
{
    int line_size = BYTES_FEEL * COLUMNS;
  	position = position + (line_size - position % (line_size));
}

void screen_print_newline(char *string)
{
    screen_newline();
    screen_print(string);
}

#endif
