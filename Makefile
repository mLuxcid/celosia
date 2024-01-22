MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

.PHONY: all
all: kernel

kernel: FORCE
	make -C kernel
	mkdir -p build
	cp kernel/$(BUILD)/$(KERNEL) $(BUILD)/$(KERNEL)

# TODO: implement these
initrd:
	$(echo)

drivers:
	$(echo)

userspace:
	$(echo)

.PHONY: clean
clean:
	rm -rf $(BUILD)

FORCE: ;
