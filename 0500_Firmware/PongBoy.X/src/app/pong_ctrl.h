/* 
 * File:   pong_ctrl.h
 * Author: samy
 *
 * Created on 3. septembre 2021, 13:42
 */

#ifndef PONG_CONTROLLER_H
#define	PONG_CONTROLLER_H

#include "../game_objects/paddle.h"

typedef enum {
    Pong_reset,
    Pong_start,
    Pong_idle,
    Pong_update
} Pong_state;

typedef enum {
    Pong_startGameEv = 51,
    Pong_resumeGameEv = 52,
    Pong_stepEv = 53
} Pong_event;

typedef struct {
    Paddle leftPaddle;
    Paddle rightPaddle;
    
    Pong_state state;
    Pong_state oldState;
} Pong;

void Pong_init(Pong* me);
void Pong_startBehavior(Pong* me);
void Pong_SM(Pong* me, Event ev);
void Pong_step(Pong* me);

#endif	/* PONG_CONTROLLER_H */

