/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: main.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/23 17时03分57秒
 *
 **/

#include "driver.h"

int main(int argc, char *argv[])
{
    Driver *dr1 = new Driver();
    Command *cmd1 = new RushOrderCmd(dr1);
    Command *cmd2 = new IgnoreOrderCmd(dr1);

    Didi *dd = new Didi();

    dd->SetCmd(cmd1);
    dd->Notify();

    dd->SetCmd(cmd2);
    dd->Notify();

    return 0;
}

