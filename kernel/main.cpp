#include <hw/reg.h>
#include <lib/cons.h>
#include <sys/types.h>

static volatile int started = 0;

auto kthread_main(void) -> void {
    /* tp stores the hartid */
    if (read_tp() == 0) {
        cons::init();
        cons::puts("initialized hart #0\n");

        cons::puts("booting...\n");

        __sync_synchronize();
        started = 1;
    } else {
        while (started == 0) {
        }

        __sync_synchronize();
    }
}
