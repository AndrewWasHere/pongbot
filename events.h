/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

#include "statemachine.h"

using namespace statemachine;
enum PongEvent
{
    START_EVENT,
    TIMER_EVENT,
    BOUNDARY_AHEAD_EVENT,
    BOUNDARY_LEFT_EVENT,
    BOUNDARY_RIGHT_EVENT
};

class StartButtonEvent : public Event
{
public:
    StartButtonEvent() : Event(START_EVENT, "start") {}
};

class TimerEvent : public Event
{
public:
    TimerEvent() : Event(TIMER_EVENT, "timer") {}
};

class BoundaryAheadEvent : public Event
{
public:
    BoundaryAheadEvent() : Event(BOUNDARY_AHEAD_EVENT, "bdy-a") {}
};

class BoundaryLeftEvent : public Event
{
public:
    BoundaryLeftEvent() : Event(BOUNDARY_LEFT_EVENT, "bdy-l") {}
};

class BoundaryRightEvent : public Event
{
public:
    BoundaryRightEvent() : Event(BOUNDARY_RIGHT_EVENT, "bdy-r") {}
};