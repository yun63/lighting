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
 * @create: 2018/03/14 18时29分10秒
 *
 **/

#include "record.h"

#include <cassert>

void DoSomeStuffWithMonster(const PrototypeMonster *original_monster) {
    PrototypeMonster *newmonster = original_monster->Clone();
    assert(newmonster);
    newmonster->set_name("MyOwnMonster");
    std::cout << newmonster->get_name() << std::endl;
    delete newmonster;
}

int main(int argc, char *argv[])
{
    RecordFactory factory;
    auto record = factory.CreateRecord(CAR);
    record->print();

    record = factory.CreateRecord(BIKE);
    record->print();

    record = factory.CreateRecord(PERSON);
    record->print();

    PurpleMonster monster;
    DoSomeStuffWithMonster(&monster);

    return 0;
}

