#include "display.h"
#include "../pongboy/pongboy.h"
#include "../app/pong_ctrl.h"

void Display_init(Display* me) {
    me->state = Display_menu;
    me->oldState = Display_menu;
    
    LCD_Init();
    
    LCD_Fill(BG_COLOR);
}

void Display_startBehavior(Display* me) {
    me->state = Display_game;
    me->oldState = Display_game;
    
    Pong* pong = PongBoy_getGame();
    Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
    Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
    Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
}

bool Display_update(Display* me, Event ev) {
    bool eventConsumed = false;
    me->oldState = me->state;
    
    Pong* pong;
    
    switch(me->state) {
        case Display_menu:
            if (ev == evStartGame) {
                me->state = Display_game;
            }
            break;
            
        case Display_game:
            if (ev == evMenu) {
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
                break;
                
            case Display_game:
                pong = PongBoy_getGame();
                Paddle_draw(&(pong->leftPaddle), ITEM_COLOR, BG_COLOR);
                Paddle_draw(&(pong->rightPaddle), ITEM_COLOR, BG_COLOR);
                Ball_draw(&(pong->ball), ITEM_COLOR, BG_COLOR);
                break;
        }
    }
    
    return eventConsumed;
}