/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: leetcode.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/03/08 23时12分17秒
 *
 **/

#include <stdio.h>

#include "lt_util.h"


int main(int argc, char *argv[])
{
    printf("%.6f\n", lt::atof("1.23"));
    printf("%.6f\n", lt::atof("-1.23"));
    printf("%.6f\n", lt::atof("1.23e2"));
    printf("%.6f\n", lt::atof("1.23E2"));
    printf("%.6f\n", lt::atof("-1.23E+2"));
    printf("%.6f\n", lt::atof("1.23E-2"));
    printf("%.6f\n", lt::atof("-1.23E-2"));


    return 0;
}
