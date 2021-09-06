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

//const uint8_t ball_bitmap[] = {
//    
//};

typedef enum {
    Ball_redraw = 62,
} Ball_event;

typedef struct {
    uint16_t posX;
    uint16_t posY;
    
    uint16_t oldX;
    uint16_t oldY;
        
    int16_t speedX;
    int16_t speedY;
} Ball;

void Ball_init(Ball* me);
void Ball_draw(Ball* me, uint16_t color, uint16_t bg_color);
void Ball_step(Ball* me);

#endif	/* BALL_H */

