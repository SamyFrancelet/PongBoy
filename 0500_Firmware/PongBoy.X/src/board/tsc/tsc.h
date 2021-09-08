#ifndef TSC_DEF
#define TSC_DEF
/*
 * File:   tsc.h
 * Author:
 *
 * Created on
 */

#include <stdint.h>
#include "../../xf/xf.h"

// Measure min :
// X : 0110
// Y : 0110
// Measure max :
// X : 0780
// Y : 0690
#define X_OFFSET 110
#define Y_OFFSET 110

#define X_CONV 2
#define Y_CONV 2.4

#define XRES 320
#define YRES 240

#define TSC_MEAS_TIME 170

#define TSC_XR_OUT        LATB0
#define TSC_XL_OUT        LATB2
#define TSC_YU_OUT        LATB1
#define TSC_YD_OUT        LATB3

#define TSC_XR_IN         PORTBbits.RB0
#define TSC_XL_IN         PORTBbits.RB2
#define TSC_YU_IN         PORTBbits.RB1
#define TSC_YD_IN         PORTBbits.RB3

#define DIR_TSC_XR        TRISB0
#define DIR_TSC_XL        TRISB2
#define DIR_TSC_YU        TRISB1
#define DIR_TSC_YD        TRISB3

// TouchScreen states
typedef enum {
    TSC_waitPress,
    TSC_measure,
    TSC_waitMeas
} TSC_state;

// TouchScreen events
typedef enum {
    TSC_evPress     = 11,
    TSC_evNextMeas  = 12,
    TSC_evRelease   = 13,
    TSC_evTSC       = 14
} TSC_event;

// TouchScreen structure definition
typedef struct {
    uint16_t x;
    uint16_t y;
    
    uint16_t meas_x;
    uint16_t meas_y;
    
    TimerID tmrID;
    
    TSC_state state;
    TSC_state oldState;
} TSC;

/**
 * Initialise the TouchScreen object
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_init(TSC* me);

/**
 * Measure the X and Y positions on the TouchScreen
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_getPos(TSC* me);

/**
 * Measure x position
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_measX(TSC* me);

/**
 * Measure y position
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_measY(TSC* me);

/**
 * Starting behavior of the TouchScreen state machine
 * 
 * @param me - TouchScreen object
 * 
 * @author Samy Francelet
 */
void TSC_startBehavior(TSC* me);

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
bool TSC_SM(TSC* me, Event ev);
#endif
