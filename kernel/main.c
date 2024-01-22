#include <limine.h>
#include <stddef.h>

LIMINE_BASE_REVISION(1)

struct limine_framebuffer_request fb_req = {
  .id = LIMINE_FRAMEBUFFER_REQUEST,
  .revision = 0,
};

void halt(void)
{
  asm ("cli");
  for (;;)
    asm ("hlt");
}

void _start(void)
{
  if (!LIMINE_BASE_REVISION_SUPPORTED) {
    halt();
  }

  if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
    halt();
  }

  struct limine_framebuffer *fb = fb_req.response->framebuffers[0];
  uint32_t *fb_addr = fb->address;

  for (size_t x = 0; x < fb->width; x++) {
    for (size_t y = 0; y < fb->height; y++) {
      fb_addr[y * (fb->pitch / 4) + x] = 0xFF00FF; 
    }
  }

  halt();
}
