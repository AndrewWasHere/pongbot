/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
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
