// This file is generated by FBC.

#ifndef WATERTANK_H_
#define WATERTANK_H_

#include "fbtypes.h"

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

#endif // WATERTANK_H_
