#include "ports.h"


unsigned char port_byte_in(unsigned short port){
	unsigned char result;
	//"=a" == output constraint, specifies that result should be saved in (reslut) AL register
	//"d" == input constraint, specifies that port should be mapped to EDX register
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void port_byte_out(unsigned short port, unsigned char data){
	//"a" (data) == load EAX with data
	//"d" (port) == load EDX with port
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}


unsigned short port_word_in(unsigned short port){
	unsigned short result;
	__asm__("in %%dx, %%al" : "=a" (result), "d" (port));
	return result;
}

void port_word_out(unsigned short port, unsigned short data){
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}
