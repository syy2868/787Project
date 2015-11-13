// This file is generated by FBC.

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT update : 1; // 
    } event;
} ControllerIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT UP : 1; // 
        UDINT DOWN : 1; // 
    } event;
} ControllerOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    ControllerIEvents _input;
    REAL x; // 
    REAL _x;
    REAL y1; // 
    REAL _y1;
    REAL y2; // 
    REAL _y2;
    REAL t1; // 
    REAL _t1;
    REAL t2; // 
    REAL _t2;
    ControllerOEvents _output;
} Controller;

/* Function block initialization function */
void Controllerinit(Controller* me);

/* Function block execution function */
void Controllerrun(Controller* me);

/* ECC algorithms */
void Controller_init(Controller* me);
void Controller_OPEN(Controller* me);
void Controller_CLOSE(Controller* me);

#endif // CONTROLLER_H_
