#include <sys/types.h>

uint8_t *uart0_base = (uint8_t *)0x10000000;

static void putc(int c) { *uart0_base = c; }
static void puts(const char *s) {
  while (*s != '\0') {
    putc(*s);
    s++;
  }
}

void kernel_entry(void) { puts("Hello, world!\r\n"); }
