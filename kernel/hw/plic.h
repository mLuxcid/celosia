#ifndef KERNEL_HW_PLIC_H_
#define KERNEL_HW_PLIC_H_

namespace hw {
namespace plic {

/* Initialize the PLIC to listen to specific interrupts */
void init(void);

/* Initialize the PLIC on the current core */
void init_local(void);

/* ask which interrupt should be served */
void claim(void);

/* we served this IRQ */
void complete(int irq);

} /* namespace plic */
} /* namespace hw */

#endif /* KERNEL_HW_PLIC_H_ */
