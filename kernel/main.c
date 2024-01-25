#include <sys/types.h>
#include <hw/uart.h>

__attribute__ ((aligned (16))) char stack0[4096 * 8];

/* This function gets called in `entry.S` */
void
kernel_entry(void)
{
    uart_write("hello, world!\n");
    while (1)
        ;
}

