/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */

#include "initstate.h"
#include "standbystate.h"

extern StandbyState standby;

InitState::InitState(State * parent, IRobot & robot) :
    PongState("init", parent, robot)
{}

bool InitState::on_event(StartButtonEvent & event)
{
    transition_to_state(&standby);

    return true;
}