// This file is generated by FBC.

#include "ytimer1.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void ytimer1init(ytimer1* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void ytimer1_init(ytimer1* me)
{
me->y1=20;
me->d=0.01;
}

void ytimer1_set(ytimer1* me)
{
me->y1=me->y1+me->d;
}

void ytimer1_reset(ytimer1* me)
{
me->y1=0;
}

/* Function block execution function */
void ytimer1run(ytimer1* me)
{
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    ytimer1_init(me);
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
                    ytimer1_set(me);
                    me->_output.event.update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.restart) {
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
                    ytimer1_reset(me);
                    me->_output.event.update = 1;
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
    if (me->_output.event.update) {
        me->_y1 = me->y1;
    }

    me->_input.events = 0;
}

