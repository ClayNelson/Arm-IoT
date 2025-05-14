ENTRY(Reset_Handler)

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

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM

    /* Set stack top to end of RAM */
    __stack_top = ORIGIN(RAM) + LENGTH(RAM);

    /DISCARD/ :
    {
        *(.note.gnu.build-id)
        *(.ARM.exidx*)
        *(.ARM.extab*)
    }
}
