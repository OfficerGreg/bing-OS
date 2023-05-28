[bits 32]
[extern main]	; calling point, same name as void main in kernel.c
call main	; call it
jmp $
