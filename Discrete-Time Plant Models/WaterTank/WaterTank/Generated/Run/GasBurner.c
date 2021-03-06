// This file is generated by FBC.

#include "GasBurner.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void GasBurnerinit(GasBurner* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void GasBurner_Init(GasBurner* me)
{
me->y=0;
me->d=0.01;
}

void GasBurner_Timer(GasBurner* me)
{
me->y=(float) me->y+me->d;
//printf("timer : %f\n", me->y);
}

void GasBurner_Reset(GasBurner* me)
{
//printf("signal transfered\n");
me->y=0;
}

/* Function block execution function */
void GasBurnerrun(GasBurner* me)
{
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    GasBurner_Init(me);
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.TurnOn) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.TurnOff) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 1:
                // State: State1
                if (!me->_entered) {
                    GasBurner_Timer(me);
                    me->_entered = true;
                }
                else {
                    if (me->y >= 0.1) {
                        me->_state = 2;
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
                // State: State2
                if (!me->_entered) {
                    GasBurner_Reset(me);
                    me->_output.event.On = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.TurnOff) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 3:
                // State: State3
                if (!me->_entered) {
                    GasBurner_Timer(me);
                    me->_entered = true;
                }
                else {
                    if (me->y >= 0.1) {
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
                // State: State4
                if (!me->_entered) {
                    GasBurner_Reset(me);
                    me->_output.event.Off = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.TurnOn) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
        }
        break;
    }
    if (me->_output.event.Update) {
        me->_y = me->y;
    }

    me->_input.events = 0;
}

