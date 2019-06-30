#pragma once

#include "pongstate.h"
#include "standbystate.h"

extern StandbyState standby;

class InitState : public PongState
{
public:
    InitState(State * parent, IRobot & robot) :
        PongState("init", parent, robot)
    {}

protected:
    bool on_event(StartButtonEvent & event) override
    {
        transition_to_state(&standby);
    }
};
