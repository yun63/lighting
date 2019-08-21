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
 * @create: 2018/03/06 15时09分02秒
 *
 **/


#include "builder.h"

int main(int argc, char *argv[])
{
    Cook cook;
    HawaiianPizzaBuilder hawaiian_pizza_builder;
    SpicyPizzaBuilder spicy_pizza_builder;

    cook.MakePizza(&hawaiian_pizza_builder);
    cook.OpenPizza();

    cook.MakePizza(&spicy_pizza_builder);
    cook.OpenPizza();

    return 0;
}
