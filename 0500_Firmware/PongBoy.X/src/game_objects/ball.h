/* 
 * File:   ball.h
 * Author: samy
 *
 * Created on 6. septembre 2021, 10:32
 */

#ifndef BALL_H
#define	BALL_H

#include "../xf/xf.h"

#define BALL_SIZE 6
#define BALL_SPEED 2

// Redraw event for the ball
typedef enum {
    Ball_redraw = 62,
} Ball_event;

// Ball structure definition
typedef struct {
    uint16_t posX;
    uint16_t posY;
    
    uint16_t oldX;
    uint16_t oldY;
        
    int16_t speedX;
    int16_t speedY;
} Ball;

/**
 * Initialise the ball position and speed
 * 
 * @param me - ball object
 * 
 * @author Samy Francelet
 */
void Ball_init(Ball* me);

/**
 * Draws the ball with correct color
 * 
 * @param me - ball to draw
 * @param color - ball color
 * @param bg_color - pong background color, to erase prev ball drawn
 * 
 * @author Samy Francelet
 */
void Ball_draw(Ball* me, uint16_t color, uint16_t bg_color);

/**
 * Updates ball position according to speed
 * and throws ball redraw event
 * 
 * @param me - ball object
 * 
 * @author Samy Francelet
 */
void Ball_step(Ball* me);

#endif	/* BALL_H */

