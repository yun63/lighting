/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: basic_types.h
 *
 * @breaf: 基础类型定义
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/30 18时41分46秒
 *
 **/


#ifndef _BASICTYPES_H_
#define _BASICTYPES_H_

#include <stdint.h>

typedef int8_t              int8;
typedef int16_t             int16;
typedef int32_t             int32;
typedef int64_t             int64;

typedef uint8_t             uint8;
typedef uint16_t            uint16;
typedef uint32_t            uint32;
typedef uint64_t            uint64;

typedef unsigned char       byte;

const uint16 kUInt16Max = (   (uint16) 0xFFFF);
const uint32 kUInt32Max = (   (uint32) 0xFFFFFFFF);
const uint64 kUInt64Max = ( (((uint64) kUInt32Max) << 32) | kUInt32Max );

const  int8  kInt8Max   = (   (  int8) 0x7F);
const  int16 kInt16Max  = (   ( int16) 0x7FFF);
const  int32 kInt32Max  = (   ( int32) 0x7FFFFFFF);
const  int64 kInt64Max =  ( ((( int64) kInt32Max) << 32) | kUInt32Max );

const  int8  kInt8Min   = (   (  int8) 0x80);
const  int16 kInt16Min  = (   ( int16) 0x8000);
const  int32 kInt32Min  = (   ( int32) 0x80000000);
const  int64 kInt64Min =  ( ((( int64) kInt32Min) << 32) | 0 );

#endif  // _BASICTYPES_H_
