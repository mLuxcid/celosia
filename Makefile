MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

.PHONY: all kernel drivers userspace initrd
all: kernel

kernel:
	make -C kernel

# TODO: implement these
initrd:
	$(echo)

drivers:
	$(echo)

userspace:
	$(echo)

.PHONY: clean
clean:
	make -C kernel clean

