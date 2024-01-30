#include <hw/reg.h>
#include <hw/uart.h>
#include <kconfig.h>
#include <sys/types.h>

void kthread_main(void);

/* This gets loaded into `sp` */
__attribute__((aligned(16))) char stack0[4096 * MAX_HART];

/* This function gets called in `entry.S` */
extern "C" auto kernel_entry(void) -> void {
    /* set machine previous privelege mode to supervisor */
    write_mstatus((read_mstatus() & ~MSTATUS_MPP_MASK) | MSTATUS_MPP_S);

    /* function that mret jumps to */
    write_mepc((uint64_t)kthread_main);

    /* disable paging in machine mode */
    write_satp(0);

    /* delegate interrupts to supervisor mode */
    write_medeleg(0xFFFF);
    write_mideleg(0xFFFF);
    write_sie(read_sie() | SIE_SEIE | SIE_STIE | SIE_SSIE);

    /* give supervisor access to all physical memory */
    write_pmpaddr0(0x3FFFFFFFFFFFFFull);
    write_pmpcfg0(0xF);

    int hartid = read_mhartid();
    write_tp(hartid);

    asm volatile("mret");
}
