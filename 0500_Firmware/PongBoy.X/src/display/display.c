#include "display.h"
#include "../hal/lcd/lcd_lowlevel.h"
#include "../pongboy/pongboy.h"
#include "../app/pong_ctrl.h"

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
    
//    Pong* pong = PongBoy_getGame();
//    Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
//    Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
//    Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
}

bool Display_update(Display* me, Event ev) {
    bool eventConsumed = false;
    me->oldState = me->state;
    
    Pong* pong;
    Menu* menu;
    
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
                Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
                Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
                Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
                LCD_ButtonDraw(&(pong->exitBtn));
                break;
        }
    }
    
    return eventConsumed;
}