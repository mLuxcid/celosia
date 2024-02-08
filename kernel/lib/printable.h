#ifndef KERNEL_LIB_PRINTABLE_H_
#define KERNEL_LIB_PRINTABLE_H_

#include <lib/traits.h>

template <typename T>
concept Printable = requires(T t) {
    { t.print() } -> Same<char *>;
};

#endif /* KERNEL_LIB_PRINTABLE_H_ */
