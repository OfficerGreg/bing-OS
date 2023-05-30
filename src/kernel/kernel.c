#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"


void main() {
    clear_screen();
    /* Fill up the screen */
    int i = 0;
    for (i = 0; i < 24; i++) {
        char str[255];
        int_to_ascii(i, str);
        str_rev(str);
        kprint_at(str, 0, i);
    }
    char testing[] = "!olleHs";
    str_rev(testing);
    

    kprint_at("Testing: ", 60, 24);
    kprint(testing);

    isr_install();
    /* Test the interrupts */
    __asm__ __volatile__("int $2");


}
