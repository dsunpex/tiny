#ifndef VGA_SCREEN_HEADER
#define VGA_SCREEN_HEADER

void print_line(char *string)
{
    vmem_print(string, text_output_color, last_pos);
    last_pos = last_pos + 160;
}

#endif
