#include <xc.h>
#include "pong_ctrl.h"
#include "menu_ctrl.h"
#include "../pongboy/pongboy.h"
#include "../display/display.h"
#include "../hal/lcd/lcd_lowlevel.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

void Pong_init(Pong* me) {
    Paddle_init(&(me->leftPaddle), true);
    Paddle_init(&(me->rightPaddle), false);
    Ball_init(&(me->ball));
    
    LCD_ButtonCreate(0, 0, 16, 16, RED, ITEM_COLOR,
        "X", &arialNarrow_12ptFontInfo, NULL, NULL, NULL, 
        &(me->exitBtn), 1);
    
    me->state = Pong_noGame;
    me->oldState = Pong_noGame;
}

void Pong_startBehavior(Pong* me) {
    Paddle_startBehavior(&(me->leftPaddle));
    Paddle_startBehavior(&(me->rightPaddle));
    
    me->state = Pong_noGame;
    me->oldState = Pong_noGame;
}

void Pong_SM(Pong* me, Event ev) {
    Paddle_SM(&(me->leftPaddle), ev);
    Paddle_SM(&(me->rightPaddle), ev);
    
    TSC* tsc;
    
    bool eventConsumed = false;
    me->oldState = me->state;
    
    switch(me->state) {
        case Pong_noGame:
            if (ev == Pong_startGameEv) {
                me->state = Pong_idle;
                me->gameTimer = XF_scheduleTimer(30, Pong_stepEv, false);
            }
            break;
        case Pong_idle:
            if (ev == Pong_stepEv) {
                me->state = Pong_update;
            } else if (ev == TSC_evTSC) {
                tsc = PongBoy_getTSC();
                if (LCD_InButton(&(me->exitBtn), tsc->x, tsc->y)) {
                    XF_pushEvent(Menu_evMenu, false);
                    XF_unscheduleTimer(me->gameTimer, false);
                    me->state = Pong_noGame;
                }
            }
            break;
            
        case Pong_update:
            break;
        default:
            break;
    }
    
    if (me->oldState != me->state) {
        eventConsumed = true;
        
        switch(me->state) {
            case Pong_idle:
                break;

            case Pong_update:
                Pong_step(me);
                me->state = Pong_idle;
                XF_scheduleTimer(30, Pong_stepEv, false);
                break;
            default:
                break;
        }
    }
}

void Pong_step(Pong* me) {
    Paddle* leftPad = &(me->leftPaddle);
    Paddle* rightPad = &(me->rightPaddle);
    Ball* ball = &(me->ball);
    
    detectCollisions(me);
    opposingPaddleControl(me);
        
    Paddle_step(leftPad);
    Paddle_step(rightPad);
    Ball_step(ball);
}

void detectCollisions(Pong* me) {
    Paddle* leftPad = &(me->leftPaddle);
    Paddle* rightPad = &(me->rightPaddle);
    Ball* ball = &(me->ball);
    
    // Collisions
    // Wall collisions :
    if (ball->posY <= 1 || (ball->posY + BALL_SIZE) >= LCD_HEIGHT-1) {
        ball->speedY = -(ball->speedY);
    }
    
    // Out collisions
    if (ball->posX <= 1 || (ball->posX + BALL_SIZE) >= LCD_WIDTH-1) {
        //ball->speedX = -(ball->speedX);
        ball->posX = 70;
        ball->posY = 90;
    }
    
    // Paddle collisions
    bool leftPadColl = (ball->posX <= leftPad->posX + PADDLE_WIDTH + 1
            && ball->posX >= leftPad->posX
            && ball->posY + BALL_SIZE >= leftPad->posY
            && ball->posY <= leftPad->posY + PADDLE_HEIGHT);

    
    bool rightPadColl = (ball->posX + BALL_SIZE + 1 >= rightPad->posX
            && ball->posX <= rightPad->posX
            && ball->posY + BALL_SIZE >= rightPad->posY
            && ball->posY <= rightPad->posY + PADDLE_HEIGHT);
    
    if (leftPadColl) {
        ball->speedX = -(ball->speedX);
    }
    
    if (rightPadColl) {
        ball->speedX = -(ball->speedX);
    }
}

void opposingPaddleControl(Pong* me) {
//    Paddle* leftPad = &(me->leftPaddle);
    Paddle* rightPad = &(me->rightPaddle);
    Ball* ball = &(me->ball);
    
    if(rightPad->posY + PADDLE_HEIGHT/2 < ball->posY + BALL_SIZE/2) {
        rightPad->speedY = PADDLE_SPEED/2;
    } else {
        rightPad->speedY = -PADDLE_SPEED/2;
    }
}