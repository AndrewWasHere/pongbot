#pragma once

#include "pongstate.h"

class TurningState : public PongState
{
public:
    TurningState(State * parent, IRobot & robot) :
        PongState("turn", parent, robot)
    {}
};
