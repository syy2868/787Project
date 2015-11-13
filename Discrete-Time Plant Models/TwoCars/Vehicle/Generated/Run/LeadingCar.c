// This file is generated by FBC.

#include "LeadingCar.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void LeadingCarinit(LeadingCar* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_output.events = 0;
    me->pos1 = 100;
    me->_pos1 = 100;
    me->speed1 = 1;
    me->_speed1 = 1;
    me->t = 0;
}

/* ECC algorithms */
void LeadingCar_Init(LeadingCar* me)
{
me->d = 0.01;
me->speed1 = 1;
me->pos1 = 32.5;
me->k = 37;

}

void LeadingCar_Decelerate(LeadingCar* me)
{
me->v = me->speed1;
me->x = me->pos1;   
//me->speed1 = -0.0097*me->k*me->k - 0.0105*me->k + 14.707; 
me->speed1 = 0;
//me->pos1 = me->x + me->d * me->v;
me->pos1 = me->pos1 + 3.81;
me->k = me->k + 1;

if(me->speed1<=0){
  me->speed1 = 0;
  me->k = 0;
  me->t = 0;
}

printf("Leading car decelerates (Position: %3.8f, Speed: %3.8f)\n", me->pos1, me->speed1);



}

void LeadingCar_Accelerate(LeadingCar* me)
{
me->v = me->speed1;
me->x = me->pos1;  
me->k = me->k + 1; 
//me->speed1 = 0.0097*me->k*me->k + 0.0112*me->k - 0.0482; 
me->speed1 = 14.66;
//me->pos1 = me->x + me->d * me->v;
me->pos1 = me->pos1 + 2.05;

if(me->speed1>=14.66){
  me->speed1 = 14.66;
  me->k = 0;
  me->t = 0;
}

printf("Leading car accelerates (Position: %3.8f, Speed: %3.8f)\n", me->pos1, me->speed1);
}

void LeadingCar_MaxSpeed(LeadingCar* me)
{
me->x = me->pos1; 
me->v = me->speed1;
me->k = me->k + 1;
//me->pos1 = me->x + me->d * me->v;
me->pos1 = me->pos1 + 29.18;
printf("Leading car (Position: %3.8f, Speed: %3.8f)\n", me->pos1, me->speed1);

if(me->k*me->d==me->random_t){
  me->k = 1;
  me->t = me->random_t;
}

}

void LeadingCar_Stop(LeadingCar* me)
{
me->x = me->pos1; 
me->v = me->speed1;
me->k = me->k + 1;
//me->pos1 = me->x + me->d * me->v;
printf("Leading car (Position: %3.8f, Speed: %3.8f)\n", me->pos1, me->speed1);

if(me->k*me->d==me->random_t){
  me->k = 1;
  me->t = me->random_t;
}

}

void LeadingCar_StopTime(LeadingCar* me)
{
//srand(time(NULL));
//int temp=rand()%2;
//if (temp==1){
//me->random_t=9;
//}else if(temp==0){
//me->random_t=6;
//}
me->random_t=6;
}

void LeadingCar_MaxSpeedTime(LeadingCar* me)
{
//srand(time(NULL));
//int temp=rand()%2;
//if (temp==1){
//me->random_t=1;
//}else if(temp==0){
//me->random_t=3;
//}
me->random_t=2;
}

/* Function block execution function */
void LeadingCarrun(LeadingCar* me)
{
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    LeadingCar_Init(me);
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
                    LeadingCar_Decelerate(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->speed1 == 0) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State2
                if (!me->_entered) {
                    LeadingCar_StopTime(me);
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
                    LeadingCar_Stop(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 4;
                    me->_entered = false;
                    continue;
                }
                break;
            case 4:
                // State: State4
                if (!me->_entered) {
                    LeadingCar_Accelerate(me);
                    me->_output.event.Update = 1;
                    me->_entered = true;
                }
                else {
                    if (me->speed1 == 14.66) {
                        me->_state = 5;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 5:
                // State: State5
                if (!me->_entered) {
                    LeadingCar_MaxSpeedTime(me);
                    me->_entered = true;
                }
                else {
                    me->_state = 6;
                    me->_entered = false;
                    continue;
                }
                break;
            case 6:
                // State: State6
                if (!me->_entered) {
                    LeadingCar_MaxSpeed(me);
                    me->_output.event.Update = 1;
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
    if (me->_output.event.Update) {
        me->_pos1 = me->pos1;
        me->_speed1 = me->speed1;
    }

}
