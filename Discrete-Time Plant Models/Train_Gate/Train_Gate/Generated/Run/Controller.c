// This file is generated by FBC.

#include "Controller.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void Controllerinit(Controller* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void Controller_init(Controller* me)
{
me->y1=0;
me->y2=0;

}

void Controller_OPEN(Controller* me)
{
if(me->t1>me->t2){
printf("signal sent : open the gate, y1 : %f, y2 : %f, time : %f\n", me->y1, me->y2, me->t1);
}else{
printf("signal sent : open the gate, y1 : %f, y2 : %f, time : %f\n", me->y1, me->y2, me->t2);
}
}

void Controller_CLOSE(Controller* me)
{
if(me->t1>me->t2){
printf("signal sent : close the gate, y1 : %f, y2 : %f, time : %f\n", me->y1, me->y2, me->t1);
}else{
printf("signal sent : close the gate, y1 : %f, y2 : %f, time : %f\n", me->y1, me->y2, me->t2);
}
}

/* Function block execution function */
void Controllerrun(Controller* me)
{
    me->_output.events = 0;

    if (me->_input.event.update) {
        me->y1 = me->_y1;
        me->y2 = me->_y2;
        me->t1 = me->_t1;
        me->t2 = me->_t2;
    }
    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    Controller_init(me);
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
                    if ((me->y1 >= 5 && me->y1 < 15) && (me->y2 >= 5 && me->y2 < 15)) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State3
                if (!me->_entered) {
                    Controller_OPEN(me);
                    me->_output.event.DOWN = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 15 || me->y2 >= 15) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 3:
                // State: State2
                if (!me->_entered) {
                    Controller_CLOSE(me);
                    me->_output.event.UP = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
        }
        break;
    }

    me->_input.events = 0;
}

