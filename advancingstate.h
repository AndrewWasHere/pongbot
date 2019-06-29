#pragma once

#include "pongstate.h"

class AdvancingState : public PongState
{
public:
    AdvancingState(State * parent, IRobot & robot) :
        PongState("adv", parent, robot)
    {}
};
