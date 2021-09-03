/* 
 * File:   pongboy.h
 * Author: Samy Francelet
 *
 * Created on 3. septembre 2021, 10:29
 */

#ifndef PONGBOY_H
#define	PONGBOY_H

#include "../board/tsc/tsc.h"
#include "../board/lcd/lcd_highlevel.h"

void PongBoy_init();
void PongBoy_build();
void PongBoy_start();

void PongBoy_execEvent();

#endif	/* PONGBOY_H */
