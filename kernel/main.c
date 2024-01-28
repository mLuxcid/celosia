#include <hw/uart.h>
#include <kconfig.h>
#include <sys/types.h>

void main(void);

/* This gets loaded into `sp` */
__attribute__((aligned(16))) char stack0[4096 * MAXHART];

/* This function gets called in `entry.S` */
void kernel_entry(void) {
    uart_init();

    uart_write("Hello, world!\n");
    uart_write("Testing out stdout locking...\n");
    while (1)
        ;
}
