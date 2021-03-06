// This file is generated by FBC.

#ifndef TWOCARS_H_
#define TWOCARS_H_

#include "fbtypes.h"
#include "LeadingCar.h"
#include "FollowingCar.h"
#include "LaserSensor.h"
#include "Controller.h"

typedef struct {
    LREAL _Car1Pos;
    LREAL _Car2Pos;
    LREAL _Car1Speed;
    LREAL _Car2Speed;
    LeadingCar LeadingCar;
    FollowingCar FollowingCar;
    LaserSensor LaserSensor;
    Controller Controller;
} TwoCars;

/* Function block initialization function */
void TwoCarsinit(TwoCars* me);

/* Function block execution function */
void TwoCarsrun(TwoCars* me);

#endif // TWOCARS_H_
