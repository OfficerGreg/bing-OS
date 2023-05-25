; GDT
gdt_start:

gdt_null:
    dd  0x0     ;   4 bytes
    dd  0x0     ;   4 bytes * 2 = 8 bytes


gdt_code:
    dw  0xffff  ;   Limit (bits 0 - 15)
    dw  0x0     ;   Base (bits 0 - 15)
    db  0x0     ;   Base (bits 16 - 23)
    

