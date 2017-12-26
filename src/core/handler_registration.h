/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: handler_registration.h
 *
 * @breaf: 接口类
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017年12月27日 06时20分17秒
 *
 **/


#ifndef  HANDLER_REGISTRATION_INC
#define  HANDLER_REGISTRATION_INC

#include "base/Object.h"

class HandlerRegistration : public lt::Object {
public:
    virtual ~HandlerRegistration() {} 

    virtual void RemoveHandler() = 0;
};

#endif   // ----- #ifndef HANDLER_REGISTRATION_INC  -----
