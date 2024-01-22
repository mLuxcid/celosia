MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

TOOLCHAIN = riscv64-unknown-elf-

# default compiler toolchain
CC := $(TOOLCHAIN)gcc
LD := $(TOOLCHAIN)ld
AS := $(TOOLCHAIN)as

CFLAGS := -O2 -ggdb
LDFLAGS :=
ASFLAGS :=

# these flags shouldn't be changed
CFLAGS += -nostdlib -ffreestanding \
	-fno-stack-protector -fno-stack-check -fno-lto \
	-fPIE -Wall -Werror -Wextra -pedantic \
	-mno-relax -mcmodel=medany -pipe

CPPFLAGS := -I.. -MMD -MP -I../limine/ -Iinclude/

LDFLAGS += -nostdlib \
	-T linker.ld

CFILES := $(shell find -L * -type f -name "*.c")
ASFILES := $(shell find -L * -type f -name "*.S")
OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.S=.S.o))
HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: $(BUILD)/$(KERNEL)

$(BUILD)/$(KERNEL): $(OBJ)
	mkdir -p "$$(dirname $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

-include $(HEADER_DEPS)

obj/%.c.o: %.c
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilation rules for *.S files.
obj/%.S.o: %.S
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD) obj
