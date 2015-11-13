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
    me->_simdata = mxmlNewElement( MXML_NO_PARENT, "Instance"); // inited to main's tree later.. but make sure it's usable without
}

/* ECC algorithms */
void Train1_init(Train1* me)
{
me->y1=0;
me->delta=0.0001;
me->k=1;
me->C1y1=-1;
}

void Train1_slow_mode(Train1* me)
{
me->y1=me->C1y1*exp(-1.0L/2.0L*me->d*me->k)+1;
(me->k)++;
}

void Train1_fast_mode(Train1* me)
{
me->y1=me->C1y1*exp(-1*me->d*me->k)+2;
(me->k)++;
}

void Train1_emergency_brake(Train1* me)
{
me->y1=me->C1y1*exp(-1.0L/10.0L*me->d*me->k);
(me->k)++;

if (me->y1 <= me->delta) {
 printf ("Emergency brake : Train stopped at y1 = %f and x = %f\n",me->y1, me->x);
 exit(1);
 }
}

void Train1_initCond_fast(Train1* me)
{
me->k=1;
me->C1y1=me->x-2;
printf("fast mode on\n");
}

void Train1_initCond_slow(Train1* me)
{
me->k=1;
me->C1y1=me->x-1;
printf("slow mode on\n");
}

void Train1_initCond_brake(Train1* me)
{
me->k=1;
me->C1y1=me->x-10;
printf("Emergency brake !!!\n");
}

