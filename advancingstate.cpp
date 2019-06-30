/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "advancingstate.h"
#include "turningstate.h"

extern TurningState turning;

AdvancingState::AdvancingState(State * parent, IRobot & robot) :
    PongState("adv", parent, robot)
{}

Result oAdvancingState::n_entry() override
{
    m_robot.move_forward();
}

bool AdvancingState::on_event(BoundaryAheadEvent & event) override
{
    m_robot.move_stop();
    m_robot.turn_right(180);

    transition_to_state(&turning);

    return true;
}

bool AdvancingState::on_event(BoundaryLeftEvent & event) override
{
    m_robot.move_stop();
    m_robot.turn_right(90);

    transition_to_state(&turning);

    return true;
}

bool AdvancingState::on_event(BoundaryRightEvent & event) override
{
    m_robot.move_stop();
    m_robot.turn_left(90);

    transition_to_state(&turning);

    return true;
}