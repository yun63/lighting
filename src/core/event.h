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

#include "base/object.h"

namespace lt {


class Event : public Object {
public:
    Event(Object &sender)
        : sender_(sender), canceled_(false) {}
    /**
     * @brief 空析构函数
     */
    virtual ~Event() {}
    /**
     * @brief 获取本事件的派发对象
     *
     * @return  事件派发者
     */
    Object &sender() const {
        return sender_;
    }
    /**
     * @brief 判定事件是否被取消
     *
     * @return true:已经取消; false:未取消
     */
    bool canceled() const { return canceled_; }
    /**
     * @brief 设置事件取消状态
     *
     * @param cancel
     */
    void set_canceled(bool cancel) { canceled_ = canceled; }

private:
    /* data */
    Object &sender_;
    bool canceled_;
};

} // namespace lt

#endif   // ----- #ifndef EVENT_INC  -----
