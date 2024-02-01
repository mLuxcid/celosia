#ifndef KERNEL_HW_PLIC_H_
#define KERNEL_HW_PLIC_H_

namespace hw {
namespace plic {

void init(void);
void claim(void);

}  // namespace plic
}  // namespace hw

#endif /* KERNEL_HW_PLIC_H_ */
