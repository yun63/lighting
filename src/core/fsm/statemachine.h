/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: statemachine.h
 *
 * @breaf: 状态机
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/23 22时09分02秒
 *
 **/

#ifndef  STATEMACHINE_INC
#define  STATEMACHINE_INC

#include <string>
#include "state.h"
#include "noncopyable.h"

template<class T>
class StateMachine : public nonecopyable {
public:
    StateMachine(T *ower)
        : ower_(ower)
        , curr_state_(NULL)
        , prev_state_(NULL)
        , global_state_(NULL)
    {}

    virtual ~StateMachine();

    void set_previous_state(State<T> *s) { previous_state_ = s; }
    void set_current_state(State<T> *s) { current_state_ = s; }
    void set_global_state(State<T> *s) { global_state_ = s; }
    /**
     * @brief Call this to update the FSM
     */
    void Update() const {
        if (global_state_) {
            global_state_->Execute(ower_);
        }
        if (current_state_) {
            current_state_->Execute(ower_);
        }
    }
    bool HandleMessage(const Telegram &msg) const {
        if (current_state_ && current_state_->OnMessage(owner_, msg)) {
            return true;
        }
        if (global_state_ && global_state_->OnMessage(ower_, msg)) {
            return true;
        }
        return false;
    }
    /**
     * @brief Change to a new state
     *
     * @param new_state
     */
    void ChangeState(State<T> *new_state) {
        // Keep a record of the previous state
        previous_state_ = current_state_;
        // Call the Exit method of the existing state
        current_state_->Exit(owner_);
        // Change state to the new state
        current_state_ = new_state;
        // Call the Enter method of the new state
        current_state_->Enter(ower_);
    }
    /**
     * @brief Change state back to the previous state
     */
    void RevertToPreviousState() {
        ChangeState(previous_state_);
    }
    /**
     * @brief Return true if the current state's type is equal to 
     * the type of the class passed as a parameter
     *
     * @param state
     *
     * @return 
     */
    bool IsInstance(const State<T> &state) const {
        return typeid(*current_state_) == typeid(state);
    }
    std::string GetCurrentStateName() const {
        std::string s(typeid(*current_state_).name());
        return s.size() > 5 ? s.erase(0, 6) : s;
    }

private:
    // A pointer to the agent that owns this instance
    T           *ower_;
    State<T>    *curr_state_;
    // A record of the last state the agent was in
    State<T>    *prev_state_;
    // This is called every time the FSM is updated
    State<T>    *global_state_;
};
#endif   // ----- #ifndef STATEMACHINE_INC  -----
