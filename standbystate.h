#pragma once

#include "pongstate.h"

class StandbyState : public PongState
{
public:
    StandbyState(State * parent, IRobot & robot) :
        PongState("standby", parent, robot)
    {}
};