/* Function block execution function */
void Train1run(Train1* me)
{
    clearChildren(me->_simevents);
    clearChildren(me->_simvars);
    deleteNexts(me->_simstate);
    clearChildren(me->_simtransitions);
    me->_output.events = 0;

    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                mxmlElementSetAttr(me->_simstate, "Name", "Start");
                if (!me->_entered) {
                    Train1_init(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    appendTransitionToXML(me->_simtransitions, "Start", "State1", "1");
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 1:
                // State: State1
                mxmlElementSetAttr(me->_simstate, "Name", "State1");
                if (!me->_entered) {
                    Train1_slow_mode(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 5) {
                        appendTransitionToXML(me->_simtransitions, "State1", "State5", "y1>=5");
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        appendTransitionToXML(me->_simtransitions, "State1", "State1", "1");
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: State5
                mxmlElementSetAttr(me->_simstate, "Name", "State5");
                if (!me->_entered) {
                    Train1_initCond_fast(me);
                    me->_entered = true;
                }
                else {
                    appendTransitionToXML(me->_simtransitions, "State5", "State2", "1");
                    me->_state = 3;
                    me->_entered = false;
                    continue;
                }
                break;
            case 3:
                // State: State2
                mxmlElementSetAttr(me->_simstate, "Name", "State2");
                if (!me->_entered) {
                    Train1_fast_mode(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 15) {
                        appendTransitionToXML(me->_simtransitions, "State2", "State6", "y1>=15");
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        appendTransitionToXML(me->_simtransitions, "State2", "State2", "1");
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 4:
                // State: State6
                mxmlElementSetAttr(me->_simstate, "Name", "State6");
                if (!me->_entered) {
                    Train1_initCond_slow(me);
                    me->_entered = true;
                }
                else {
                    appendTransitionToXML(me->_simtransitions, "State6", "State3", "1");
                    me->_state = 5;
                    me->_entered = false;
                    continue;
                }
                break;
            case 5:
                // State: State3
                mxmlElementSetAttr(me->_simstate, "Name", "State3");
                if (!me->_entered) {
                    Train1_slow_mode(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    if (me->y1 >= 20 && me->x > 1 + me->delta) {
                        appendTransitionToXML(me->_simtransitions, "State3", "State7", "y1>=20 AND x>1+delta");
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->y1 >= 25) {
                        appendTransitionToXML(me->_simtransitions, "State3", "Start", "y1>=25");
                        me->_state = 0;
                        me->_entered = false;
                        continue;
                    }
                    else {
                        appendTransitionToXML(me->_simtransitions, "State3", "State3", "1");
                        me->_state = 5;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 6:
                // State: State7
                mxmlElementSetAttr(me->_simstate, "Name", "State7");
                if (!me->_entered) {
                    Train1_initCond_brake(me);
                    me->_entered = true;
                }
                else {
                    appendTransitionToXML(me->_simtransitions, "State7", "State4", "1");
                    me->_state = 7;
                    me->_entered = false;
                    continue;
                }
                break;
            case 7:
                // State: State4
                mxmlElementSetAttr(me->_simstate, "Name", "State4");
                if (!me->_entered) {
                    Train1_emergency_brake(me);
                    me->_output.event.update_t1 = 1;
                    me->_entered = true;
                }
                else {
                    appendTransitionToXML(me->_simtransitions, "State4", "State4", "1");
                    me->_state = 7;
                    me->_entered = false;
                    continue;
                }
                break;
        }
        break;
    }

    Train1_runXML(me);
    me->_input.events = 0;
}

void Train1_initXML(mxml_node_t* node, Train1* me, char* instancename)
{
    // Add to tree
    mxmlAdd(node, MXML_ADD_AFTER, NULL, me->_simdata);
    // Add constanty things
    mxmlElementSetAttrf(me->_simdata, "Name", "%s", instancename);
    mxmlElementSetAttr(me->_simdata, "Type", "Train1");
    me->_simevents = mxmlNewElement(me->_simdata,"Events");
    me->_simvars = mxmlNewElement(me->_simdata,"Vars");
    me->_simstates = mxmlNewElement(me->_simdata,"ECStates");
    me->_simstate = mxmlNewElement(me->_simstates,"ECState");
    me->_simtransitions = mxmlNewElement(me->_simdata,"ECTransitions");
}

void Train1_runXML(Train1* me)
{
mxml_node_t* childnode; // used as a temp node
childnode = mxmlNewElement(me->_simevents,"Event");
mxmlElementSetAttr(childnode, "Name", "update");
mxmlElementSetAttr(childnode, "Scope", "Input");
mxmlElementSetAttr(childnode, "Type", "EVENT");
if(  me->_input.event.update )
    mxmlElementSetAttr(childnode, "Value", "Present");
else
    mxmlElementSetAttr(childnode, "Value", "Absent");
childnode = mxmlNewElement(me->_simevents,"Event");
mxmlElementSetAttr(childnode, "Name", "update_t1");
mxmlElementSetAttr(childnode, "Scope", "Output");
mxmlElementSetAttr(childnode, "Type", "EVENT");
if(  me->_output.event.update_t1 )
    mxmlElementSetAttr(childnode, "Value", "Present");
else
    mxmlElementSetAttr(childnode, "Value", "Absent");
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "x");
mxmlElementSetAttr(childnode, "Scope", "Input");
mxmlElementSetAttr(childnode, "Type", "REAL");
mxmlElementSetAttrf(childnode, "Value", "%f", me->_x);
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "y1");
mxmlElementSetAttr(childnode, "Scope", "Output");
mxmlElementSetAttr(childnode, "Type", "REAL");
mxmlElementSetAttrf(childnode, "Value", "%f", me->_y1);
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "d");
mxmlElementSetAttr(childnode, "Scope", "Internal");
mxmlElementSetAttr(childnode, "Type", "REAL");
mxmlElementSetAttrf(childnode, "Value", "%f", me->d);
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "k");
mxmlElementSetAttr(childnode, "Scope", "Internal");
mxmlElementSetAttr(childnode, "Type", "INT");
mxmlElementSetAttrf(childnode, "Value", "%d", me->k);
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "C1y1");
mxmlElementSetAttr(childnode, "Scope", "Internal");
mxmlElementSetAttr(childnode, "Type", "REAL");
mxmlElementSetAttrf(childnode, "Value", "%f", me->C1y1);
childnode = mxmlNewElement(me->_simvars,"Var");
mxmlElementSetAttr(childnode, "Name", "delta");
mxmlElementSetAttr(childnode, "Scope", "Internal");
mxmlElementSetAttr(childnode, "Type", "REAL");
mxmlElementSetAttrf(childnode, "Value", "%f", me->delta);
//mxmlElementSetAttrf(me->_simstate, "Name", "%s", me->_statename); // set in run function
}
