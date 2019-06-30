/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "advancingstate.h"
#include "turningstate.h"

extern AdvancingState advancing;

TurningState::TurningState(State * parent, IRobot & robot) :
    PongState("turn", parent, robot)
{}

bool TurningState::on_event(EncoderEvent & event) override
{
    transition_to_state(&advancing);

    return true;
}