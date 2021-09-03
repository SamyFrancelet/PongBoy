#include <xc.h>
#include "paddle.h"

void Paddle_init(Paddle* me, bool isPlayer) {
    me->isPlayer = isPlayer;
        
    if (isPlayer) {
        me->posX = 20;
    } else {
        me->posX = 300 - PADDLE_WIDTH;
    }
    
    me->posY = 80;
    
    me->speedX = 0;
    me->speedY = 0;
    
    me->state = Paddle_notMoving;
    me->oldState = Paddle_notMoving;
}

void Paddle_startBehavior(Paddle* me) {
    me->state = Paddle_notMoving;
    me->oldState = Paddle_notMoving;
    
    Paddle_draw(me, WHITE);
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
            }
            break;
            
        default:
            break;
    }
    
    if (me->oldState != me->state) {
        eventConsumed = true;
        
        switch(me->state) {
            case Paddle_notMoving:
                me->speedX = 0;
                me->speedY = 0;
                break;

            case Paddle_moving:
                if (me->isPlayer) {
                    me->speedX = 0;
                    me->speedY = 2;                    
                }
                break;

            default:
                break;
        }
    }
    
    return eventConsumed;
}

void Paddle_draw(Paddle* me, uint16_t color) {
    LCD_DrawRect(me->posX, me->posY, me->posX + PADDLE_WIDTH,
            me->posY + PADDLE_HEIGHT, true, color);
}

void Paddle_step(Paddle* me) {
    
    if (me->speedX != 0 || me->speedY != 0) {
        Paddle_draw(me, BLACK);
        
        me->posX += me->speedX;
        me->posY += me->speedY;
        
        Paddle_draw(me, WHITE);
    }
}