#include "menu_ctrl.h"
#include "pong_ctrl.h"
#include "../pongboy/pongboy.h"
#include "../display/display.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

/**
 * Initialise the Menu controller
 * 
 * @param me - Menu controller object
 * 
 * @author Samy Francelet
 */
void Menu_init(Menu* me) {
    me->state = Menu_main;
    me->oldState = Menu_main;
    
    LCD_ButtonCreate(20, 50, 80, 40, BG_COLOR, ITEM_COLOR,
            "Play Pong", &arialNarrow_12ptFontInfo, NULL, NULL, NULL, 
            &(me->SinglePlayerBtn), 1);
    
    LCD_ButtonCreate(20, 150, 80, 40, BG_COLOR, ITEM_COLOR,
            "Settings", &arialNarrow_12ptFontInfo, NULL, NULL, NULL, 
            &(me->settingsBtn), 1);
    
    LCD_SliderCreate(150, 60, 100, 20, BG_COLOR, ITEM_COLOR,
            RED, 5, 100, NULL, &(me->backLightSlider));
    me->backLightSlider.value = 100;
}

/**
 * Starting behavior of the Menu state machine
 * 
 * @param me - Menu controller object
 * 
 * @author Samy Francelet
 */
void Menu_startBehavior(Menu* me) {
    me->state = Menu_main;
    me->oldState = Menu_main;
}

/**
 * Update the Menu state machine
 * accordingly to the event received
 * 
 * @param me - Menu controller object
 * @param ev - event to react
 * 
 * @author Samy Francelet
 */
void Menu_SM(Menu* me, Event ev) {
    me->oldState = me->state;
    TSC* tsc;
    
    switch(me->state) {
        case Menu_main:
        case Menu_settings:
            if(ev == TSC_evTSC) {
                tsc = PongBoy_getTSC();
                checkClick(me, tsc->x, tsc->y);
            } else if (ev == Pong_startGameEv) {
                me->state = Menu_inGame;
            }
            break;

        case Menu_inGame:
            if(ev == Menu_evMenu) {
                me->state = Menu_main;
            }
            break;
        default:
            break;
    }
}

/**
 * Check if the TouchScreen has clicked on an object
 * 
 * @param me - Menu controller object
 * @param posX - TouchScreen x position
 * @param posY - TouchScreen y position
 * 
 * @author Samy Francelet
 */
void checkClick(Menu* me, uint16_t posX, uint16_t posY) {
    if (me->state == Menu_main) {
        if (LCD_InButton(&(me->SinglePlayerBtn), posX, posY)) {
            XF_pushEvent(Pong_startGameEv, false);
        } else if (LCD_InButton(&(me->settingsBtn), posX, posY)) {
            XF_pushEvent(Menu_redraw, false);
            me->state = Menu_settings;
            me->SinglePlayerBtn.text = "Back";
        }
    } else if (me->state == Menu_settings) {
        if (LCD_InButton(&(me->SinglePlayerBtn), posX, posY)) {
            XF_pushEvent(Menu_redraw, false);
            me->state = Menu_main;
            me->SinglePlayerBtn.text = "Play Pong";
        } else if (LCD_InSlider(&(me->backLightSlider), posX, posY)) {
            uint8_t value;
            value = posX - me->backLightSlider.posX;
            me->backLightSlider.value = value;
            XF_pushEvent(Menu_refresh, false);
        }
    }
}