MAKEFLAGS += -rR

# Kernel options
BUILD := build
KERNEL := cycle

# default compiler toolchain
CC := cc
LD := ld
AS := as

CFLAGS := -O2 -ggdb
LDFLAGS :=
ASFLAGS :=

# these flags shouldn't be changed
CFLAGS += -nostdlib -ffreestanding \
	-fno-stack-protector -fno-stack-check -fno-lto \
	-fPIE -m64 -march=x86-64 -mno-80387 -mno-mmx -mno-sse \
    	-mno-sse2 -mno-red-zone \
	-Wall -Werror -Wextra -pedantic

CPPFLAGS := -I. -MMD -MP -Ilimine/

LDFLAGS += -m elf_x86_64 -nostdlib -static -pie \
	--no-dynamic-linker -z text -z max-page-size=0x1000 \
	-T kernel/linker.ld

CFILES := $(shell cd kernel && find -L * -type f -name "*.c")
ASFILES := $(shell cd kernel && find -L * -type f -name "*.S")
OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.S=.S.o))
HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: $(BUILD)/$(KERNEL)

$(BUILD)/$(KERNEL): $(OBJ)
	mkdir -p "$$(dirname $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

-include $(HEADER_DEPS)

obj/%.c.o: kernel/%.c
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
 
# Compilation rules for *.S files.
obj/%.S.o: kernel/%.S
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD) obj
