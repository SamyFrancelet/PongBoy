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

#define REFRESH_TIME 30

typedef enum {
    Refresh_display = 31
} Display_event;

typedef enum {
    Display_menu,
    Display_game,
} Display_state;

// Display structure definition
typedef struct {
    uint8_t luminosity;
    
    Display_state state;
    Display_state oldState;
} Display;

/**
 * Initialise the Display object
 * 
 * @param me - Display object to initialise
 * 
 * @author Samy Francelet
 */
void Display_init(Display* me);

/**
 * Initialise the PWM for the LCD backlight
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_PWM_init(Display* me);

/**
 * Sets the PWM duty-cycle for the LCD backlight
 * 
 * @param me - Display object
 * @param luminosity - LCD luminosity in (0 to 100)
 * 
 * @author Samy Francelet
 */
void Display_setBackLight(Display* me, uint8_t luminosity);

/**
 * Sleep routine for the Display
 * Turn off everything and avoid current wells
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_sleep(Display* me);

/**
 * Starting behavior of the Display state machine
 * 
 * @param me - Display object
 * 
 * @author Samy Francelet
 */
void Display_startBehavior(Display* me);

/**
 * Updates display accordingly to the event received
 * 
 * @param me - Display object
 * @param ev - event to react
 * @return 
 * 
 * @author Samy Francelet
 */
bool Display_update(Display* me, Event ev);

#endif	/* DISPLAY_H */

