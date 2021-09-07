#include <string.h>
#include <stdio.h>

#include "display.h"
#include "../hal/lcd/lcd_lowlevel.h"
#include "../pongboy/pongboy.h"
#include "../app/pong_ctrl.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

void Display_init(Display* me) {
    me->state = Display_menu;
    me->oldState = Display_menu;
    
    LCD_Init();
    LCD_PowerOn();
    
    LCD_Fill(BG_COLOR);
}

void Display_startBehavior(Display* me) {
    me->state = Display_menu;
    me->oldState = Display_menu;
    
    XF_pushEvent(Menu_redraw, false);
}

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
                if(menu->state == Menu_main) {
                    LCD_Fill(BG_COLOR);
                    LCD_ButtonDraw(&(menu->SinglePlayerBtn));
                } else if (menu->state == Menu_settings) {
                    
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