/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

#include "pongstate.h"

class StandbyState : public PongState
{
public:
    StandbyState(State * parent, IRobot & robot);

protected:
    Result on_entry() override;
    bool on_event(TimerEvent & event) override;
};
