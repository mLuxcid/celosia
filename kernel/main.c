#include <kernel/hw/uart.h>
#include <sys/types.h>

void kernel_entry(void) { uart_puts_sync("Hello, world!\n"); }
