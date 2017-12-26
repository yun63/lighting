/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: eventbus.h
 *
 * @breaf: 事件管理总线
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017年12月27日 06时25分48秒
 *
 **/


#ifndef  EVENTBUS_INC
#define  EVENTBUS_INC

#include <list>
#include <unordered_map>

#include "base/object.h"
#include "core/event.h"
#include "core/event_handler.h"
#include "core/handler_registration.h"

class EventBus : public lt::Object {
public:
    /**
     * @brief 默认构造函数
     */
    EventBus() {}
    /**
     * @brief 空虚构函数
     */
    virtual ~EventBus() {}

    /**
     * @brief 返回单例实例
     *
     * @return 
     */
    static const EventBus *GetInstance() {
        if (instance_ == NULL) {
            instance_ = new EventBus();
        }
        return instance_;
    }

private:
    static EventBus *instance_;
};

#endif   // ----- #ifndef EVENTBUS_INC  -----
