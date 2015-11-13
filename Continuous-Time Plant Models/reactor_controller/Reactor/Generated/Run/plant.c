// This file is generated by FBC.

#include "plant.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void plantinit(plant* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void plant_init(plant* me)
{
me->x=510;
me->d=0.01;
me->k=0;
me->C1x=10;
}

void plant_norod(plant* me)
{
me->x=me->C1x*exp(0.1*me->d*me->k) + 500.0;
me->k++;
printf("No Rod, Temperature : %f\n",me->x);
}

void plant_rod1(plant* me)
{
me->x = me->C1x*exp(0.1*me->d*me->k) + 560.0;
me->k++;
printf("Rod1, Temperature : %f\n",me->x);
}

void plant_rod2(plant* me)
{
me->x = me->C1x*exp(0.1*me->d*me->k) + 600.0;
me->k++;
printf("Rod2, Temperature : %f\n",me->x);
}

void plant_initvalno(plant* me)
{
me->k=0;
me->C1x=me->x-500;
}

void plant_initval1(plant* me)
{
me->k=0;
me->C1x=me->x-560;
}

void plant_initval2(plant* me)
{
me->k=0;
me->C1x=me->x-600;
}

/* Function block execution function */
void plantrun(plant* me)
{
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    plant_init(me);
                    me->_output.event.update = 1;
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
                    plant_norod(me);
                    me->_output.event.update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.add2) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.add1) {
                        me->_state = 5;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State6
                if (!me->_entered) {
                    plant_initval2(me);
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
                    plant_rod2(me);
                    me->_output.event.update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.remove2) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 4:
                // State: State5
                if (!me->_entered) {
                    plant_initvalno(me);
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 5:
                // State: State4
                if (!me->_entered) {
                    plant_initval1(me);
                    me->_entered = true;
                }
                else {
                    me->_state = 6;
                    me->_entered = false;
                    continue;
                }
                break;
            case 6:
                // State: State2
                if (!me->_entered) {
                    plant_rod1(me);
                    me->_output.event.update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.remove1) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
        }
        break;
    }
    if (me->_output.event.update) {
        me->_x = me->x;
    }

    me->_input.events = 0;
}

