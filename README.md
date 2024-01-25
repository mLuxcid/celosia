Celosia src tree.


To build the project, you'll need a risc-v cross compiler and the configuration 
for you SOC. By default, the project provides files for QEMUs virt target (which
 is compiled for by default) and a few SOCs. You'll either have to copy
 `boardconfig.h` from the `boards` directory or provide your own.

To now build the system
```
make -j$(nproc)
```


To run the project in QEMU, run the following command:
```
qemu-system-riscv64 -kernel build/celosia -machine virt -bios none -m 128M -nographic -serial mon:stdio
```
