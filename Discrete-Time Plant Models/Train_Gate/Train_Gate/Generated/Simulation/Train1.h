// This file is generated by FBC.

#ifndef TRAIN1_H_
#define TRAIN1_H_

#include "fbtypes.h"
#include "Simulation.h"

typedef union {
    UDINT events;
    struct {
        UDINT update : 1; // 
    } event;
} Train1IEvents;

typedef union {
    UDINT events;
    struct {
        UDINT update_t1 : 1; // 
    } event;
} Train1OEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    Train1IEvents _input;
    REAL x; // 
    REAL _x;
    Train1OEvents _output;
    REAL y1; // 
    REAL _y1;
    REAL d; // 
    INT k; // 
    REAL C1y1; // 
    REAL delta; // 
    mxml_node_t *_simdata, *_simevents, *_simvars;
    mxml_node_t *_simstates, *_simtransitions;
    mxml_node_t *_simstate;
} Train1;

/* Function block initialization function */
void Train1init(Train1* me);

/* Function block execution function */
void Train1run(Train1* me);

/* ECC algorithms */
void Train1_init(Train1* me);
void Train1_slow_mode(Train1* me);
void Train1_fast_mode(Train1* me);
void Train1_emergency_brake(Train1* me);
void Train1_initCond_fast(Train1* me);
void Train1_initCond_slow(Train1* me);
void Train1_initCond_brake(Train1* me);

void Train1_initXML(mxml_node_t* node, Train1* me, char* instancename);
void Train1_runXML(Train1* me);
#endif // TRAIN1_H_
