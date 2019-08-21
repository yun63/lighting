/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: light.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/23 17时15分45秒
 *
 **/

#ifndef  LIGHT_INC
#define  LIGHT_INC

#include <iostream>

using namespace std;

class Light;


class Command {
public:
    virtual void Execute() = 0;

protected:
    Light *light_;
};


class Light {
public:
    void TurnOn() {
        std::cout << "Light turn on!";
    }

    void TurnOff() {
        std::cout << "Light turn off!";
    }
};


class TurnOnCmd : public Command {
public:
    TurnOnCmd(Light *lt) : light_(lt) {}
    void Execute() {
        light_->TurnOn();
    }
};


class TurnOffCmd : public Command {
public:
    TurnOffCmd(Light *lt) : light_(lt) {}
    void Execute() {
        light_->TurnOff();
    }
};


class Switch {
public:
    Switch(Command &turn_on, Command &turn_off) : turn_on_cmd_(turn_on), turn_off_cmd_(turn_off) {}

    void TurnOn() {
        turn_on_cmd_.Execute();
    }

    void TurnOff() {
        turn_off_cmd_.Execute();
    }

private:
    TurnOnCmd &turn_on_cmd_;
    TurnOffCmd &turn_off_cmd_;
};

#endif   // ----- #ifndef LIGHT_INC  -----
