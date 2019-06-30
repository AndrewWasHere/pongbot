#pragma once

#include "initstate.h"
#include "pongstate.h"

extern InitState initialized;

class PongStateMachine : public PongState
{
public:
    PongStateMachine(State * parent, IRobot & robot) :
        PongState("machine", parent, robot)
    {}

protected:
    Result on_initialize() override
    {
        return transition_to_state(&initialized);
    }
};
