#include <kernel/hw/gdt.h>
#include <limine.h>
#include <sys/types.h>

LIMINE_BASE_REVISION(1)

limine_framebuffer_request framebuffer_req = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = nullptr,
};

void halt(void) {
  __asm__("cli");
  for (;;) __asm__("hlt");
}

extern "C" void kernel_entry(void) {
  if (!LIMINE_BASE_REVISION_SUPPORTED) {
    halt();
  }

  if (framebuffer_req.response == nullptr ||
      framebuffer_req.response->framebuffer_count < 1) {
    halt();
  }

  const limine_framebuffer *framebuffer =
      framebuffer_req.response->framebuffers[0];
  uint32_t *framebuffer_addr =
      reinterpret_cast<uint32_t *>(framebuffer->address);

  for (size_t x = 0; x < framebuffer->width; x++) {
    for (size_t y = 0; y < framebuffer->height; y++) {
      framebuffer_addr[y * (framebuffer->pitch / 4) + x] = 0xFF00FF;
    }
  }

  halt();
}
