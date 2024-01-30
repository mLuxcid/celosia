#include <hw/uart.h>
#include <lib/cons.h>

namespace cons {

// TODO: setup for the actual current context, right now
// this just sets up UART0
void init(void) { hw::uart::init(); }

}  // namespace cons
