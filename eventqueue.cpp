#include "eventqueue.h"

EventQueue::EventQueue() : m_write_idx(0), m_read_idx(0)
{}

bool EventQueue::empty() 
{ 
    return m_write_idx == m_read_idx; 
}

void EventQueue::push(Event * e)
{
    m_queue[m_write_idx] = e;
    if (++m_write_idx >= QUEUE_SIZE)
    {
        m_write_idx = 0;
    };
}

Event * EventQueue::pop()
{
    unsigned int idx = m_read_idx;
    if (++m_read_idx >= QUEUE_SIZE)
    {
        m_read_idx = 0;
    }
    return m_queue[idx];
}
