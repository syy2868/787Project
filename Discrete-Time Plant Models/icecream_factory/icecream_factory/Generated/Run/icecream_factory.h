// This file is generated by FBC.

#ifndef ICECREAM_FACTORY_H_
#define ICECREAM_FACTORY_H_

#include "fbtypes.h"
#include "Controller.h"
#include "Plant.h"

typedef struct {
    Controller Controller;
    Plant Plant;
} icecream_factory;

/* Function block initialization function */
void icecream_factoryinit(icecream_factory* me);

/* Function block execution function */
void icecream_factoryrun(icecream_factory* me);

#endif // ICECREAM_FACTORY_H_