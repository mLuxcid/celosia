Celosia src tree.


To build the project, you'll need a risc-v cross compiler. 

Then run 
```
make -j$(nproc)
```


To run the project in QEMU, run the following command:
```
qemu-system-riscv64 -kernel build/celosia -machine virt -bios none -m 128M -nographic -serial mon:stdio
```
