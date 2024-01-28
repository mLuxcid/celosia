#include <boardconfig.h>
#include <hw/uart.h>
#include <spinlock.h>
#include <sys/types.h>

volatile uint8_t *uart0_ptr = (volatile uint8_t *)UART0_ADDR;
struct spinlock locked;

void uart_init(void) { init_lock(&locked, "UART0 lock"); }

void uart_putc(char c) { *uart0_ptr = c; }

void uart_write(const char *buf) {
    while (locked.locked) {
        // spin
    }

    acquire_lock(&locked);

    while (*buf != '\0') {
        uart_putc(*buf);
        buf++;
    }

    release_lock(&locked);
}
