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
    void cancel_timer();
    void start_timer(unsigned long timeout);
    void move_forward();
    void move_stop();
    void turn_left(int degrees);
    void turn_right(int degrees);

private:
    int const speed = 150;
    // Change this to match the gear ratio of your Zumo.
    long int const gear_ratio = 50;
    long int const encoder_count_per_motor_revolution = 12;

    Boundary boundary_detect();

    Zumo32U4ButtonB start_button;
    Zumo32U4Encoders encoders;
    Zumo32U4LCD lcd;
    Zumo32U4LineSensors boundary_sensor;
    Zumo32U4Motors motors;

    // Timer "register". Use `start_timer()` to set.
    unsigned long end_time;
};