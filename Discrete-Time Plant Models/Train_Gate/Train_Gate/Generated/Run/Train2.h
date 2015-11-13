// This file is generated by FBC.

#ifndef TRAIN2_H_
#define TRAIN2_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT update : 1; // 
        UDINT count : 1; // 
    } event;
} Train2IEvents;

typedef union {
    UDINT events;
    struct {
        UDINT update_t2 : 1; // 
    } event;
} Train2OEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    Train2IEvents _input;
    REAL x; // 
    REAL _x;
    LINT c; // 
    LINT _c;
    Train2OEvents _output;
    REAL y2; // 
    REAL _y2;
    REAL t2; // 
    REAL _t2;
    REAL d; // 
    INT k; // 
    REAL C1y2; // 
    REAL delta; // 
    LINT t; // 
} Train2;

/* Function block initialization function */
void Train2init(Train2* me);

/* Function block execution function */
void Train2run(Train2* me);

/* ECC algorithms */
void Train2_init(Train2* me);
void Train2_slow_mode1(Train2* me);
void Train2_fast_mode(Train2* me);
void Train2_emergency_brake(Train2* me);
void Train2_initCond_slow(Train2* me);
void Train2_initCond_fast(Train2* me);
void Train2_initCond_brake(Train2* me);
void Train2_slow_mode2(Train2* me);

#endif // TRAIN2_H_
