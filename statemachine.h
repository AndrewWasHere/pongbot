/*
    Copyright 2019, Andrew Lin.

    This source code is released under the 3-Clause BSD license. See 
    LICENSE.txt, or https://opensource.org/licenses/BSD-3-Clause.
 */
#pragma once

namespace statemachine
{
    /*
     * Return codes for State interfaces.
     */
    enum Result
    {
        OK,
        STATE_TRANSITION_FAILED,
        EVENT_NOT_HANDLED
    };

    /*
     * Base class for events that are to be processed by state machine states.
     */
    class Event
    {
    public:
        Event(int const id, char const * name) :
            m_id(id),
            m_name(name)
        {}
        virtual ~Event() = default;

        int const m_id;
        char const * m_name;
    };

    /*
     * Base class for states in the finite state machine.
     */
    class State
    {
    public:
        /*
         * State machine state constructor.
         *
         * Pass nullptr as the parent state for the root state machine state.
         * Otherwise, pass the parent state as the `parent` argument.
         */
        State(char const * name, State * parent);
        virtual ~State() = default;

        /*
         * Transition to new state.
         */
        virtual Result transition_to_state(State * state);

        /*
         * Transition to state history.
         */
        Result transition_to_history(State * state);

        /*
            Transition to state's deep history.
         */
        Result transition_to_deep_history(State * state);

        /*
         * Call this from the state machine root class instance to process
         * an event.
         */
        Result handle_event(Event & event);

        /*
         * Return the name of the active state.
         */
        char const * const active_state_name();
        
    protected:
        /*
         * Override this function to provide state initialization
         * functionality (black dot transition).
         */
        virtual Result on_initialize();

        /*
         * Override this function to provide functionality for whenever your
         * derived state is entered via a `transition_to_state` call.
         */
        virtual Result on_entry();

        /*
         * Override this function to provide functionality for whenever your
         * derived state is exited via a `transition_to_state` call.
         */
        virtual Result on_exit();

        /*
         * Overload this function to process specific events. Override this
         * function to determine the event type and call `on_event` with the
         * proper event type. See the example for a sample implementation.
         *
         * Either way, return `true` if the event was processed. Return `false`
         * if it was not, so the parent state can get a shot.
         *
         * Your machine's derived state machine class should override this
         * function and return `true`.
         */
        virtual bool on_event(Event & event);

        /*
         * Returns the root (machine) state.
         */
        State * root_state();

        /*
         * Returns the current active state.
         */
        State * active_state();

        /*
         * Find the common parent with state `other`.
         */
        State * find_common_parent(State * other);

        char const * const m_name;
        State * m_active_state;
        State * m_parent_state;
    };
}
