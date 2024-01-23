#include <kernel/hw/uart.h>

volatile uint8_t *uart0_base = (uint8_t *)UART0_ADDR;

void uart_putc_sync(char c) { *uart0_base = c; }
void uart_puts_sync(const char *s) {
  while (*s != '\0') {
    uart_putc_sync(*s);
  }
}
