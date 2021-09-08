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

void PongBoy_init();
void PongBoy_build();
void PongBoy_start();

void PongBoy_execEvent();

void guteNacht();

TSC* PongBoy_getTSC();
Pong* PongBoy_getGame();
Menu* PongBoy_getMenu();

#endif	/* PONGBOY_H */

