#include <hw/uart.h>
#include <lib/cons.h>
#include <lib/printable.h>

namespace lib {
namespace cons {

template <Printable T>
void puts(T const& t) {
    hw::uart::puts(t.print());
}

template <typename T>
void puts(T t) {
    hw::uart::puts(t);
}

}  // namespace cons
}  // namespace lib
