/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "initstate.h"
#include "pongstatemachine.h"

extern InitState initialized;

PongStateMachine::PongStateMachine(State * parent, IRobot & robot) :
    PongState("machine", parent, robot)
{}

Result PongStateMachine::on_initialize() 
{
    return transition_to_state(&initialized);
}