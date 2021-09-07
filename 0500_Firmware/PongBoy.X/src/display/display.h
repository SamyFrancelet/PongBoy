/* 
 * File:   display.h
 * Author: samy
 *
 * Created on 6. septembre 2021, 11:05
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#define DEBUG false

#define DARKMODE

#ifdef DARKMODE
#define ITEM_COLOR WHITE
#define BG_COLOR BLACK
#else
#define ITEM_COLOR BLACK
#define BG_COLOR WHITE
#endif

#include "../xf/xf.h"
#include "../board/lcd/lcd_highlevel.h"

typedef enum {
    Display_menu,
    Display_game
} Display_state;

typedef struct {
    Display_state state;
    Display_state oldState;
} Display;

void Display_init(Display* me);
void Display_startBehavior(Display* me);
bool Display_update(Display* me, Event ev);

#endif	/* DISPLAY_H */

