/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: driver.h
 *
 * @breaf: 滴滴打车
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/23 16时37分30秒
 *
 **/

#ifndef  DRIVER_INC
#define  DRIVER_INC

#include <iostream>
#include <vector>

using namespace std;

class Driver {
public:
    void RushOrder() {
        cout << "马上到达!\n";
    }

    void IgnoreOrder() {
        cout << "忽略订单!\n";
    }
};


class Command {
public:
    Command(Driver *dr) : driver_(dr) {}

    virtual void ExecuteCmd() = 0;

protected:
    Driver *driver_;
};


class RushOrderCmd : public Command {
public:
    RushOrderCmd(Driver *dr) : Command(dr) {}
    virtual void ExecuteCmd() {
        driver_->RushOrder();
    }
};


class IgnoreOrderCmd : public Command {
public:
    IgnoreOrderCmd(Driver *dr) : Command(dr) {}
    virtual void ExecuteCmd() {
        driver_->IgnoreOrder();
    }
};


class Didi {
public:
    void SetCmd(Command *cmd) {
        cmd_ = cmd;
    }

    void Notify() {
        cmd_->ExecuteCmd();
    }

private:
    Command *cmd_;
};

#endif   // ----- #ifndef DRIVER_INC  -----

