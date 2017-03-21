/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_node.h
 *
 * @breaf: 结点类型的定义及实现：单链表结点、双端链表结点、二叉树结点
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/03/10 23时36分55秒
 *
 **/


#ifndef  LT_NODE_INC
#define  LT_NODE_INC

namespace lt {

template<class T>
struct LinkNode {
    LinkNode()
        : data(), next(nullptr) {}
    LinkNode(const T &elem)
        : data(elem), next(nullptr) {}
    ~LinkNode() {
        next = nullptr;
    }
    T data;
    LinkNode<T> *next;
};

template<class T>
struct DoubleNode {
    DoubleNode()
        : data(), prev(nullptr), next(nullptr) {}
    DoubleNode(const T &elem)
        : data(elem), prev(nullptr), next(nullptr) {}
    ~DoubleNode() {
        prev = next = nullptr;
    }
    T  data;
    LinkNode<T> *prev;
    LinkNode<T> *next;
};

} // namespace lt


#endif   // ----- #ifndef LT_NODE_INC  -----
