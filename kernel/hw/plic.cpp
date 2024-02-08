#include <hw/plic.h>
#include <hw/reg.h>
#include <sys/types.h>
#include <target/boardconfig.h>
#include <target/kconfig.h>

namespace hw {
namespace plic {

void init(void) { *(uint32_t *)(PLIC_ADDR + UART_INTR_OFFSET) = 1; }
void init_local(void) {
    // uint hart = read_tp();
    // *(uint32_t *)PLIC_SENABLE(hart) = (1 << UART_INTR_OFFSET);
}

} /* namespace plic */
} /* namespace hw */
