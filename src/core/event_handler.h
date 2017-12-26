/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: event_handler.h
 *
 * @breaf: 事件处理
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017年12月18日 07时43分30秒
 *
 **/


#ifndef  EVENT_HANDLER_INC
#define  EVENT_HANDLER_INC

#include <cassert>
#include "base/object.h"

namespace lt {

class Event;

template <typename T>
class EventHandler {
public:
    /**
     * @brief 默认构造函数 
     *
     * 当EventHandler模板参数T并非从Event类继承时发生断言错误
     */
    EventHandler() {
        static_assert(std::is_base_of<Event, T>::value, "EventHandler<T>: T must be a class derived from Event");
    }
    /**
     * @brief 空虚析构函数
     */
    virtual ~EventHandler() {}

    virtual void OnEvent(T &) = 0;

    /**
     * @brief 派发一个通用的事件给合适的监听者
     *
     * @param event 派发的事件实例
     */
    void Dispatch(Event &event) {
        OnEvent(dynamic_cast<T &>(event));
    }
};

}; // namespace lt

#endif   // ----- #ifndef EVENT_HANDLER_INC  -----
