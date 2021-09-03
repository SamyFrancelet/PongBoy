/* 
 * File:   pongboy.c
 * Author: Samy Francelet
 *
 * Created on 3. septembre 2021, 10:29
 */

#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "pongboy.h"
#include "../xf/xf.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

TSC tsc;

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
    
    LCD_Init();
    
    LCD_Fill(BLACK);

//    LCD_DrawRect(100,100,150,150,1,YELLOW);

//    LCD_DrawText("Hello friend", &arialNarrow_12ptFontInfo,
//            A_LEFT, 50, 50, WHITE, BLACK);

    TSC_Init(&tsc);
}

void PongBoy_build() {
    
}

void PongBoy_start() {
    TSC_startBehavior(&tsc);
}

void PongBoy_execEvent() {
    Event ev;
    ev = XF_popEvent(false);
    
    if (ev != NULLEVENT) {
        TSC_SM(&tsc, ev);
        
        if (ev == TSC_evTSC) {
            char txt[20];
            
            sprintf(txt, "X=%03d", tsc.x);
            LCD_DrawText(txt, &arialNarrow_12ptFontInfo,
                    A_LEFT, 50, 50, WHITE, BLACK);

            sprintf(txt, "Y=%03d", tsc.y);
            LCD_DrawText(txt, &arialNarrow_12ptFontInfo,
                    A_LEFT, 150, 50, WHITE, BLACK);
        }
    }
}