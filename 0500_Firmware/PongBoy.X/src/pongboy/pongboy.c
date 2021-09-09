/* 
 * File:   pongboy.c
 * Author: Samy Francelet
 *
 * Created on 3. septembre 2021, 10:29
 */

#include <xc.h>

#include "pongboy.h"
#include "../hal/lcd/lcd_lowlevel.h"
#include "../xf/xf.h"

TSC tsc;
Menu menu;
Pong pong;
Display disp;

TimerID sleepID;

/**
 * Initialise everything for the PongBoy to work
 * timers, interrupts, every state machines
 * 
 * @author Samy Francelet
 */
void PongBoy_init() {
    // Start the PLL
    PLLEN = 1;           // activate PLL x4
    OSCCON = 0b01110000; // for 64MHz cpu clock (default is 8MHz)
    __delay_ms(100);     // Caution -> the PLL needs up to 2 [ms] to start !  
    
    // TIMER0 10 ms
    T0CON=0b10000110;    // Timer 0 on, source OSC/4, prescaler is 128
    //TMR0=65535-1250;     // Count to this value @ 128kHz is 10 ms
    TMR0 = 65535 - 33395; // Count to this value @ 128kHz is 5 ms
    
    // Intialise execution framework
    XF_init();
    
    // Interrupts
    GIE = 1;            // enable global interrupts
    
    TMR0IE = 1;         // Enable interrupt for timer 0
    
    INTEDG0 = 0;        // Falling edge
    INT0IE = 0;         // Disable INT0

    TSC_init(&tsc);
    Menu_init(&menu);
    Pong_init(&pong);
    Display_init(&disp);
}

/**
 * Starts the behavior of every state machines
 * 
 * @author Samy Francelet
 */
void PongBoy_start() {
    TSC_startBehavior(&tsc);
    Menu_startBehavior(&menu);
    Pong_startBehavior(&pong);
    Display_startBehavior(&disp);
    
    sleepID = XF_scheduleTimer(SLEEP_TIME, sleep_ev, false);
}

/**
 * Pop an event from the XF buffer
 * and sends it to state machines
 * Manages the sleep event
 * 
 * @author Samy Francelet
 */
void PongBoy_execEvent() {
    Event ev;
    ev = XF_popEvent(false);
    
    if (ev != NULLEVENT) {
        TSC_SM(&tsc, ev);
        Menu_SM(&menu, ev);
        Pong_SM(&pong, ev);
        Display_update(&disp, ev);
        
        if(ev == sleep_ev) {
            guteNacht();
        } else if (ev == TSC_evTSC) {
            XF_unscheduleTimer(sleepID, false);
            sleepID = XF_scheduleTimer(SLEEP_TIME, sleep_ev, false);
        } 
    }
}

/**
 * Executes the sleep routine
 * 
 * @author Samy Francelet
 */
void guteNacht() {
    Display_sleep(&disp);
    Sleep();
    
    // Instructions on wake-up
    PongBoy_init();
    PongBoy_start();
}

/**
 * @return the TouchScreen controller
 * 
 * @author Samy Francelet
 */
TSC* PongBoy_getTSC() {
    return &tsc;
}

/**
 * @return the Game controller
 * 
 * @author Samy Francelet
 */
Pong* PongBoy_getGame() {
    return &pong;
}

/**
 * @return the Menu controller
 * 
 * @author Samy Francelet
 */
Menu* PongBoy_getMenu() {
    return &menu;
}