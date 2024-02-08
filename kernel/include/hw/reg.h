#ifndef KERNEL_HW_REG_H_
#define KERNEL_HW_REG_H_

#include <sys/types.h>
namespace hw {}

static inline uint64_t read_mhartid() {
    uint64_t val;
    asm volatile("csrr %0, mhartid" : "=r"(val));
    return val;
}

#define MSTATUS_MPP_MASK (3L << 11) /* previous mode. */
#define MSTATUS_MPP_M (3L << 11)    /* machine-mode */
#define MSTATUS_MPP_S (1L << 11)    /* supervisor-mode */
#define MSTATUS_MPP_U (0L << 11)    /* user-mode */
#define MSTATUS_MIE (1L << 3)       /* machine-mode interrupt enable */

static inline uint64_t read_mstatus() {
    uint64_t val;
    asm volatile("csrr %0, mstatus" : "=r"(val));
    return val;
}

static inline void write_mstatus(uint64_t val) {
    asm volatile("csrw mstatus, %0" : : "r"(val));
}

static inline void write_mepc(uint64_t val) {
    asm volatile("csrw mepc, %0" : : "r"(val));
}

#define SSTATUS_SPP (1L << 8)  /* Previous mode, 1=Supervisor, 0=User */
#define SSTATUS_SPIE (1L << 5) /* Supervisor Previous Interrupt Enable */
#define SSTATUS_UPIE (1L << 4) /* User Previous Interrupt Enable */
#define SSTATUS_SIE (1L << 1)  /* Supervisor Interrupt Enable */
#define SSTATUS_UIE (1L << 0)  /* User Interrupt Enable */

static inline uint64_t read_sstatus() {
    uint64_t val;
    asm volatile("csrr %0, sstatus" : "=r"(val));
    return val;
}

static inline void write_sstatus(uint64_t val) {
    asm volatile("csrw sstatus, %0" : : "r"(val));
}

// Supervisor Interrupt Pending
static inline uint64_t read_sip() {
    uint64_t val;
    asm volatile("csrr %0, sip" : "=r"(val));
    return val;
}

static inline void write_sip(uint64_t val) {
    asm volatile("csrw sip, %0" : : "r"(val));
}

/* Supervisor Interrupt Enable */
#define SIE_SEIE (1L << 9) /* external */
#define SIE_STIE (1L << 5) /* timer */
#define SIE_SSIE (1L << 1) /* software */
static inline uint64_t

read_sie() {
    uint64_t val;
    asm volatile("csrr %0, sie" : "=r"(val));
    return val;
}

static inline void write_sie(uint64_t val) {
    asm volatile("csrw sie, %0" : : "r"(val));
}

/* Machine-mode Interrupt Enable */
#define MIE_MEIE (1L << 11) /* external */
#define MIE_MTIE (1L << 7)  /* timer */
#define MIE_MSIE (1L << 3)  /* software */
static inline uint64_t read_mie() {
    uint64_t val;
    asm volatile("csrr %0, mie" : "=r"(val));
    return val;
}

static inline void write_mie(uint64_t val) {
    asm volatile("csrw mie, %0" : : "r"(val));
}

/* supervisor exception program counter, holds the */
/* instruction address to which a return from */
/* exception will go. */
static inline void write_sepc(uint64_t val) {
    asm volatile("csrw sepc, %0" : : "r"(val));
}

static inline uint64_t read_sepc() {
    uint64_t val;
    asm volatile("csrr %0, sepc" : "=r"(val));
    return val;
}

/* Machine Exception Delegation */
static inline uint64_t read_medeleg() {
    uint64_t val;
    asm volatile("csrr %0, medeleg" : "=r"(val));
    return val;
}

static inline void write_medeleg(uint64_t val) {
    asm volatile("csrw medeleg, %0" : : "r"(val));
}

/* Machine Interrupt Delegation */
static inline uint64_t read_mideleg() {
    uint64_t val;
    asm volatile("csrr %0, mideleg" : "=r"(val));
    return val;
}

static inline void write_mideleg(uint64_t val) {
    asm volatile("csrw mideleg, %0" : : "r"(val));
}

/* Supervisor Trap-Vector Base Address */
/* low two bits are mode. */
static inline void write_stvec(uint64_t val) {
    asm volatile("csrw stvec, %0" : : "r"(val));
}

static inline uint64_t read_stvec() {
    uint64_t val;
    asm volatile("csrr %0, stvec" : "=r"(val));
    return val;
}

/* Machine-mode interrupt vector */
static inline void write_mtvec(uint64_t val) {
    asm volatile("csrw mtvec, %0" : : "r"(val));
}

/* Physical Memory Protection */
static inline void write_pmpcfg0(uint64_t val) {
    asm volatile("csrw pmpcfg0, %0" : : "r"(val));
}

static inline void write_pmpaddr0(uint64_t val) {
    asm volatile("csrw pmpaddr0, %0" : : "r"(val));
}

/* use riscv's sv39 page table scheme. */
#define SATP_SV39 (8L << 60)

#define MAKE_SATP(pagetable) (SATP_SV39 | (((uint64_t)pagetable) >> 12))

/* supervisor address translation and protection; */
/* holds the address of the page table. */
static inline void write_satp(uint64_t val) {
    asm volatile("csrw satp, %0" : : "r"(val));
}

static inline uint64_t read_satp() {
    uint64_t val;
    asm volatile("csrr %0, satp" : "=r"(val));
    return val;
}

static inline void write_mscratch(uint64_t val) {
    asm volatile("csrw mscratch, %0" : : "r"(val));
}

/* Supervisor Trap Cause */
static inline uint64_t read_scause() {
    uint64_t val;
    asm volatile("csrr %0, scause" : "=r"(val));
    return val;
}

/* Supervisor Trap Value */
static inline uint64_t read_stval() {
    uint64_t val;
    asm volatile("csrr %0, stval" : "=r"(val));
    return val;
}

/* Machine-mode Counter-Enable */
static inline void write_mcounteren(uint64_t val) {
    asm volatile("csrw mcounteren, %0" : : "r"(val));
}

static inline uint64_t read_mcounteren() {
    uint64_t val;
    asm volatile("csrr %0, mcounteren" : "=r"(val));
    return val;
}

/* machine-mode cycle counter */
static inline uint64_t read_time() {
    uint64_t val;
    asm volatile("csrr %0, time" : "=r"(val));
    return val;
}

/* enable device interrupts */
static inline void intr_on() { write_sstatus(read_sstatus() | SSTATUS_SIE); }

/* disable device interrupts */
static inline void intr_off() { write_sstatus(read_sstatus() & ~SSTATUS_SIE); }

/* are device interrupts enabled? */
static inline int intr_get() {
    const uint64_t val = read_sstatus();
    return (val & SSTATUS_SIE) != 0;
}

static inline uint64_t read_sp() {
    uint64_t val;
    asm volatile("mv %0, sp" : "=r"(val));
    return val;
}

static inline uint64_t read_tp() {
    uint64_t val;
    asm volatile("mv %0, tp" : "=r"(val));
    return val;
}

static inline void write_tp(uint64_t val) {
    asm volatile("mv tp, %0" : : "r"(val));
}

static inline uint64_t read_ra() {
    uint64_t val;
    asm volatile("mv %0, ra" : "=r"(val));
    return val;
}

#endif /* KERNEL_HW_REG_H_ */
