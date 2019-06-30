/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

#include "events.h"

#define QUEUE_SIZE 6

class EventQueue
{
public:
    EventQueue();
    bool empty();
    void push(Event * e);
    Event * pop();

private:
    unsigned int m_write_idx;
    unsigned int m_read_idx;
    Event * m_queue[6];
};