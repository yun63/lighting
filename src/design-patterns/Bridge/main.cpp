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
 * @create: 2018/03/19 21时12分53秒
 *
 **/

#include "draw.h"

int main(int argc, char *argv[])
{
    CircleShape cs1(1, 2, 3, new DrawingAAPI());
    CircleShape cs2(5, 7, 11, new DrawingBAPI());

    cs1.ResizeByPercentage(2.5);
    cs2.ResizeByPercentage(2.5);

    cs1.Draw();
    cs2.Draw();

    return 0;
}

