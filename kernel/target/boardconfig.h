/* boardconfig.h for QEMU's virt machine */

/* UART0 */
#define UART0_ADDR 0x10000000
#define UART_INTR_OFFSET 10

/* The PLIC & CLINT */
#define PLIC_ADDR 0xc000000
#define CLINT_ADDR 0x2000000

/* Enabled the PLIC in machine-mode */
#define PLIC_MENABLE(hart) (PLIC_ADDR + 0x2000 + (hart) * 0x100)

/* Enabled the PLIC in supervisor-mode */
#define PLIC_SENABLE(hart) (PLIC_ADDR + 0x2080 + (hart) * 0x100)

/* Set machine-mode priority threshold */
#define PLIC_MPRIORITY(hart) (PLIC + 0x200000 + (hart) * 0x2000)

/* Set supervisor-mode priority threshold */
#define PLIC_SPRIORITY(hart) (PLIC + 0x201000 + (hart) * 0x2000)
