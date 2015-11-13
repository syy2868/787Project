// This file is generated by FBC.

#include "Controller.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void Controllerinit(Controller* me)
{
    me->_input.events = 0;
    me->_output.events = 0;
    detectioninit(&me->detection);
    TRDCinit(&me->TRDC);
}

/* Function block execution function */
void Controllerrun(Controller* me)
{
    me->detection._input.event.update = me->_input.event.update;
    me->detection._x = me->_x;
    me->TRDC._input.event.update = me->_input.event.update;
    me->TRDC._y = me->_y;
    me->TRDC._input.event.S1 = me->detection._output.event.S1;
    
    detectionrun(&me->detection);
    TRDCrun(&me->TRDC);
    
    me->_output.event.S3 = me->TRDC._output.event.S3;
    me->_output.event.S2 = me->TRDC._output.event.S2;
}