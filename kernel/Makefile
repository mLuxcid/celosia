MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

# default compiler toolchain
CC := cc
CXX := c++
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

# C++ specific flags
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions -std=c++20

CPPFLAGS := -I.. -MMD -MP -I../limine/ -Iinclude/

LDFLAGS += -m elf_x86_64 -nostdlib -static -pie \
	--no-dynamic-linker -z text -z max-page-size=0x1000 \
	-T linker.ld

CFILES := $(shell find -L * -type f -name "*.c")
CXXFILES := $(shell find -L * -type f -name "*.cc")
ASFILES := $(shell find -L * -type f -name "*.S")
OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(CXXFILES:.cc=.cc.o) $(ASFILES:.S=.S.o))
HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(CXXFILES:.cc=.cc.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: $(BUILD)/$(KERNEL)

$(BUILD)/$(KERNEL): $(OBJ)
	mkdir -p "$$(dirname $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

-include $(HEADER_DEPS)

obj/%.c.o: %.c
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
 
obj/%.cc.o: %.cc
	mkdir -p "$$(dirname $@)"
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilation rules for *.S files.
obj/%.S.o: %.S
	mkdir -p "$$(dirname $@)"
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD) obj
