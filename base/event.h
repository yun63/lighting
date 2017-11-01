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
    Event(Object &sender)
        : sender_(sender), canceled_(false) {}
    virtual ~Event() {}
    Object &sender() const { return sender_; }
    bool canceled() const { return canceled_; }
    void setcanceled(bool cancel) { canceled_ = canceled; }

private:
    /* data */
    Object &sender_;
    bool canceled_;
};

} // namespace lt

#endif   // ----- #ifndef EVENT_INC  -----
