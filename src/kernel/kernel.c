#include "../drivers/ports.h"

void main(){
	port_byte_out(0x3d4, 14);	// 0x3d4 VGA control register

	int position = port_byte_in(0x3d5);
	position = position << 8;

	port_byte_out(0x3d4, 15);
	position += port_byte_in(0x3d4);

	int offset_from_vga = position * 2;

    	char* vga = 0xb8000;
    	vga[offset_from_vga] = 'X';
	vga[offset_from_vga+1] = 0x0f;
}
