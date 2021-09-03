#include <xc.h>
#include "pong_ctrl.h"

void Pong_init(Pong* me) {
    Paddle_init(&(me->leftPaddle), true);
    Paddle_init(&(me->rightPaddle), false);
    
    me->state = Pong_idle;
    me->oldState = Pong_idle;
}

void Pong_startBehavior(Pong* me) {
    Paddle_startBehavior(&(me->leftPaddle));
    Paddle_startBehavior(&(me->rightPaddle));
    
    me->state = Pong_idle;
    me->oldState = Pong_idle;
    
    XF_scheduleTimer(50, Pong_stepEv, false);
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
                XF_scheduleTimer(50, Pong_stepEv, false);
                break;
            default:
                break;
        }
    }
}

void Pong_step(Pong* me) {
    Paddle_step(&(me->leftPaddle));
    Paddle_step(&(me->rightPaddle));
}