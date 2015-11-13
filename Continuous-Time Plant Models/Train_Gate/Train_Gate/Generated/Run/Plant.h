// This file is generated by FBC.

#ifndef PLANT_H_
#define PLANT_H_

#include "fbtypes.h"
#include "Train1.h"
#include "Gate.h"
#include "Train2.h"

typedef union {
    UDINT events;
    struct {
        UDINT UP : 1; // 
        UDINT DOWN : 1; // 
    } event;
} PlantIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT update : 1; // 
    } event;
} PlantOEvents;

typedef struct {
    PlantIEvents _input;
    PlantOEvents _output;
    REAL _x;
    REAL _y1;
    REAL _y2;
    REAL _t1;
    REAL _t2;
    Train1 Train1;
    Gate Gate;
    Train2 Train2;
} Plant;

/* Function block initialization function */
void Plantinit(Plant* me);

/* Function block execution function */
void Plantrun(Plant* me);

#endif // PLANT_H_
