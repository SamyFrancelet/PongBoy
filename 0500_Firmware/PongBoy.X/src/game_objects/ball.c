#include "ball.h"
#include "../board/lcd/lcd_highlevel.h"

void Ball_init(Ball* me) {
    me->posX = 100;
    me->posY = 100;
    
    me->speedX = BALL_SPEED;
    me->speedY = BALL_SPEED;
}

void Ball_draw(Ball* me, uint16_t color, uint16_t bg_color) {
    LCD_DrawRect(me->oldX, me->oldY, me->oldX + BALL_SIZE,
            me->oldY + BALL_SIZE, true, bg_color);
    
    me->oldX = me->posX;
    me->oldY = me->posY;
    
    LCD_DrawRect(me->posX, me->posY, me->posX + BALL_SIZE,
            me->posY + BALL_SIZE, true, color);
}

void Ball_step(Ball* me) {
    if (me->speedX != 0 || me->speedY != 0) {        
        me->posX += me->speedX;
        me->posY += me->speedY;
        
        XF_pushEvent(Ball_redraw, false);
    }
}