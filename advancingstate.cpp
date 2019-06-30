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

Result AdvancingState::on_entry() 
{
    m_robot.move_forward();
}

bool AdvancingState::on_event(BoundaryAheadEvent & event) 
{
    m_robot.move_stop();

    long degrees = 90 + (rand() % 181);
    if (rand() % 2)
    {
        m_robot.turn_right(degrees);
    }
    else
    {
        m_robot.turn_left(degrees);
    }
    

    transition_to_state(&turning);

    return true;
}

bool AdvancingState::on_event(BoundaryLeftEvent & event) 
{
    m_robot.move_stop();
    m_robot.turn_right(90 + (rand() % 91));

    transition_to_state(&turning);

    return true;
}

bool AdvancingState::on_event(BoundaryRightEvent & event) 
{
    m_robot.move_stop();
    m_robot.turn_left(90 + (rand() % 91));

    transition_to_state(&turning);

    return true;
}