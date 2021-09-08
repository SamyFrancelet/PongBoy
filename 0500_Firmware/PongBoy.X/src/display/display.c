#include <string.h>
#include <stdio.h>

#include "display.h"
#include "../hal/lcd/lcd_lowlevel.h"
#include "../pongboy/pongboy.h"
#include "../app/pong_ctrl.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

/**
 * Initialise the Display object
 * 
 * @param me - Display object to initialise
 * 
 * @author Samy Francelet
 */
void Display_init(Display* me) {
    me->state = Display_menu;
    me->oldState = Display_menu;
    
    me->luminosity = 100;
    
    LCD_Init();
    LCD_PowerOn();
    
    Display_PWM_init(me);
    
    LCD_Fill(BG_COLOR);
}

/**
 * Initialise the PWM for the LCD backlight
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_PWM_init(Display* me) {
    // 1 - Disable CCPx pin output driver by setting the TRIS bit
    LCD_BACKLIGHT_DIR = 1;
    // 2 - Select 8-bit Timer2 to be used with CxTSEL<1:0> bits in CCPTMRSx
    CCPTMRS0bits.C2TSEL = 0b00;
    // 3 - Load PR register
    PR2 = 100;
    // 4 - Configure CCP module for PWM mode
    CCP2CONbits.CCP2M = 0xC;
    // 5 - Load CCPR2L and DCxB bits with PWM duty cycle
    CCPR2L = 100;
    CCP2CONbits.DC2B = 0;
    // 6 - Configure timer2
    TMR2IF = 0; // Clear flag
    T2CONbits.T2CKPS = 0b01;
    T2CONbits.TMR2ON = 1; // activate timer
    // 7 - Enable CCPx output
    LCD_BACKLIGHT_DIR = 0;
}

/**
 * Sets the PWM duty-cycle for the LCD backlight
 * 
 * @param me - Display object
 * @param luminosity - LCD luminosity in (0 to 100)
 * 
 * @author Samy Francelet
 */
void Display_setBackLight(Display* me, uint8_t luminosity) {
    if (luminosity > 100) {
        luminosity = 100;
    }

    CCPR2L = luminosity;
}

/**
 * Sleep routine for the Display
 * Turn off everything and avoid current wells
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_sleep(Display* me) {
    LCD_nRD = 1;
    LCD_nWR = 1;
    LCD_DnC = 1;
    LCD_nCS = 1;
    
    LCD_DATA_BUS = 0xFF;
    
    Display_setBackLight(me, 0);
    CCP2CONbits.CCP2M = 0x0;
    TMR2IF = 0;
    T2CONbits.TMR2ON = 0;
    LCD_PowerOff();
}

/**
 * Starting behavior of the Display state machine
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_startBehavior(Display* me) {
    me->state = Display_menu;
    me->oldState = Display_menu;
    
    XF_pushEvent(Menu_redraw, false);
}

/**
 * Updates display accordingly to the event received
 * 
 * @param me - Display object
 * @param ev - event to react
 * @return 
 * 
 * @author Samy Francelet
 */
bool Display_update(Display* me, Event ev) {
    bool eventConsumed = false;
    me->oldState = me->state;
    
    Pong* pong;
    Menu* menu;
    TSC* tsc;
    
    switch(me->state) {
        case Display_menu:
            if (ev == Pong_startGameEv) {
                me->state = Display_game;
            } else if (ev == Menu_redraw) {
                // Redraws menu
                menu = PongBoy_getMenu();
                LCD_Fill(BG_COLOR);
                if(menu->state == Menu_main) {
                    LCD_ButtonDraw(&(menu->SinglePlayerBtn));
                    LCD_ButtonDraw(&(menu->settingsBtn));
                } else if (menu->state == Menu_settings) {
                    LCD_ButtonDraw(&(menu->SinglePlayerBtn));
                    LCD_SliderDraw(&(menu->backLightSlider));
                    me->luminosity = menu->backLightSlider.value;
                    Display_setBackLight(me, me->luminosity);
                }
            } else if (ev == Menu_refresh) {
                menu = PongBoy_getMenu();
                if(menu->state == Menu_main) {
                    LCD_ButtonUpdate(&(menu->SinglePlayerBtn));
                    LCD_ButtonUpdate(&(menu->settingsBtn));
                } else if (menu->state == Menu_settings) {
                    LCD_ButtonUpdate(&(menu->SinglePlayerBtn));
                    LCD_SliderUpdate(&(menu->backLightSlider));
                    me->luminosity = menu->backLightSlider.value;
                    Display_setBackLight(me, me->luminosity);
                } 
            }
            break;
            
        case Display_game:
            if (ev == Menu_evMenu) {
                me->state = Display_menu;
            } else if (ev == Paddle_redraw) {
                pong = PongBoy_getGame();
                Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
                Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
            } else if (ev == Ball_redraw) {
                pong = PongBoy_getGame();
                Pong_drawMidLine(pong, ITEM_COLOR);
                Pong_drawScore(pong, ITEM_COLOR, BG_COLOR);
                Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
                LCD_ButtonDraw(&(pong->exitBtn));
            }
            break;
            
        default:
            break;
    }
    
    if (me->oldState != me->state) {
        eventConsumed = true;
        
        switch(me->state) {
            case Display_menu:
                menu = PongBoy_getMenu();
                LCD_Fill(BG_COLOR);
                LCD_ButtonDraw(&(menu->SinglePlayerBtn));
                LCD_ButtonDraw(&(menu->settingsBtn));
                break;
                
            case Display_game:
                LCD_Fill(BG_COLOR);
                pong = PongBoy_getGame();
                Pong_drawMidLine(pong, ITEM_COLOR);
                Pong_drawScore(pong, ITEM_COLOR, BG_COLOR);
                Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
                Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
                Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
                LCD_ButtonDraw(&(pong->exitBtn));
                break;
        }
    }
    
    if (ev == dim_ev) {
        Display_setBackLight(me, (me->luminosity)/2);
    } else if (ev == TSC_evPress) {
        Display_setBackLight(me, me->luminosity);
    }
    
    if (ev == TSC_evTSC && DEBUG) {
        tsc = PongBoy_getTSC();
        char txt[20];

        sprintf(txt, "X=%03d", tsc->x);
        LCD_DrawText(txt, &arialNarrow_12ptFontInfo,
            A_LEFT, 0, 0, RED, BG_COLOR);

        sprintf(txt, "Y=%03d", tsc->y);
        LCD_DrawText(txt, &arialNarrow_12ptFontInfo,
            A_RIGHT, 320, 0, RED, BG_COLOR);
    }
    
    return eventConsumed;
}