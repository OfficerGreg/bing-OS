#include "../drivers/screen.h"

#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

void main() {
    clear_screen();
    /* Fill up the screen */
    int i = 0;
    for (i = 0; i < 24; i++) {
        kprint_num_at(i, 0, i);
    }
    char testing[] = "!olleHs";
    str_rev(testing);
    
    kprint_at("Testing: ", 60, 24);
    kprint(testing);
    kprint_num(10);
    kprint_num_at(20, 65, 0);

    isr_install();
    asm volatile("sti");
    init_timer(10);
    // /* Test the interrupts */
    // __asm__ __volatile__("int $2");


}
