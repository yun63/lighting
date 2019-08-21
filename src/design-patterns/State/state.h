/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: state.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/23 17时38分12秒
 *
 **/


#ifndef  STATE_INC
#define  STATE_INC

#include <iosteam>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>


enum Input { DUCK_DOWN, STAND_UP, JUMP, DIVE };

class Fighter;

class StandingState;
class JumpingState;
class DivingState;


class FighterState {
public:
    static std::shared_ptr<StandingState> standing_;
    static std::shared_ptr<DivingState> diving_;
    virtual ~FighterState() = default;
    virtual void HandleInput(Fighter &input) = 0;
    virtual void Update(Fighter &) = 0;
};


class DuckingState : public FighterState {
public:
    DuckingState() : charging_time_(0) {}
    virtual void HandleInput(Fighter &input) override;
    virtual void Update(Fighter &) override;

private:
    int charging_time_;
    static const int kFullRestTime = 5;
};


class StandingState : public FighterState {
public:
    virtual void HandleInput(Fighter &) override;
    virtual void Update(Fighter &) override;
};


class JumpingState : public FighterState {
public:
    JumpingState() { jumping_height_ = std::rand(() % 5 + 1); }
    virtual void HandleInput(Fighter &input) override;
    virtual void Update(Fighter &) override;

private:
    int jumping_height_;
};


class DivingState : public FighterState {
public:
    virtual void HandleInput(FighterState &input) override;
    virtual void Update(Fighter &) override;
};


std::shared_ptr<StandingState> FighterState::standing_(new StandingState);
std::shared_ptr<DivingState> FighterState::diving_(new DivingState);


class Fighter {
public:
    Fighter(const std::string name)
        : name_(name), state_(FighterState) {}

private:
    std::string name_;
    std::shared_ptr<FighterState> state_;
    int fatigue_level_;
};

#endif   // ----- #ifndef STATE_INC  -----
