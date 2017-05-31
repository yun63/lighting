/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: event.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/05/31 20时46分14秒
 *
 **/


#ifndef  EVENT_INC
#define  EVENT_INC

#include <vector>
#include <stdexcept>

#include "object.h"

namespace lt {


class Event : public Object {
public:
    Event();
    virtual ~Event();

private:
    /* data */
};

} // namespace lt

#endif   // ----- #ifndef EVENT_INC  -----
