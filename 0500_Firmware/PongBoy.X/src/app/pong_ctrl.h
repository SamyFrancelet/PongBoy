/* 
 * File:   pong_ctrl.h
 * Author: samy
 *
 * Created on 3. septembre 2021, 13:42
 */

#ifndef PONG_CONTROLLER_H
#define	PONG_CONTROLLER_H

#include "../game_objects/paddle.h"
#include "../game_objects/ball.h"
#include "../board/lcd/lcd_highlevel.h"

typedef enum {
    Pong_noGame,
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
    
    Ball ball;
    
    btn_t exitBtn;
    
    Pong_state state;
    Pong_state oldState;
    
    TimerID gameTimer;
} Pong;

void Pong_init(Pong* me);
void Pong_startBehavior(Pong* me);
void Pong_SM(Pong* me, Event ev);
void Pong_step(Pong* me);

void detectCollisions(Pong* me);
void opposingPaddleControl(Pong* me);

#endif	/* PONG_CONTROLLER_H */

