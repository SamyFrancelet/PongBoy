/*
 * File:   main.c
 * Author: Samy Francelet
 *
 * Created on 3. septembre 2021, 09:15
 */


#include <xc.h>

#include "pongboy/pongboy.h"

/**
 * Interruption routine
 * 
 * Timer0 is the XF timer
 * 
 * INT0 is the TouchScreen detection interrupt
 * 
 * @author Samy Francelet
 */
void __interrupt() isr(void) {
    // Interrupt on TIMER0
    if(TMR0IF == 1 && TMR0IE == 1)
    {
        TMR0IF = 0;         // reset interrupt flag
        TMR0 = 65535-1250;  // reload timer
        XF_decrementAndQueueTimers();
    }

    // Press on screen detected
    if (INT0IF == 1 && INT0IE == 1)
    {
        INT0IF = 0;
        if(INTEDG0 == 1) { // If on rising edge
            XF_pushEvent(TSC_evRelease, true);
        } else {
            XF_pushEvent(TSC_evPress, true);
        }
    }
}

/**
 * Initialise the PongBoy
 * and calls the event execution routine
 * 
 * @author Samy Francelet
 */
void main(void) {
    
    PongBoy_init();
    PongBoy_start();
    
    while(true) {
        PongBoy_execEvent();
    }
        
    return;
}
