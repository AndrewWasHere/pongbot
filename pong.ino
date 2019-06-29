#include "advancingstate.h"
#include "events.h"
#include "eventqueue.h"
#include "initstate.h"
#include "pongstatemachine.h"
#include "robot.h"
#include "standbystate.h"
#include "turningstate.h"

// Robot interface.
IRobot robot;

// State machine.
PongStateMachine machine(nullptr, robot);
InitState initalized(&machine, robot);
StandbyState standby(&machine, robot);
AdvancingState advancing(&machine, robot);
TurningState turning(&machine, robot);

// Events.
StartButtonEvent start_event;
ResetButtonEvent reset_event;
TimerEvent timer_event;
BoundaryAheadEvent boundary_ahead_event;
BoundaryLeftEvent boundary_left_event;
BoundaryRightEvent boundary_right_event;

EventQueue queue;

void setup()
{

}

void loop()
{
    // Read sensors, and generate events.

    // Process events.
    while (!queue.empty())
    {
        Event * e = queue.pop();
        machine.handle_event(*e);
    }
}