/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

#include "pongstate.h"

class TurningState : public PongState
{
public:
    TurningState(State * parent, IRobot & robot) :
        PongState("turn", parent, robot)
    {}
};
