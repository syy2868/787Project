// This file is generated by FBC.

#ifndef WATERTANKSYSTEM_H_
#define WATERTANKSYSTEM_H_

#include "fbtypes.h"
#include "DigitalController.h"
#include "Plant.h"

typedef struct {
    DigitalController DigitalController;
    Plant Plant;
} WaterTankSystem;

/* Function block initialization function */
void WaterTankSysteminit(WaterTankSystem* me);

/* Function block execution function */
void WaterTankSystemrun(WaterTankSystem* me);

#endif // WATERTANKSYSTEM_H_