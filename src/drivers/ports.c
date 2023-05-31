#include "ports.h"


u8 port_byte_in(u16 port){
	u8 result;
	//"=a" == output constraint, specifies that result should be saved in (reslut) AL register
	//"d" == input constraint, specifies that port should be mapped to EDX register
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void port_byte_out(u16 port, u8 data){
	//"a" (data) == load EAX with data
	//"d" (port) == load EDX with port
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}


u16 port_word_in(u16 port){
	u16 result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void port_word_out(u16 port, u16 data){
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}
