#ifndef KERNEL_LIB_CONS_H_
#define KERNEL_LIB_CONS_H_

#include <lib/printable.h>

namespace lib {

namespace cons {

// Classes must implement the `print` function
template <Printable T>
void puts(T const&);

// primitive types can be printed directly
template <typename T>
void puts(T);

}  // namespace cons

};  // namespace lib

#endif /* KERNEL_LIB_CONS_H_ */
