mov ah, 0x0e        ;teletype BIOS routine

mov bp, 0x7ff0

%include "print.asm"

mov al, "X"
call print

mov al, "T"
call print


jmp $
times 510 - ($-$$) db 0
dw 0xaa55