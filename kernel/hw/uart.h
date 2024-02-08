#ifndef KERNEL_HW_UART_H_
#define KERNEL_HW_UART_H_

#include <sys/types.h>

namespace hw {
namespace uart {

/* initialize the uart lock & configure(TODO)*/
void init(void);

/* write onto UART0 */
void puts(const char *);
void putc(char);

/* read from UART0 */
char getc(void);

}  // namespace uart
}  // namespace hw

#endif /* KERNEL_HW_UART_H_ */
