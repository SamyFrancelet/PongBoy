#include <xc.h>
#include "paddle.h"
#include "../pongboy/pongboy.h"
#include "../hal/lcd/lcd_lowlevel.h"

void Paddle_init(Paddle* me, bool isPlayer) {
    me->isPlayer = isPlayer;
        
    if (isPlayer) {
        me->posX = 30;
    } else {
        me->posX = 290 - PADDLE_WIDTH;
    }
    
    me->posY = 120;
    me->oldX = me->posX;
    me->oldY = me->posY;
    
    me->speedX = 0;
    me->speedY = 0;
    
    me->state = Paddle_notMoving;
    me->oldState = Paddle_notMoving;
}

void Paddle_startBehavior(Paddle* me) {
    me->state = Paddle_notMoving;
    me->oldState = Paddle_notMoving;
}

bool Paddle_SM(Paddle* me, Event ev) {
    bool eventConsumed = false;
    me->oldState = me->state;
    
    switch(me->state) {
        case Paddle_notMoving:
            if (ev == TSC_evPress) {
                me->state = Paddle_moving;
            }
            break;
            
        case Paddle_moving:
            if (ev == TSC_evRelease) {
                me->state = Paddle_notMoving;
            } else if (ev == TSC_evTSC && me->isPlayer) {
                uint16_t posY;
                posY = PongBoy_getTSC()->y;
                
                if (posY >= 120 && posY <= 240) { // Bottom
                    me->speedY = PADDLE_SPEED;
                } else if (posY >= 0 && posY < 120){
                    me->speedY = -PADDLE_SPEED;
                }
            }
            break;
            
        default:
            break;
    }
    
    if (me->oldState != me->state) {
        eventConsumed = true;
        
        switch(me->state) {
            case Paddle_notMoving:
                me->speedY = 0;
                break;

            case Paddle_moving:
                /*if (me->isPlayer) {
                    me->speedY = 2;                    
                }*/
                break;

            default:
                break;
        }
    }
    
    return eventConsumed;
}

void Paddle_draw(Paddle* me, uint16_t color, uint16_t bg_color) {
    LCD_DrawRect(me->oldX, me->oldY, me->oldX + PADDLE_WIDTH,
            me->oldY + PADDLE_HEIGHT, true, bg_color);
    
    me->oldX = me->posX;
    me->oldY = me->posY;
    
    LCD_DrawRect(me->posX, me->posY, me->posX + PADDLE_WIDTH,
            me->posY + PADDLE_HEIGHT, true, color);
}

void Paddle_step(Paddle* me) {
    if (me->speedY != 0) {
        
        if ((me->speedY > 0 && me->posY + PADDLE_HEIGHT <= LCD_HEIGHT - 1)
                || (me->speedY < 0 && me->posY >= 1)) {
            me->posY += me->speedY;            
        }
        
        XF_pushEvent(Paddle_redraw, false);
    }
}