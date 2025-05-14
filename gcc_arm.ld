/* Linker script for Cortex-M55 */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 256K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM

    .heap :
    {
        . = ALIGN(8);
        __heap_start__ = .;
        . = . + 0x1000;
        . = ALIGN(8);
        __heap_end__ = .;
    } > RAM

    .stack :
    {
        . = ALIGN(8);
        __stack_start__ = .;
        . = . + 0x1000;
        . = ALIGN(8);
        __stack_end__ = .;
    } > RAM
}
