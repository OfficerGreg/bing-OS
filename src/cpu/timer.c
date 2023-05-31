#include "timer.h"
#include "isr.h"
#include "ports.h"

#include "../libc/function.h"


u32 tick;

static void timer_callback(registers_t regs){
    tick++;
    UNUSED(regs);
    //Debug    
    // kprint("Tick: ");
    // kprint_num(tick);
    // kprint("\n");
}

void init_timer(u32 frequency){
    register_interrupt_handler(IRQ0, &timer_callback);

    // The value we send to the PIT is the value to divide it's input clock
    // (1193180 Hz) by, to get our required frequency. Important to note is
    // that the divisor must be small enough to fit into 16-bits.
    u32 divisor = 1193180 / frequency;

    // divisor has to be sent byte-wise
    u8 low = (u8)(divisor & 0xFF);
    u8 high = (u8)((divisor >> 8) & 0xFF);

    // Send out command byte
    port_byte_out(0x43, 0x36);

    // Send out freq divisor
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);

}