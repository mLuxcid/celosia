#ifndef KERNEL_HW_UART_H_
#define KERNEL_HW_UART_H_

#include <sys/types.h>

/* initialize the uart lock & configure(TODO)*/
void uart_init(void);

/* write onto UART0 */
void uart_puts(const char *);
void uart_putc(char);

/* read from UART0 */
char uart_getc(void);

#endif /* KERNEL_HW_UART_H_ */
