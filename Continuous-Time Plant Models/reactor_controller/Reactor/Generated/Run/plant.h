// This file is generated by FBC.

#ifndef PLANT_H_
#define PLANT_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT add1 : 1; // 
        UDINT add2 : 1; // 
        UDINT remove1 : 1; // 
        UDINT remove2 : 1; // 
    } event;
} plantIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT update : 1; // 
    } event;
} plantOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    plantIEvents _input;
    plantOEvents _output;
    REAL x; // 
    REAL _x;
    REAL d; // 
    INT k; // 
    REAL C1x; // 
} plant;

/* Function block initialization function */
void plantinit(plant* me);

/* Function block execution function */
void plantrun(plant* me);

/* ECC algorithms */
void plant_init(plant* me);
void plant_norod(plant* me);
void plant_rod1(plant* me);
void plant_rod2(plant* me);
void plant_initvalno(plant* me);
void plant_initval1(plant* me);
void plant_initval2(plant* me);

#endif // PLANT_H_
