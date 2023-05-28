; GDT
gdt_start:
    dd  0x0         ;   4 bytes
    dd  0x0         ;   4 bytes * 2 = 8 bytes


gdt_code:
    dw  0xffff      ;   Limit   (bits 0 - 15)
    dw  0x0         ;   Base    (bits 0 - 15)
    db  0x0         ;   Base    (bits 16 - 23)
    db  10011010b   ;   1st flag
    db  11001111b   ;   2nd flag
    db  0x0         ;   Base    (bits 24- 31)
    
gdt_data:
    dw  0xffff      ;   Limit   (bits 0 - 15)
    dw  0x0         ;   Base    (bits 0 - 15)
    db  0x0         ;   Base    (bits 16 - 23)
    db  10010010b   ;   1st flag
    db  11001111b   ;   2nd flag
    db  0x0         ;   Base    (bits 24- 31)
    
gdt_end:            ;   this is so that the assembler can calculate the size of the GDT for the GDT descriptor

;   GDT descriptior
gdt_descriptor:
    dw gdt_end - gdt_start - 1  ;   Size of GDT
    
    dd gdt_start                ;   Start address of GDT


; Define some handy constants for the GDT segment descriptor offsets , which
; are what segment registers must contain when in protected mode. For example ,
; when we set DS = 0 x10 in PM , the CPU knows that we mean it to use the
; segment described at offset 0 x10 ( i.e. 16 bytes ) in our GDT , which in our
; case is the DATA segment (0 x0 -> NULL ; 0x08 -> CODE ; 0 x10 -> DATA )
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start