// This file is generated by FBC.

#include "Train1.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void Train1init(Train1* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
    me->t = 0;
}

/* ECC algorithms */
void Train1_init(Train1* me)
{
me->y1=0;
me->delta=0.0001;
me->k=1;
me->C1y1=0;
me->d=0.01;
if(me->t==0){
printf("train 1 position : %f\n", me->y1);
}
}

void Train1_slow_mode1(Train1* me)
{
//me->y1=me->d*me->k+me->C1y1;
me->y1=5;
printf("train 1 position : %f\n", me->y1);
(me->k)++;
me->t=me->c;
me->t1=me->t/(float)3;
//printf("train1 time : %d\n", me->t);
}

void Train1_fast_mode(Train1* me)
{
//me->y1=2*me->d*me->k+me->C1y1;
me->y1=15;
(me->k)++;
printf("y1 : %f\n", me->y1);
me->t=me->c;
me->t1=me->t/(float)3;
//printf("train1 time : %d\n", me->t);
}

void Train1_emergency_brake(Train1* me)
{
//float temp = me->y1;
float temp = 20;
//me->y1 = me->C1y1*exp(-10*me->d*me->k)+23;
me->y1 =23;
(me->k)++;


if (me->y1 - temp <= me->delta) {
 printf ("Emergency brake : Train stopped at y1 = %f and x = %f\n",me->y1, me->x);
 exit(1);
 }
}

void Train1_initCond_fast(Train1* me)
{
me->k=1;
me->C1y1=me->y1;
//printf("Train 1 is going into fast mode \n");
}

void Train1_initCond_slow(Train1* me)
{
me->k=1;
me->C1y1=me->y1;
//printf("Train 1 is going into slow mode \n");
}

void Train1_initCond_brake(Train1* me)
{
me->k=1;
me->C1y1=me->y1-23;
printf("Emergency brake T1 !!!\n");
}

void Train1_slow_mode2(Train1* me)
{
//me->y1=me->d*me->k+me->C1y1;
me->y1=25;
printf("train 1 position : %f\n", me->y1);
(me->k)++;
me->t=me->c;
me->t1=me->t/(float)3;
//printf("train1 time : %d\n", me->t);
}

/* Function block execution function */
void Train1run(Train1* me)
{
    me->_output.events = 0;

    if (me->_input.events) {
        if (me->_input.event.update) {
            me->x = me->_x;
        }
        if (me->_input.event.count) {
            me->c = me->_c;
        }
    }
    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    Train1_init(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->c - me->t >= 15) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 1:
                // State: State1
                if (!me->_entered) {
                    Train1_slow_mode1(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 5) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State5
                if (!me->_entered) {
                    Train1_initCond_fast(me);
                    me->_entered = true;
                }
                else {
                    if (me->c - me->t >= 15) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 3:
                // State: State2
                if (!me->_entered) {
                    Train1_fast_mode(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 15) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 4:
                // State: State6
                if (!me->_entered) {
                    Train1_initCond_slow(me);
                    me->_entered = true;
                }
                else {
                    if (me->c - me->t >= 30) {
                        me->_state = 5;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 5:
                // State: State3
                if (!me->_entered) {
                    Train1_slow_mode2(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (false && me->y1 >= 20 && me->x < 10 - me->delta) {
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->y1 >= 25) {
                        me->_state = 0;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 6:
                // State: State7
                if (!me->_entered) {
                    Train1_initCond_brake(me);
                    me->_entered = true;
                }
                else {
                    me->_state = 7;
                    me->_entered = false;
                    continue;
                }
                break;
            case 7:
                // State: State4
                if (!me->_entered) {
                    Train1_emergency_brake(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                break;
        }
        break;
    }
    if (me->_output.event.update_t1) {
        me->_y1 = me->y1;
        me->_t1 = me->t1;
    }

    me->_input.events = 0;
}

