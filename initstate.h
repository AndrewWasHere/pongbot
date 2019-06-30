/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

#include "pongstate.h"

extern StandbyState standby;

class InitState : public PongState
{
public:
    InitState(State * parent, IRobot & robot);

protected:
    bool on_event(StartButtonEvent & event) override;
};
