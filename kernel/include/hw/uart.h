#ifndef KERNEL_HW_UART_H_
#define KERNEL_HW_UART_H_

#include <sys/types.h>

void uart_init(void);
void uart_write(const char *);
void uart_putc(char);

#endif /* KERNEL_HW_UART_H_ */
