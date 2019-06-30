#pragma once

#include "pongstate.h"

class AdvancingState : public PongState
{
public:
    AdvancingState(State * parent, IRobot & robot) :
        PongState("adv", parent, robot)
    {}

protected:
    Result on_entry() override
    {
        m_robot.turn_left(0);
    }
};
