#pragma once

#include "events.h"
#include "robot.h"
#include "statemachine.h"

using namespace statemachine;

class PongState : public State
{
public:
    PongState(char const * name, State * parent, IRobot & robot) :
        State(name, parent), m_robot(robot)
    {}

protected:
    bool on_event(Event & event) override{
        bool handled = false;

        switch(event.m_id)
        {
            case START:
                handled = on_event(static_cast<StartButtonEvent &>(event));
                break;
            case RESET:
                handled = on_event(static_cast<ResetButtonEvent &>(event));
                break;
            case TIMER:
                handled = on_event(static_cast<TimerEvent &>(event));
                break;
            case BOUNDARY_AHEAD:
                handled = on_event(static_cast<BoundaryAheadEvent &>(event));
                break;
            case BOUNDARY_LEFT:
                handled = on_event(static_cast<BoundaryLeftEvent &>(event));
                break;
            case BOUNDARY_RIGHT:
                handled = on_event(static_cast<BoundaryRightEvent &>(event));
                break;
            default:
                break;
        }
        return handled;
    }

    virtual bool on_event(StartButtonEvent & event) { return false; }
    virtual bool on_event(ResetButtonEvent & event) { return false; }
    virtual bool on_event(TimerEvent & event) { return false; }
    virtual bool on_event(BoundaryAheadEvent & event) { return false; }
    virtual bool on_event(BoundaryLeftEvent & event) { return false; }
    virtual bool on_event(BoundaryRightEvent & event) { return false; }
    
private:
    IRobot & m_robot;
};