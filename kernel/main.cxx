#include <limine.h>
#include <types.h>
#include <kernel/hw/gdt.h>

LIMINE_BASE_REVISION(1)

limine_framebuffer_request fb_req = {
  LIMINE_FRAMEBUFFER_REQUEST,
  0,
  NULL,
};

void halt(void) {
  __asm__ ("cli");
  for (;;)
    __asm__ ("hlt");
}

extern "C" void kernel_entry(void) {
  if (!LIMINE_BASE_REVISION_SUPPORTED) {
    halt();
  }

  if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
    halt();
  }

  limine_framebuffer *fb = fb_req.response->framebuffers[0];
  u32 *fb_addr = reinterpret_cast<u32 *>(fb->address);

  for (size_t x = 0; x < fb->width; x++) {
    for (size_t y = 0; y < fb->height; y++) {
      fb_addr[y * (fb->pitch / 4) + x] = 0xFF00FF; 
    }
  }

  halt();
}
