// This file is generated by FBC.

#ifndef WATERTANK_H_
#define WATERTANK_H_

#include "fbtypes.h"
#include "Simulation.h"

typedef union {
    UDINT events;
    struct {
        UDINT On : 1; // 
        UDINT Off : 1; // 
    } event;
} WaterTankIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT Update : 1; // 
    } event;
} WaterTankOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    WaterTankIEvents _input;
    WaterTankOEvents _output;
    REAL x; // 
    REAL _x;
    REAL C1x; // 
    REAL k; // 
    REAL d; // 
    mxml_node_t *_simdata, *_simevents, *_simvars;
    mxml_node_t *_simstates, *_simtransitions;
    mxml_node_t *_simstate;
} WaterTank;

/* Function block initialization function */
void WaterTankinit(WaterTank* me);

/* Function block execution function */
void WaterTankrun(WaterTank* me);

/* ECC algorithms */
void WaterTank_Init(WaterTank* me);
void WaterTank_HeatingUp(WaterTank* me);
void WaterTank_InitValueOff(WaterTank* me);
void WaterTank_CoolingDown(WaterTank* me);
void WaterTank_InitValueOn(WaterTank* me);

void WaterTank_initXML(mxml_node_t* node, WaterTank* me, char* instancename);
void WaterTank_runXML(WaterTank* me);
#endif // WATERTANK_H_
