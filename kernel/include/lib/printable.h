#ifndef KERNEL_LIB_PRINTABLE_H_
#define KERNEL_LIB_PRINTABLE_H_

#include <lib/traits.h>

namespace lib {

template <typename T>
concept Printable = requires(T t) {
    { t.print() } -> Same<char *>;
};

}  // namespace lib

#endif /* KERNEL_LIB_PRINTABLE_H_ */
