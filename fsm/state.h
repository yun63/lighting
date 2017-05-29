/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: state.h
 *
 * @breaf: State抽象类接口定义
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/23 00时52分23秒
 *
 **/


#ifndef  STATE_INC
#define  STATE_INC

#include "noncopyable.h"

struct Telegram;

template<class Entity>
class State : public nonecopyable {
public:
    virtual ~State();
    /**
     * @brief 当进入该State时调用
     *
     * @param e 实体
     */
    virtual void Enter(Entity *e) = 0;
    /**
     * @brief State更新方法
     *
     * @param e 实体
     */
    virtual void Excute(Entity *e) = 0;
    /**
     * @brief 当退出该State时调用
     *
     * @param e 实体
     */
    virtual void Exit(Entity *e) = 0;
    /**
     * @brief 当接收到来自message dispatcher的消息时执行
     *
     * @param e 实体
     *
     * @return 
     */
    virtual bool OnMessage(Entity *e) = 0;

private:
    /* data */
};

#endif   // ----- #ifndef STATE_INC  -----
