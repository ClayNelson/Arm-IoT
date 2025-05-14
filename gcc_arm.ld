ENTRY(Reset_Handler)

PHDRS
{
  headers PT_PHDR PHDRS ;
  text PT_LOAD FILEHDR PHDRS ;
  data PT_LOAD ;
}

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 256K
}

SECTIONS
{
  .text : {
    KEEP(*(.vectors))
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
    _etext = .;
  } >FLASH :text

  .data : {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } >RAM AT>FLASH :data

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } >RAM

  .stack (NOLOAD) : {
    . = ALIGN(8);
    . = . + 0x1000;
    . = ALIGN(8);
  } >RAM

  _end = .;

  /* Set stack top to end of RAM */
  __stack = ORIGIN(RAM) + LENGTH(RAM);
  _estack = __stack;

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
