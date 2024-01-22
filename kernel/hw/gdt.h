#ifndef CYCLE_KERNEL_HW_GDT_H_
#define CYCLE_KERNEL_HW_GDT_H_

#include <sys/types.h>

namespace hw {
namespace gdt {

class __attribute__((packed)) Entry {};

}  // namespace gdt
}  // namespace hw

#endif  // CYCLE_KERNEL_HW_GDT_H_
