/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
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
    // Change the following value to match the gear ratio of your Zumo.
    // The formula derivation is as follows:
    //
    // The circumference of the circle enscribed by a robot spinning in place
    // (one tread going forward, one tread going backwards at the same speed)
    // is
    //    Cr = r * pi
    // 
    // The distrance travelled in one wheel rotation is
    //    Cw = w * pi
    //
    // The number of encoder counts per wheel revolution is
    //    Ew = g * e
    //
    // The number of encoder counts in 1 degree of robot rotation is
    //    Er = ((Cr / Cw) * Ew) / 360
    //    
    // Where
    //    g = gear ratio of the Zumo.
    //        (ie 50 for 50:1, 75 for 75:1, 100 for 100:1)
    //    e = encoder counts / motor revolution.
    //        This is 12, per the documentation.
    //    r = robot width, center of tread to center of tread.
    //        Measured to be 88 mm.
    //    w = diameter of wheel, with tread attached.
    //        Measured to be 38 mm.
    //
    // Motor Gearing  Encoder counts per degree rotation 
    // =============  ================================== 
    //          50:1  4                                  
    //          75:1  6                                  
    //         100:1  8                                  
    long const encoder_counts_per_degree_rotation = 4;

    Boundary boundary_detect();

    Zumo32U4ButtonB start_button;
    Zumo32U4Encoders encoders;
    Zumo32U4LCD lcd;
    Zumo32U4LineSensors boundary_sensor;
    Zumo32U4Motors motors;

    // Timer "register". Use `start_timer()` to set.
    unsigned long end_time;
};