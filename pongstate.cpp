/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "pongstate.h"

using namespace statemachine;

PongState::PongState(char const * name, State * parent, IRobot & robot) :
    State(name, parent), m_robot(robot)
{
}

Result PongState::transition_to_state(State * state)
{
    Result r = State::transition_to_state(state);
    m_robot.display(active_state_name());

    return r;
}
bool PongState::on_event(Event & event) 
{
    bool handled = false;

    switch(event.m_id)
    {
        case START_EVENT:
            handled = on_event(static_cast<StartButtonEvent &>(event));
            break;
        case TIMER_EVENT:
            handled = on_event(static_cast<TimerEvent &>(event));
            break;
        case BOUNDARY_AHEAD_EVENT:
            handled = on_event(static_cast<BoundaryAheadEvent &>(event));
            break;
        case BOUNDARY_LEFT_EVENT:
            handled = on_event(static_cast<BoundaryLeftEvent &>(event));
            break;
        case BOUNDARY_RIGHT_EVENT:
            handled = on_event(static_cast<BoundaryRightEvent &>(event));
            break;
        default:
            break;
    }
    return handled;
}

bool PongState::on_event(StartButtonEvent & event) 
{
    return false; 
}

bool PongState::on_event(TimerEvent & event) 
{ 
    return false; 
}

bool PongState::on_event(BoundaryAheadEvent & event) 
{ 
    return false; 
}

bool PongState::on_event(BoundaryLeftEvent & event) 
{ 
    return false; 
}

bool PongState::on_event(BoundaryRightEvent & event) 
{ 
    return false; 
}