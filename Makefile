MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

.PHONY: all kernel drivers userspace initrd
all: kernel

kernel:
	@./cel-build build celosia-kernel

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

