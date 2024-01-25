#include <sys/types.h>
#include <hw/uart.h>

/* TODO: for easier porting to real hardware, use something like `boardcfg.h` */
#define UART0_ADDR 0x10000000

volatile uint8_t *uart0_ptr = (volatile uint8_t *)UART0_ADDR;

void uart_write(const char *buf)
{
    while (*buf != '\0') {
        *uart0_ptr = *buf;
        buf++;
    }
}
