/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_bits.h
 *
 * @breaf: 位相关
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2019/04/10 18时48分40秒
 *
 **/

#include "lt_types.h"

/* 
 *
 * 翻转二进制位
 * 在32位机器上，25的二进制位：00000000000000000000000000011001
 * 翻转之后它的二进制位应该是：10011000000000000000000000000000，函数返回值应该是2550136832
 * */
unsigned int reverse_bits(unsigned int value) {
    unsigned int res = 0;
    for (int i = 1; i != 0; i <<= 1) {
        res <<= 1;
        if (value & 1) {
            res |= (value & 1);
        }
        value >>= 1;
    }
    return res;
}
