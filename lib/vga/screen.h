#ifndef VGA_SCREEN_HEADER
#define VGA_SCREEN_HEADER

/*void char_print_newline(char *string)
{
    vmem_print(string, text_output_color, last_pos);
    last_pos = last_pos + 160;
}*/

void switch_to_newline(void)
{
    line_size = BYTES_FEEL * COLUMNS;
  	last_pos = last_pos + (line_size - last_pos % (line_size));
}

void print_here(char *string)
{
    vmem_print(string, text_output_color, last_pos);
}

#endif
