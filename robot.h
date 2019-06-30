#pragma once

#include <Wire.h>
#include <Zumo32U4.h>
#include "eventqueue.h"

enum Boundary
{
    NO_BOUNDARY,
    BOUNDARY_AHEAD,
    BOUNDARY_LEFT,
    BOUNDARY_RIGHT
};

class IRobot
{
public:
    // Call in `setup()`.
    void setup();

    // Call at the beginning of `loop()` to generate state machine events.
    void generate_events(EventQueue & q);
    
    // State machine interfaces.
    void display(char const * msg);
    void start_timer(unsigned long timeout);

private:
    Boundary boundary_detect();

    Zumo32U4ButtonB start_button;
    Zumo32U4LCD lcd;
    Zumo32U4LineSensors boundary_sensor;

    // Timer "register". Use `start_timer()` to set.
    unsigned long end_time;
};