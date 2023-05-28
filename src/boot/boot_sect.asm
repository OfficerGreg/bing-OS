[org 0x7c00]
KERNEL_OFFSET equ 0x1000	; CONSTANT = memory offset which will load the kernel
	mov [BOOT_DRIVE], dl	; BIOS stores boot drive in dl
	
	mov bp, 0x9000		; setup the stack
	mov sp, bp		

	mov bx, MSG_REAL_MODE	; print starting 16 bits real mode
	call print
	call print_nl
	
	call load_kernel	; load the kernel

	call switch_to_pm	; switch to protected mode

	jmp $


%include "boot_sect_print.asm"
%include "boot_sect_print_hex.asm"

%include "boot_sect_disk.asm"

%include "32bit_gdt.asm"
%include "32bit_print.asm"
%include "32bit_switch.asm"

[bits 16]
load_kernel:
	mov bx, MSG_LOAD_KERNEL	; Print load kernel msg
	call print
	call print_nl

	mov bx, KERNEL_OFFSET	; mov offset -> load sectors
	mov dh, 15		; load first 15 sectors
	mov dl, [BOOT_DRIVE]	
	call disk_load

	ret

[bits 32]
; ready to switch

BEGIN_PM:
	mov ebx, MSG_PROT_MODE	; print that we are in 32 bit
	call print_string_pm

	call KERNEL_OFFSET	; jump to address where kernel code is loaded

	jmp $

BOOT_DRIVE	db 0

MSG_REAL_MODE	db "Starting in 16-bit real mode", 0

MSG_PROT_MODE	db "Successfully entered 32-bit Protected Mode!", 0

MSG_LOAD_KERNEL	db "Loading kernel into memory ...", 0

times 510-($-$$) db 0
dw 0xaa55
