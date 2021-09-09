#include "ball.h"
#include "../board/lcd/lcd_highlevel.h"

/**
 * Initialise the ball position and speed
 * 
 * @param me - ball object
 * 
 * @author Samy Francelet
 */
void Ball_init(Ball* me) {
    me->posX = 100;
    me->posY = 100;
    
    me->speedX = BALL_SPEED;
    me->speedY = BALL_SPEED/2;
}

/**
 * Draws the ball with correct color
 * 
 * @param me - ball to draw
 * @param color - ball color
 * @param bg_color - pong background color, to erase prev ball drawn
 * 
 * @author Samy Francelet
 */
void Ball_draw(Ball* me, uint16_t color, uint16_t bg_color) {
    LCD_DrawRect(me->oldX, me->oldY, me->oldX + BALL_SIZE,
            me->oldY + BALL_SIZE, true, bg_color);
    
    me->oldX = me->posX;
    me->oldY = me->posY;
    
    LCD_DrawRect(me->posX, me->posY, me->posX + BALL_SIZE,
            me->posY + BALL_SIZE, true, color);
}

/**
 * Updates ball position according to speed
 * and throws ball redraw event
 * 
 * @param me - ball object
 * 
 * @author Samy Francelet
 */
void Ball_step(Ball* me) {
    if (me->speedX != 0 || me->speedY != 0) {        
        me->posX += me->speedX;
        me->posY += me->speedY;
        
        XF_pushEvent(Ball_redraw, false);
    }
}