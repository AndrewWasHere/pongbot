#pragma once

#include "advancingstate.h"
#include "pongstate.h"

extern AdvancingState advancing;

class StandbyState : public PongState
{
public:
    StandbyState(State * parent, IRobot & robot) :
        PongState("standby", parent, robot)
    {}

protected:
    Result on_entry() override
    {
        m_robot.start_timer(5000);
        return OK;
    }

    bool on_event(TimerEvent & event) override
    {
        transition_to_state(&advancing);
    }
};
