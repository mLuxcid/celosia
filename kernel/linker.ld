OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x80000000;

  .text : {
    *(.text .text.*)
    . = ALIGN(0x1000);
    PROVIDE(etext = .);
  }

  .rodata : {
    . = ALIGN(16);
    *(.srodata .srodata.*) /* do not need to distinguish this from .rodata */
    . = ALIGN(16);
    *(.rodata .rodata.*)
  }

  .data : {
    . = ALIGN(16);
    *(.sdata .sdata.*) /* do not need to distinguish this from .data */
    . = ALIGN(16);
    *(.data .data.*)
  }

  .bss : ALIGN(4K) {
    PROVIDE(bss_start = .);
    *(.bss)
    . += 8192;
    PROVIDE(stack_top = .);
    . += 8192;
    PROVIDE(global_pointer = .);
    PROVIDE(bss_end = .);
  }

  PROVIDE(end = .);
}
