/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "advancingstate.h"
#include "standbystate.h"

extern AdvancingState advancing;

StandbyState::StandbyState(State * parent, IRobot & robot) :
    PongState("standby", parent, robot)
{}

Result StandbyState::on_entry() 
{
    m_robot.start_timer(5000);
    return OK;
}

bool StandbyState::on_event(TimerEvent & event)
{
    transition_to_state(&advancing);

    return true;
}