#include <sys/types.h>
#include <hw/uart.h>
#include <boardconfig.h>

volatile uint8_t *uart0_ptr = (volatile uint8_t *)UART0_ADDR;

void uart_putc(char c)
{
    *uart0_ptr = c;
}

void uart_write(const char *buf)
{
    while (*buf != '\0') {
        uart_putc(*buf);
        buf++;
    }
}
