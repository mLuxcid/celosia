#include <hw/reg.h>
#include <hw/uart.h>
#include <sys/types.h>

static volatile int started = 0;

auto kthread_main(void) -> void {
    const char *nums = "0123456789";

    /* tp stores the hartid */
    if (read_tp() == 0) {
        hw::uart::init();
        hw::uart::puts("initialized hart #0\n");
        hw::uart::puts("booting...\n");

        __sync_synchronize();
        started = 1;
    } else {
        while (started == 0) {
        }

        __sync_synchronize();
        hw::uart::puts("initialized hart #");
        hw::uart::putc(nums[read_tp()]);
        hw::uart::putc('\n');
    }
}