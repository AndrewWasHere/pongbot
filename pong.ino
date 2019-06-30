/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include <Wire.h>
#include <Zumo32U4.h>
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
InitState initialized(&machine, robot);
StandbyState standby(&machine, robot);
AdvancingState advancing(&machine, robot);
TurningState turning(&machine, robot);

// Events.
StartButtonEvent start_event;
TimerEvent timer_event;
BoundaryAheadEvent boundary_ahead_event;
BoundaryLeftEvent boundary_left_event;
BoundaryRightEvent boundary_right_event;

EventQueue queue;

void setup()
{
    // Initialize robot.
    robot.setup();

    // Initialize state machine.
    machine.transition_to_state(&machine);
}

void loop()
{
    // Read sensors, and generate events.
    robot.generate_events(queue);

    // Process events.
    while (!queue.empty())
    {
        Event * e = queue.pop();
        machine.handle_event(*e);
    }
}