#ifndef KERNEL_LIB_CONS_H_
#define KERNEL_LIB_CONS_H_

#include <lib/printable.h>

#include "hw/uart.h"

namespace lib {

namespace cons {

// Classes must implement the `print` function
template <Printable T>
[[gnu::always_inline]] inline void puts(T const& t) {
    hw::uart::puts(t.print());
}

// primitive types can be printed directly
template <typename T>
[[gnu::always_inline]] inline void puts(T t) {
    hw::uart::puts(t);
}

}  // namespace cons

};  // namespace lib

#endif /* KERNEL_LIB_CONS_H_ */
