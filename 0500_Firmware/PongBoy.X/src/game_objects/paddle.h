/* 
 * File:   paddle.h
 * Author: samy
 *
 * Created on 3. septembre 2021, 13:24
 */

#ifndef PADDLE_H
#define	PADDLE_H

#include "../xf/xf.h"
#include "../board/tsc/tsc.h"
#include "../board/lcd/lcd_highlevel.h"

#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 40
#define PADDLE_SPEED 4

typedef enum {
    Paddle_notMoving,
    Paddle_moving
} Paddle_state;

// Redraw event for every paddle
typedef enum {
    Paddle_redraw = 61,
} Paddle_event;

// Paddle structure definition
typedef struct {
    uint16_t posX;
    uint16_t posY;
    
    uint16_t oldX;
    uint16_t oldY;
    
    int16_t speedX;
    int16_t speedY;
    
    bool isPlayer;
    
    Paddle_state state;
    Paddle_state oldState;
} Paddle;

/**
 * Initialise the paddle object
 * 
 * @param me - paddle object to initialise
 * @param isPlayer - if the paddle is controllable or not
 * 
 * @author Samy Francelet
 */
void Paddle_init(Paddle* me, bool isPlayer);

/**
 * Starting behavior of the paddle state machine
 * 
 * @param me - paddle object
 * 
 * @author Samy Francelet
 */
void Paddle_startBehavior(Paddle* me);

/**
 * Paddle state machine, modify paddle behavior
 * accordingly to the event received
 * 
 * @param me - paddle object
 * @param ev - event to react
 * @return 
 * 
 * @author Samy Francelet
 */
bool Paddle_SM(Paddle* me, Event ev);

/**
 * Draws the paddle with correct color
 * 
 * @param me - paddle to draw
 * @param color - paddle color
 * @param bg_color - pong background color, to erase prev paddle drawn
 * 
 * @author Samy Francelet
 */
void Paddle_draw(Paddle* me, uint16_t color, uint16_t bg_color);

/**
 * Updates paddle position according to speed
 * and throws paddle redraw event
 * 
 * @param me - paddle object
 * 
 * @author Samy Francelet
 */
void Paddle_step(Paddle* me);

#endif	/* PADDLE_H */

