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
    
    uint8_t leftScore;
    uint8_t rightScore;
    
    Ball ball;
    
    btn_t exitBtn;
    
    Pong_state state;
    Pong_state oldState;
    
    TimerID gameTimer;
} Pong;

/**
 * Initialise the Pong Game
 * 
 * @param me - PongGame object
 * 
 * @author Samy Francelet
 */
void Pong_init(Pong* me);

/**
 * Starting behavior of the Pong state machine
 * 
 * @param me - PongGame object
 * 
 * @author Samy Francelet
 */
void Pong_startBehavior(Pong* me);

/**
 * Update PongGame state machine
 * accordingly to the event received
 * 
 * @param me - PongGame object
 * @param ev - event to react
 * 
 * @author Samy Francelet
 */
void Pong_SM(Pong* me, Event ev);

/**
 * Update positions of every game objects
 * 
 * @param me - PongGame object
 * 
 * @author Samy Francelet
 */
void Pong_step(Pong* me);

/**
 * Checks is collisions have happened and react accordingly
 * 
 * @param me - PongGame object
 * 
 * @author Samy Francelet
 */
void detectCollisions(Pong* me);

/**
 * AI control of the non-playable paddle
 * 
 * @param me - PongGame object
 * 
 * @author Samy Francelet
 */
void opposingPaddleControl(Pong* me);

/**
 * Draws the mid-line of the pong field
 * 
 * @param me - PongGame object
 * @param color - color of the mid-line
 * 
 * @author Samy Francelet
 */
void Pong_drawMidLine(Pong* me, uint16_t color);

/**
 * Draw the current game score
 * 
 * @param me - PongGame object
 * @param color - score color
 * @param bg_color - background color of the pong game
 * 
 * @author Samy Francelet
 */
void Pong_drawScore(Pong*me, uint16_t color, uint16_t bg_color);

#endif	/* PONG_CONTROLLER_H */

