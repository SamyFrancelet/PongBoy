#include <xc.h>
#include "tsc.h"

/**
 * Initialise the TouchScreen object
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_init(TSC* me) {
    me->state = TSC_waitPress;
    me->oldState = TSC_waitPress;
    me->x = 0;
    me->y = 0;
    me->tmrID = NULLTIMER;
    
    // Initialise TSC for press detection
    INTCON2bits.RBPU = 0; // pull-ups
    WPUBbits.WPUB0 = 1; // RB0 pullup
    
    // Activate AD
    ADCON1bits.PVCFG = 0b00;
    ADCON1bits.NVCFG = 0b00;
    
    ADCON2bits.ADFM = 1;
    ADCON2bits.ACQT = 0b101;
    ADCON2bits.ADCS = 0b110;
    
    DIR_TSC_XR = 1; // input with pullup
    DIR_TSC_XL = 1; // open
    DIR_TSC_YU = 0; // output
    DIR_TSC_YD = 1; // open
    
    TSC_YU_OUT = 0;
}

/**
 * Measure the X and Y positions on the TouchScreen
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_getPos(TSC* me) {
    
    // Analog measurement
    //WPUBbits.WPUB0 = 0; // RB0 no pullup
    ADCON0bits.ADON = 1;
    TSC_measX(me);
    TSC_measY(me);
    ADCON0bits.ADON = 0;
    
    // Back to press detection
    //WPUBbits.WPUB0 = 1; // RB0 pullup
    DIR_TSC_XR = 1; // input with pullup
    DIR_TSC_XL = 1; // open
    DIR_TSC_YU = 0; // output
    DIR_TSC_YD = 1; // open
    
    TSC_YU_OUT = 0;
    
    ANSELBbits.ANSB2 = 1; // XL analog
    ANSELBbits.ANSB3 = 1; // YD analog
    
    // Y position is measured on X resistors, and vice-versa,
    // because the touchscreen pinout is for a vertical usage
    // and we have an horizontal configuration
    // measX and measY function are made to measure
    // positions according to the pinout of the screen
    if (TSC_XR_IN == 0) { // If we are still touching the screen
        me->y = (me->meas_x - Y_OFFSET)/Y_CONV;
        me->x = (me->meas_y - X_OFFSET)/X_CONV;
    }
}

/**
 * Measure x position
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_measX(TSC* me) {
    DIR_TSC_XR = 0; // output
    DIR_TSC_XL = 0; // output
    DIR_TSC_YU = 1; // open
    DIR_TSC_YD = 1; // measuring pin
    
    TSC_XR_OUT = 0; // Right is 0V
    TSC_XL_OUT = 1; // Left is 3V
    
    ADCON0bits.CHS = 0b01001; // AN9 = RB3 = YD
    ADCON0bits.GO_nDONE = 1;
    
    while(ADCON0bits.GO_nDONE != 0) {}
    me->meas_x = ADRES;
}

/**
 * Measure y position
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_measY(TSC* me) {
    DIR_TSC_XR = 1; // open
    DIR_TSC_XL = 1; // measuring pin
    DIR_TSC_YU = 0; // output
    DIR_TSC_YD = 0; // output
    
    TSC_YU_OUT = 0; // Up is 0V
    TSC_YD_OUT = 1; // Down is 3V
    
    ADCON0bits.CHS = 0b01000; // AN8 = RB2 = XL
    ADCON0bits.GO_nDONE = 1;
    
    while(ADCON0bits.GO_nDONE != 0) {}
    me->meas_y = ADRES;
}

/**
 * Starting behavior of the TouchScreen state machine
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_startBehavior(TSC* me) {
    me->state = TSC_waitPress;
    me->oldState = TSC_waitPress;
    
    // Activate press interruption
    INT0IE = 1;
}

/**
 * Updates TouchScreen state machine
 * accordingly to the event received
 * 
 * @param me - TouchScreen object
 * @param ev - event to react
 * @return 
 * 
 * @author Samy Francelet
 */
bool TSC_SM(TSC* me, Event ev) {
    bool eventConsumed = false;
    me->oldState = me->state;
    
    switch(me->state) {
        case TSC_waitPress:
            if (ev == TSC_evPress) {
                me->state = TSC_measure;
            }
            break;
            
        case TSC_measure:
            break;
            
        case TSC_waitMeas:
            if (ev == TSC_evNextMeas) {
                me->state = TSC_measure;
            } else if (ev == TSC_evRelease) {
                me->state = TSC_waitPress;
                XF_unscheduleTimer(me->tmrID, false);
            }
            break;
        default:
            break;
    }
    
    if (me->oldState != me->state) {
        eventConsumed = true;
        
        switch(me->state) {
            case TSC_waitPress:
                INTEDG0 = 0;        // Falling edge
                INT0IE = 1;         // Enable INT0
                break;

            case TSC_measure:
                INTEDG0 = 1;        // Rising edge
                INT0IE = 0;         // Disable INT0
                
                // Measure position and sends an event
                TSC_getPos(me);
                XF_pushEvent(TSC_evTSC, false);
                
                // Schedule a timer and pass to the next state
                me->tmrID = XF_scheduleTimer(TSC_MEAS_TIME, TSC_evNextMeas, false);
                me->state = TSC_waitMeas;
                INT0IF = 0;         // Clear flag, because measure sets it
                INT0IE = 1;         // Enable INT0
                break;

            case TSC_waitMeas:
                break;
                
            default:
                break;
        }
    }
    
    return eventConsumed;
}
