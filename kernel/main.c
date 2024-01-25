#include <sys/types.h>
#include <hw/uart.h>
#include <kconfig.h>

void main(void);

__attribute__ ((aligned (16))) char stack0[4096 * MAXHART];

/* This function gets called in `entry.S` */
void
kernel_entry(void)
{
    uart_write("Hello, world!\r\n");
    while (1)
        ;
}

