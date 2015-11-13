// This file is generated by FBC.

#ifndef PLANT_H_
#define PLANT_H_

#include "fbtypes.h"
#include "carousel_belt.h"
#include "diverter.h"

typedef union {
    UDINT events;
    struct {
        UDINT S2 : 1; // 
        UDINT S3 : 1; // 
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
    REAL _y;
    carousel_belt carousel_belt;
    diverter diverter;
} Plant;

/* Function block initialization function */
void Plantinit(Plant* me);

/* Function block execution function */
void Plantrun(Plant* me);

#endif // PLANT_H_
