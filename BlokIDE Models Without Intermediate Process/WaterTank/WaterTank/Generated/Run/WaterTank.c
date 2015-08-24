// This file is generated by FBC.

#include "WaterTank.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void WaterTankinit(WaterTank* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void WaterTank_Init(WaterTank* me)
{
me->x = 20;
me->C1x = -130;
me->d = 0.01;
me->k = 1;
}

void WaterTank_HeatingUp(WaterTank* me)
{
//me->x = (float) me->C1x*exp(-0.075*me->d*me->k) + 150.0;
me->x = 100;
me->k++;
printf("Temperature : %f\n", me->x);
}

void WaterTank_InitValueOff(WaterTank* me)
{
me->k=0;
me->C1x=me->x;
}

void WaterTank_CoolingDown(WaterTank* me)
{
//me->x = (float) me->C1x*exp(-0.075*me->d*me->k);
me->x = 20;
me->k++;
printf("Temperature : %f\n", me->x);
}

void WaterTank_InitValueOn(WaterTank* me)
{
me->k=0;
me->C1x=me->x-150;
}

/* Function block execution function */
void WaterTankrun(WaterTank* me)
{
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    WaterTank_Init(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 1:
                // State: State1
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.On) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State2
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    me->_state = 3;
                    me->_entered = false;
                    continue;
                }
                break;
            case 3:
                // State: State3
                if (!me->_entered) {
                    WaterTank_HeatingUp(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->x >= 100) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.Off) {
                        me->_state = 10;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 4:
                // State: State4
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    me->_state = 5;
                    me->_entered = false;
                    continue;
                }
                break;
            case 5:
                // State: State6
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.Off) {
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 6:
                // State: State7
                if (!me->_entered) {
                    WaterTank_InitValueOff(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 7;
                    me->_entered = false;
                    continue;
                }
                break;
            case 7:
                // State: State8
                if (!me->_entered) {
                    WaterTank_CoolingDown(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->x <= 20) {
                        me->_state = 8;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.On) {
                        me->_state = 9;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 8:
                // State: State9
                if (!me->_entered) {
                    WaterTank_InitValueOn(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 9:
                // State: State10
                if (!me->_entered) {
                    WaterTank_InitValueOn(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 3;
                    me->_entered = false;
                    continue;
                }
                break;
            case 10:
                // State: State5
                if (!me->_entered) {
                    WaterTank_InitValueOff(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 7;
                    me->_entered = false;
                    continue;
                }
                break;
        }
        break;
    }
    if (me->_output.event.Update) {
        me->_x = me->x;
    }

    me->_input.events = 0;
}

