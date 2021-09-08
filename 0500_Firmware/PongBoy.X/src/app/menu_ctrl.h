/* 
 * File:   menu_ctrl.h
 * Author: samy
 *
 * Created on 7. septembre 2021, 07:59
 */

#ifndef MENU_CTRL_H
#define	MENU_CTRL_H

#include "../xf/xf.h"
#include "../board/lcd/lcd_highlevel.h"

typedef enum {
    Menu_main,
    Menu_settings,
    Menu_inGame
} Menu_state;

typedef enum {
    Menu_evMenu = 41,
    Menu_redraw = 42,
    Menu_refresh = 43
} Menu_event;

typedef struct {
    btn_t settingsBtn;
    btn_t SinglePlayerBtn;
    //btn_t MultiPlayerBtn;
    
    sld_t backLightSlider;
    
    Menu_state state;
    Menu_state oldState;
} Menu;

/**
 * Initialise the Menu controller
 * 
 * @param me - Menu controller object
 * 
 * @author Samy Francelet
 */
void Menu_init(Menu* me);

/**
 * Starting behavior of the Menu state machine
 * 
 * @param me - Menu controller object
 * 
 * @author Samy Francelet
 */
void Menu_startBehavior(Menu* me);

/**
 * Update the Menu state machine
 * accordingly to the event received
 * 
 * @param me - Menu controller object
 * @param ev - event to react
 * 
 * @author Samy Francelet
 */
void Menu_SM(Menu* me, Event ev);

/**
 * Check if the TouchScreen has clicked on an object
 * 
 * @param me - Menu controller object
 * @param posX - TouchScreen x position
 * @param posY - TouchScreen y position
 * 
 * @author Samy Francelet
 */
void checkClick(Menu* me, uint16_t posX, uint16_t posY);

#endif	/* MENU_CTRL_H */

