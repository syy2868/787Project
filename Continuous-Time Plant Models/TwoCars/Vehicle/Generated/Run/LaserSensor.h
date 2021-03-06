// This file is generated by FBC.

#ifndef LASERSENSOR_H_
#define LASERSENSOR_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT SensorReading : 1; // 
    } event;
} LaserSensorIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT Output : 1; // 
    } event;
} LaserSensorOEvents;

typedef struct {
    BOOL _entered;
    LaserSensorIEvents _input;
    LREAL pos1; // 
    LREAL _pos1;
    LREAL pos2; // 
    LREAL _pos2;
    LaserSensorOEvents _output;
    LREAL distance; // 
    LREAL _distance;
} LaserSensor;

/* Function block initialization function */
void LaserSensorinit(LaserSensor* me);

/* Function block execution function */
void LaserSensorrun(LaserSensor* me);

/* ECC algorithms */
void LaserSensor_ReadSensor(LaserSensor* me);

#endif // LASERSENSOR_H_
