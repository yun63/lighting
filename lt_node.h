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
    LinkNode(const T &elem, LinkNode<T> *n)
        : data(elem), next(n) {}
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
    DoubleNode(const T &elem, DoubleNode<T> *p, DoubleNode<T> *n)
        : data(elem), prev(p), next(n) {}
    ~DoubleNode() {
        prev = next = nullptr;
    }
    T  data;
    LinkNode<T> *prev;
    LinkNode<T> *next;
};

template<class T>
struct BintreeNode {
    explicit BintreeNode(const T &elem, BintreeNode<T> *l = nullptr, BintreeNode<T> *r = nullptr)
        : data(elem), left(l), right(r) {}
    T data;                              // 数据域
    BintreeNode<T> *left;                // 左孩子结点
    BintreeNode<T> *right;               // 右孩子结点
};

} // namespace lt


#endif   // ----- #ifndef LT_NODE_INC  -----
