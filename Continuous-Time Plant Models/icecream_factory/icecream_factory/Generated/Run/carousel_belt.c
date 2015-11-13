// This file is generated by FBC.

#include "carousel_belt.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void carousel_beltinit(carousel_belt* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_output.events = 0;
}

/* ECC algorithms */
void carousel_belt_init(carousel_belt* me)
{
me->x=0;
me->beta=10;
}

void carousel_belt_run(carousel_belt* me)
{
me->x=me->x+1;
//printf("icecream, %f\n", me->x);
}

/* Function block execution function */
void carousel_beltrun(carousel_belt* me)
{
    me->_output.events = 0;

    for (;;) {
        if (me->_state == 0) {
            // State: Start
            if (!me->_entered) {
                carousel_belt_init(me);
                me->_output.event.update = 1;
                me->_entered = true;
            }
            else {
                me->_state = 1;
                me->_entered = false;
                continue;
            }
        }
        else {
            // State: State1
            if (!me->_entered) {
                carousel_belt_run(me);
                me->_output.event.update = 1;
                me->_entered = true;
            }
            else {
                if (me->x >= me->beta) {
                    me->_state = 0;
                    me->_entered = false;
                    continue;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
            }
        }
        break;
    }
    if (me->_output.event.update) {
        me->_x = me->x;
    }

}

