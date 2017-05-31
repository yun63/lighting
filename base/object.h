/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: object.h
 *
 * @breaf: 类继承体系的基类，所有的事件处理都需继承该类
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/05/31 20时49分04秒
 *
 **/


#ifndef  OBJECT_INC
#define  OBJECT_INC

namespace lt {


class Object {
public:
    /**
     * @brief 类的默认构造函数
     */
    Object() {}
    /**
     * @brief 空的虚析构函数
     */
    virtual ~Object() {}
    /**
     * @brief 拷贝构造函数
     *
     * @param other
     */
    Object(const Object &other) {}
};

} // namespace lt

#endif   // ----- #ifndef OBJECT_INC  -----
