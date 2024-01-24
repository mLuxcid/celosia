.option norvc

.section .text

.align 2
.global _start
.type _start, %function
_start:
    .cfi_startproc

    .option push
    .option norelax
    la gp, global_pointer
    .option pop

    # set up a stack for C.
    la sp, stack_top

    # clear out the bss section
    la t5, bss_start
    la t6, bss_end
bss_clear:
    sd zero, (t5)
    addi t5, t5, 8
    bltu t5, t6, bss_clear


    call kernel_entry

    .cfi_endproc

.end
