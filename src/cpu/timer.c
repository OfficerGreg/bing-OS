#include "timer.h"

#include "isr.h"

#include "../drivers/screen.h"

#include "../kernel/util.h"


u32 tick;


static void timer_callback(registers_t regs){
    tick++;
    kprint("Tick: ");
    char c_tick[255];
}

void init_timer(u32 frequency){

}