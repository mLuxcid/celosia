#ifndef KERNEL_HW_UART_H_
#define KERNEL_HW_UART_H_

#include <sys/types.h>

#define UART0_ADDR 0x10000000

// NOTE: This is required for interrupt-based UART communication
void uart_init();
void uart_putc(char);
void uart_puts(const char *);

void uart_putc_sync(char);
void uart_puts_sync(const char *);

#endif  // KERNEL_HW_UART_H_
