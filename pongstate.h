#pragma once

#include "events.h"
#include "robot.h"
#include "statemachine.h"

using namespace statemachine;

class PongState : public State
{
public:
    PongState(char const * name, State * parent, IRobot & robot);
    Result transition_to_state(State * state) override;

protected:
    bool on_event(Event & event) override;
    virtual bool on_event(StartButtonEvent & event);
    virtual bool on_event(TimerEvent & event);
    virtual bool on_event(BoundaryAheadEvent & event);
    virtual bool on_event(BoundaryLeftEvent & event);
    virtual bool on_event(BoundaryRightEvent & event);
    
    IRobot & m_robot;
};