/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#include "statemachine.h"

namespace statemachine
{
    State::State(char const * name, State * parent) :
        m_name(name),
        m_active_state(nullptr),
        m_parent_state(parent)
    {}

    Result State::transition_to_state(State * state)
    {
        State * s = active_state();
        State * common_parent = s->find_common_parent(state);

        if (!common_parent)
        {
            // Destination state does not exist in state machine.
            return STATE_TRANSITION_FAILED;
        }

        // Call on_exit() from active state to common parent.
        for (; s != common_parent->m_parent_state; s = s->m_parent_state)
        {
            s->on_exit();
        }

        // Update active state pointers from common parent to `state`.
        state->m_active_state = nullptr;
        for (s = state; s != common_parent; s = s->m_parent_state)
        {
            s->m_parent_state->m_active_state = s;
        }

        // Call on_entry from common parent's active state to `state`.
        for (s = common_parent->m_active_state; s; s = s->m_active_state)
        {
            s->on_entry();
        }

        return state->on_initialize();
    }

    Result State::transition_to_history(State * state)
    {
        // Follow new state's active state history down one sub-state.
        if (state->m_active_state) 
        {
            state = state->m_active_state;
        }
        return transition_to_state(state);
    }

    Result State::transition_to_deep_history(State * state)
    {
        // Follow new state's active state history all the way down.
        while (state->m_active_state)
        {
            state = state->m_active_state;
        }
        return transition_to_state(state);
    }

    Result State::handle_event(Event & event)
    {
        bool handled = false;

        for
        (
            State * s = active_state();
            s and !(handled = s->on_event(event));
            s = s->m_parent_state
        )
            // Event handled in for loop parameters.
            ;

        return handled ? OK : EVENT_NOT_HANDLED;
    }

    char const * const State::active_state_name()
    {
        return active_state()->m_name;
    }

    State * State::root_state()
    {
        State * s = this;
        while (s->m_parent_state)
        {
            s = s->m_parent_state;
        }

        return s;
    }

    State * State::active_state()
    {
        State * s = root_state();
        while (s->m_active_state) 
        {
            s = s->m_active_state;
        }

        return s;
    }

    Result State::on_initialize() 
    {
        return OK;
    }

    Result State::on_entry() 
    {
        return OK;
    }

    Result State::on_exit() 
    {
        return OK;
    }

    bool State::on_event(Event & event)
    {
        return false;
    }

    State * State::find_common_parent(State * other)
    {
        if (other)
        {
            for (State * l = this; l; l = l->m_parent_state)
            {
                for
                (
                    State * r = other->m_parent_state;
                    r;
                    r = r->m_parent_state
                )
                {
                    if (r == l)
                    {
                        // Common parent found.
                        return r;
                    }
                }
            }
        }

        // No common parent.
        return nullptr;
    }
}