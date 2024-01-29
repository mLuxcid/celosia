# roadmap
- [x] basic UART
- [x] SMP working
- [x] switch to supervisor
- [ ] Timer interrupts using the CLINT/ACLINT
- [ ] interrupts & exceptions using the PLIC
- [ ] Memory Managment:
    - [ ] PMM
    - [ ] VMM
    - [ ] Allocator
    - [ ] Paging
- [ ] scheduling
- [ ] IPC
- [ ] syscalls
- [ ] basic kernel filesystem driver (see below)
- [ ] elf loading
- [ ] kernel API
- [ ] userspace
- [ ] drivers

## filesystems
There should be a minimal filesystem driver embedded in the kernel for improved 
speed.
