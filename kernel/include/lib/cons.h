#ifndef KERNEL_LIB_CONS_H_
#define KERNEL_LIB_CONS_H_

#include <lib/printable.h>

#include "hw/uart.h"

namespace cons {

// initialize the current console context
void init(void);

// this functions gets called by printf but not by the
// write syscall
// this version requires `T` to implement `print`
template <Printable T>
[[gnu::always_inline]] inline auto puts(T const& t) -> void {
    hw::uart::puts(t.print());
}

// this functions gets called by printf but not by the
// write syscall
// primitive types can be printed directly
template <typename T>
[[gnu::always_inline]] inline auto puts(T t) -> void {
    hw::uart::puts(t);
}

// this function is used by the write syscall
void write(const void*);

}  // namespace cons

#endif /* KERNEL_LIB_CONS_H_ */
