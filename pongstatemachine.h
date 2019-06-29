#pragma once

#include "pongstate.h"

class PongStateMachine : public PongState
{
public:
    PongStateMachine(State * parent, IRobot & robot) :
        PongState("machine", parent, robot)
    {}
};
