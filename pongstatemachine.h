/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
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
