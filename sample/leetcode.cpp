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
#include <ctime>

#include <base/lt_util.h>


int main(int argc, char *argv[])
{
    printf("%.6f\n", lt::atof("1.23"));
    printf("%.6f\n", lt::atof("-1.23"));
    printf("%.6f\n", lt::atof("1.23e2"));
    printf("%.6f\n", lt::atof("1.23E2"));
    printf("%.6f\n", lt::atof("-1.23E+2"));
    printf("%.6f\n", lt::atof("1.23E-2"));
    printf("%.6f\n", lt::atof("-1.23E-2"));

    std::srand(std::time(NULL));

    std::vector<int> a{1, 2, 3, 4, 5};
    lt::random_shuffle(a);
    for (auto i : a) {
        printf("%d ", i);
    }
    printf("\n");

    std::vector<std::string> vs{"lei", "yun", "fei", "liu", "xiao", "xia"};
    lt::random_shuffle(vs);
    for (auto i : vs) {
        printf("%s ", i.c_str());
    }
    printf("\n");


    return 0;
}
