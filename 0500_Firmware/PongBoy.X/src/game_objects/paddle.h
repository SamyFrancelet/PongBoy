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
#define PADDLE_SPEED 3

typedef enum {
    Paddle_notMoving,
    Paddle_moving
} Paddle_state;

typedef enum {
    Paddle_redraw = 61,
} Paddle_event;

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

void Paddle_init(Paddle* me, bool isPlayer);
void Paddle_startBehavior(Paddle* me);
bool Paddle_SM(Paddle* me, Event ev);
void Paddle_draw(Paddle* me, uint16_t color, uint16_t bg_color);
void Paddle_step(Paddle* me);

#endif	/* PADDLE_H */

