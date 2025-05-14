ENTRY(Reset_Handler)

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
    } > FLASH

    .data : AT(_etext) {
        _data = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM

    .bss : {
        _bss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        . = ALIGN(8);
        _end = .;
        __end__ = .;
    } > RAM

    .ARM.attributes 0 : { *(.ARM.attributes) }

    /* Set stack top to end of RAM */
    __stack = ORIGIN(RAM) + LENGTH(RAM);
    _estack = __stack;

    /* Check if data + stack exceeds RAM limit */
    ASSERT(__stack >= _end, "region RAM overflowed")
}
