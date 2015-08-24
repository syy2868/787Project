// This file is generated by FBC.

#include "Filling_control.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void Filling_controlinit(Filling_control* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void Filling_control_init(Filling_control* me)
{
me->x1=0.05;
}

/* Function block execution function */
void Filling_controlrun(Filling_control* me)
{
    me->_output.events = 0;

    if (me->_input.event.update) {
        me->x1 = me->_x1;
    }
    for (;;) {
        if (me->_state == 0) {
            // State: Start
            if (!me->_entered) {
                Filling_control_init(me);
                me->_output.event.full = 1;
                me->_entered = true;
            }
            else {
                if (true && (me->x1 >= 1)) {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
            }
        }
        else {
            // State: setFull
            if (!me->_entered) {
                me->_output.event.full = 1;
                me->_entered = true;
            }
        }
        break;
    }

    me->_input.events = 0;
}
