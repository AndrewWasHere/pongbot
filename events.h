#pragma once

#include "statemachine.h"

using namespace statemachine;
enum PongEvent
{
    START,
    RESET,
    TIMER,
    BOUNDARY_AHEAD,
    BOUNDARY_LEFT,
    BOUNDARY_RIGHT
};

class StartButtonEvent : public Event
{
public:
    StartButtonEvent() : Event(START, "start") {}
};

class ResetButtonEvent : public Event
{
public:
    ResetButtonEvent() : Event(RESET, "reset") {}
};

class TimerEvent : public Event
{
public:
    TimerEvent() : Event(TIMER, "timer") {}
};

class BoundaryAheadEvent : public Event
{
public:
    BoundaryAheadEvent() : Event(BOUNDARY_AHEAD, "bdy-a") {}
};

class BoundaryLeftEvent : public Event
{
public:
    BoundaryLeftEvent() : Event(BOUNDARY_LEFT, "bdy-l") {}
};

class BoundaryRightEvent : public Event
{
public:
    BoundaryRightEvent() : Event(BOUNDARY_RIGHT, "bdy-r") {}
};