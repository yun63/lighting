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
 * @create: 2018/03/19 20时45分58秒
 *
 **/

#include "adapter.h"

int main(int argc, char *argv[])
{
    HinduFemale *hindu_girl = new HinduFemale;
    MuslimFemale *muslim_girl = new MuslimFemale;
    HinduRitual hindu_ritual;
//    hindu_ritual.CarryOutRitual(muslim_girl); // will not compile of course since the parameter must be Hindu*
    HinduAdapter *adapter_muslim = new HinduAdapter(muslim_girl);
    hindu_ritual.CarryOutRitual(hindu_girl);
    hindu_ritual.CarryOutRitual(adapter_muslim);

    delete adapter_muslim;
    delete muslim_girl;
    delete hindu_girl;

    return 0;
}
