#pragma once

#include "pongstate.h"

class InitState : public PongState
{
public:
    InitState(State * parent, IRobot & robot) :
        PongState("init", parent, robot)
    {}
};
