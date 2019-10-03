#ifndef IO_SERIAL_HEADER
#define IO_SERIAL_HEADER

#define PORT DBG_PORT
enum serial_type
{
    DBG_PORT = 0x3F8, // by default, debug output port is COM1
    COM1 = 0x3F8,
    COM2 = 0x2F8,
    COM3 = 0x3E8,
    COM4 = 0x2E8,
};

void serial_init() {
   port_write(PORT + 1, 0x00);    // Disable all interrupts
   port_write(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   port_write(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   port_write(PORT + 1, 0x00);    //                  (hi byte)
   port_write(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   port_write(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   port_write(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

int is_transmit_empty() {
   return port_read(PORT + 5) & 0x20;
}


// Don't working. Output is always 0x92
int serial_write(char a) {
   while (is_transmit_empty() == 0);

   port_write(PORT,a);
}

#endif
