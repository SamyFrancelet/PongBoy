#include "menu_ctrl.h"
#include "pong_ctrl.h"
#include "../pongboy/pongboy.h"
#include "../display/display.h"

extern const FONT_INFO arialNarrow_12ptFontInfo;

void Menu_init(Menu* me) {
    me->state = Menu_main;
    me->oldState = Menu_main;
    
    LCD_ButtonCreate(100, 100, 100, 50, BG_COLOR, ITEM_COLOR,
            "1 Player", &arialNarrow_12ptFontInfo, NULL, NULL, NULL, 
            &(me->SinglePlayerBtn), 1);
}

void Menu_startBehavior(Menu* me) {
    me->state = Menu_main;
    me->oldState = Menu_main;
}

void Menu_SM(Menu* me, Event ev) {
    me->oldState = me->state;
    TSC* tsc;
    
    switch(me->state) {
        case Menu_main:
        case Menu_settings:
            if(ev == TSC_evTSC) {
                tsc = PongBoy_getTSC();
                checkClick(me, tsc->x, tsc->y);
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

void checkClick(Menu* me, uint16_t posX, uint16_t posY) {
    if (me->state == Menu_main) {
        if (LCD_InButton(&(me->SinglePlayerBtn), posX, posY)) {
            XF_pushEvent(Pong_startGameEv, false);
        }
    } else if (me->state == Menu_settings) {
        
    }
}