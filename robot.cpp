#include "robot.h"

extern StartButtonEvent start_event;
extern TimerEvent timer_event;
extern BoundaryAheadEvent boundary_ahead_event;
extern BoundaryLeftEvent boundary_left_event;
extern BoundaryRightEvent boundary_right_event;

void IRobot::setup()
{
    end_time = 0;
    boundary_sensor.initThreeSensors();
}

void IRobot::generate_events(EventQueue & q)
{
    // Check start button.
    if (start_button.getSingleDebouncedPress())
    {
        q.push(&start_event);
    }

    // Check timer.
    if (end_time && millis() >= end_time)
    {
        q.push(&timer_event);
        end_time = 0;
    }

    // Check boundary sensors.
    switch(boundary_detect())
    {
    case BOUNDARY_AHEAD:
        q.push(&boundary_ahead_event);
        break;
    case BOUNDARY_LEFT:
        q.push(&boundary_left_event);
        break;
    case BOUNDARY_RIGHT:
        q.push(&boundary_right_event);
        break;
    }
}

void IRobot::display(char const * msg)
{
    lcd.clear();
    lcd.write(msg, strlen(msg));
}

void IRobot::start_timer(unsigned long timeout)
{
    end_time = millis() + timeout;
}

Boundary IRobot::boundary_detect()
{
    // below threshold => boundary.
    // above threshold => ring.
    const unsigned int threshold = 250;

    unsigned int sensor_values[3];
    boundary_sensor.read(sensor_values);
    bool left_boundary = sensor_values[0] < threshold;
    bool center_boundary = sensor_values[1] < threshold;
    bool right_boundary = sensor_values[2] < threshold;

    Boundary boundary = NO_BOUNDARY;
    if (center_boundary || (left_boundary && right_boundary))
    {
        boundary = BOUNDARY_AHEAD;
    }
    else if (left_boundary)
    {
        boundary = BOUNDARY_LEFT;
    }
    else if (right_boundary)
    {
        boundary = BOUNDARY_RIGHT;
    }

    return boundary;
}