/*
 * File:   pongboy.h
 * Author: Samy Francelet
 *
 * Created on 3. septembre 2021, 10:29
 */

#ifndef PONGBOY_H
#define	PONGBOY_H

#include "../board/tsc/tsc.h"
#include "../app/pong_ctrl.h"
#include "../app/menu_ctrl.h"
#include "../display/display.h"

#define SLEEP_TIME 30000

typedef enum {
    dim_ev = 254,
    sleep_ev = 255
} PongBoy_event;

/**
 * Initialise everything for the PongBoy to work
 * timers, interrupts, every state machines
 * 
 * @author Samy Francelet
 */
void PongBoy_init();

/**
 * Starts the behavior of every state machines
 * 
 * @author Samy Francelet
 */
void PongBoy_start();

/**
 * Pop an event from the XF buffer
 * and sends it to state machines
 * Manages the sleep event
 * 
 * @author Samy Francelet
 */
void PongBoy_execEvent();

/**
 * Executes the sleep routine
 * 
 * @author Samy Francelet
 */
void guteNacht();

/**
 * @return the TouchScreen controller
 * 
 * @author Samy Francelet
 */
TSC* PongBoy_getTSC();

/**
 * @return the Game controller
 * 
 * @author Samy Francelet
 */
Pong* PongBoy_getGame();

/**
 * @return the Menu controller
 * 
 * @author Samy Francelet
 */
Menu* PongBoy_getMenu();

#endif	/* PONGBOY_H */
