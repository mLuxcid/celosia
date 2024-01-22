#ifndef CELOSIA_KERNEL_HW_UART_H_
#define CELOSIA_KERNEL_HW_UART_H_

#include <sys/types.h>

// QEMU's UART0 is located at 0x10000000
#define UART0_ADDR 0x10000000

void uart_init();
void uart_putc(char c);
void uart_puts(const char *s);

#endif  // CELOSIA_KERNEL_HW_UART_H_
