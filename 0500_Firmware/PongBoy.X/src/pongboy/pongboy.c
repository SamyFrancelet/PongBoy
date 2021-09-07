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

TimerID tmrID;

void PongBoy_init() {
    // Start the PLL
    PLLEN = 1;           // activate PLL x4
    OSCCON = 0b01110000; // for 64MHz cpu clock (default is 8MHz)
    __delay_ms(100);     // Caution -> the PLL needs up to 2 [ms] to start !  
    
    // TIMER0 10 ms
    T0CON=0b10000110;    // Timer 0 on, source OSC/4, prescaler is 128
    TMR0=65535-1250;     // Count to this value @ 128kHz is 10 ms
    
    // Intialise execution framework
    XF_init();
    
    // Interrupts
    GIE = 1;            // enable global interrupts
    
    TMR0IE = 1;         // Enable interrupt for timer 0
    
    INTEDG0 = 0;        // Falling edge
    INT0IE = 0;         // Disable INT0

//    LCD_DrawRect(100,100,150,150,1,YELLOW);

//    LCD_DrawText("Hello friend", &arialNarrow_12ptFontInfo,
//            A_LEFT, 50, 50, WHITE, BLACK);

    TSC_init(&tsc);
    Menu_init(&menu);
    Pong_init(&pong);
    Display_init(&disp);
}

void PongBoy_build() {
    
}

void PongBoy_start() {
    TSC_startBehavior(&tsc);
    Menu_startBehavior(&menu);
    Pong_startBehavior(&pong);
    Display_startBehavior(&disp);
    
    tmrID = XF_scheduleTimer(10000, SLEEP_EV, false);
}

void PongBoy_execEvent() {
    Event ev;
    ev = XF_popEvent(false);
    
    if (ev != NULLEVENT) {
        TSC_SM(&tsc, ev);
        Menu_SM(&menu, ev);
        Pong_SM(&pong, ev);
        Display_update(&disp, ev);
        
        if(ev == SLEEP_EV) {
            guteNacht();
        } else if (ev == TSC_evTSC) {
            XF_unscheduleTimer(tmrID, false);
            tmrID = XF_scheduleTimer(10000, SLEEP_EV, false);
        }
    }
}

void guteNacht() {
    LCD_nRD = 1;
    LCD_nWR = 1;
    LCD_DnC = 1;
    LCD_nCS = 1;
    
    LCD_DATA_BUS = 0xFF;
    
    LCD_PowerOff();
    Sleep();
    Reset();
}

TSC* PongBoy_getTSC() {
    return &tsc;
}

Pong* PongBoy_getGame() {
    return &pong;
}

Menu* PongBoy_getMenu() {
    return &menu;
}