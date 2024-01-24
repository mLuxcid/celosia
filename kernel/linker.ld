OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  ram  (wxa) : ORIGIN = 0x80000000, LENGTH = 128M
}

PHDRS
{
  text PT_LOAD;
  data PT_LOAD;
  bss PT_LOAD;
}

SECTIONS
{
  . = 0x80000000;

  .text : {
    *(.text .text.*)
    . = ALIGN(0x1000);
    PROVIDE(etext = .);
  } >ram :text

  .rodata : {
    . = ALIGN(16);
    *(.srodata .srodata.*) /* do not need to distinguish this from .rodata */
    . = ALIGN(16);
    *(.rodata .rodata.*)
  } >ram

  .data : {
    . = ALIGN(16);
    *(.sdata .sdata.*) /* do not need to distinguish this from .data */
    . = ALIGN(16);
    *(.data .data.*)
  } >ram :data

  .bss : ALIGN(4K) {
    PROVIDE(bss_start = .);
    *(.bss)
    . += 8192;
    PROVIDE(stack_top = .);
    . += 8192;
    PROVIDE(global_pointer = .);
    PROVIDE(bss_end = .);
  } >ram :bss

  PROVIDE(end = .);
}
