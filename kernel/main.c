#include <hw/reg.h>
#include <hw/uart.h>
#include <sys/types.h>

static volatile int started = 0;

void main(void) {
    if (read_tp() == 0) {
        uart_init();
        uart_write("initialized hart #0\n");
        uart_write("booting...\n");

        __sync_synchronize();
        started = 1;
    } else {
        while (started == 0) {
        }

        __sync_synchronize();
        uart_write("initialized hart...\n");
    }
}
