#include <xc.h>
#include "pong_ctrl.h"
#include "../hal/lcd/lcd_lowlevel.h"

void Pong_init(Pong* me) {
    Paddle_init(&(me->leftPaddle), true);
    Paddle_init(&(me->rightPaddle), false);
    Ball_init(&(me->ball));
    
    me->state = Pong_idle;
    me->oldState = Pong_idle;
}

void Pong_startBehavior(Pong* me) {
    Paddle_startBehavior(&(me->leftPaddle));
    Paddle_startBehavior(&(me->rightPaddle));
    
    me->state = Pong_idle;
    me->oldState = Pong_idle;
    
    XF_scheduleTimer(30, Pong_stepEv, false);
}

void Pong_SM(Pong* me, Event ev) {
    Paddle_SM(&(me->leftPaddle), ev);
    Paddle_SM(&(me->rightPaddle), ev);
    
    bool eventConsumed = false;
    me->oldState = me->state;
    
    switch(me->state) {
        case Pong_idle:
            if (ev == Pong_stepEv) {
                me->state = Pong_update;
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
    
    if(rightPad->posY + PADDLE_HEIGHT/2 < ball->posY + BALL_SIZE/2) {
        rightPad->speedY = PADDLE_SPEED/2;
    } else {
        rightPad->speedY = -PADDLE_SPEED/2;
    }
    
    Paddle_step(leftPad);
    Paddle_step(rightPad);
    Ball_step(ball);
    
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