MAKEFLAGS += -rR

BUILD := build
KERNEL := celosia

# determine toolchain
ifndef TOOLCHAIN
TOOLCHAIN := $(shell if riscv64-unknown-elf-objdump -i 2>&1 | grep 'elf64-big' >/dev/null 2>&1; \
	then echo 'riscv64-unknown-elf-'; \
	elif riscv64-linux-gnu-objdump -i 2>&1 | grep 'elf64-big' >/dev/null 2>&1; \
	then echo 'riscv64-linux-gnu-'; \
	elif riscv64-unknown-linux-gnu-objdump -i 2>&1 | grep 'elf64-big' >/dev/null 2>&1; \
	then echo 'riscv64-unknown-linux-gnu-'; \
	else echo "***" 1>&2; \
	echo "*** Error: Couldn't find a riscv64 version of GCC/binutils." 1>&2; \
	echo "*** To turn off this error, run 'gmake TOOLCHAIN= ...'." 1>&2; \
	echo "***" 1>&2; exit 1; fi)
endif

CC := $(TOOLCHAIN)gcc
CXX := $(TOOLCHAIN)g++
LD := $(TOOLCHAIN)ld

CFLAGS := -O -ggdb -gdwarf-2
CXXFLAGS := $(CFLAGS)
LDFLAGS :=
ASFLAGS :=

CFLAGS += -nostdlib -ffreestanding \
		  -fno-stack-protector -fno-stack-check -fno-lto \
		  -fno-pie -no-pie -Wall -Werror -Wextra -pedantic \
		  -mno-relax -mcmodel=medany -pipe -fno-common \

CXXFLAGS += -nostdlib -ffreestanding \
		  -fno-stack-protector -fno-stack-check -fno-lto \
		  -fno-pie -no-pie -Wall -Werror -Wextra -pedantic \
		  -mno-relax -mcmodel=medany -pipe -fno-common \
		  -fno-rtti -fno-exceptions

CPPFLAGS := -I.. -MMD -MP -Iinclude/ -I../conf

LDFLAGS += -nostdlib \
		   -T linker.ld

CFILES := $(shell find -L * -type f -name "*.c")
CXXFILES := $(shell find -L * -type f -name "*.cpp")
ASFILES := $(shell find -L * -type f -name "*.S")
OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(CXXFILES:.cpp=.cpp.o) $(ASFILES:.S=.S.o))
HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(CXXFILES:.cp=.cp.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: $(BUILD)/$(KERNEL)

$(BUILD)/$(KERNEL): $(OBJ)
	mkdir -p "$$(dirname $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

-include $(HEADER_DEPS)

obj/%.c.o: %.c
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.cpp.o: %.cpp
	mkdir -p "$$(dirname $@)"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.S.o: %.S
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD) obj
