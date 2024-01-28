.section .text

# I may have stolen a bit from xv6 :3
.section .text.init
.global _start
.type _start, %function
_start:
    la sp, stack0
    li a0, 1024 * 4 
    csrr a1, mhartid
    addi a1, a1, 1
    mul a0, a0, a1
    add sp, sp, a0

    call kernel_entry

1:
    j 1b
