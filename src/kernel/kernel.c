#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"

void main() {
    clear_screen();

    isr_install();
    irq_install();

    kprint_at("binq OS v.1.0", 30, 5);
    kprint_at("$ ", 0, 15);    

}

void user_input(char* input){
    if(str_cmp(input, "exit") == 0){
        kprint("baj baj!!.\n");
        asm volatile("hlt");
    }
    kprint(input);
    kprint(": Command not found");
    kprint("\n$ ");
}