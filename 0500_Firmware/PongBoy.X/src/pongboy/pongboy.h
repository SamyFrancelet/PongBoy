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
#include "../display/display.h"

void PongBoy_init();
void PongBoy_build();
void PongBoy_start();

void PongBoy_execEvent();

TSC* PongBoy_getTSC();
Pong* PongBoy_getGame();

#endif	/* PONGBOY_H */

