/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_queue.h
 *
 * @breaf: 基于链式结点实现的队列
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/03 19时14分23秒
 *
 **/


#ifndef  LT_QUEUE_INC
#define  LT_QUEUE_INC

#include <sstream>

#include "lt_node.h"
#include "noncopyable.h"
#include "lt_exception.h"

namespace lt {


//基于单链表的队列实现
//template<class T>
//class Queue : public noncopyable {
//public:
//    Queue () : qlist_() {}
//    virtual ~Queue () {}
//    /**
//     * @brief 队列是否为空
//     *
//     * @return true: 空队列 false: 非空
//     */
//    bool empty() const { return qlist_.empty(); }
//    /**
//     * @brief 求队列长度
//     *
//     * @return 
//     */
//    int size() const { return qlist_.size(); }
//    /**
//     * @brief 清空队列
//     */
//    void clear() const { return qlist_.clear(); }
//    /**
//     * @brief 入队列
//     *
//     * @param elem
//     */
//    void push(const T &elem) {
//        qlist_.push_back(elem);
//    }
//    /**
//     * @brief 出队列
//     *
//     * @return 
//     */
//    T pop() {
//        return qlist_.pop_front();
//    }
//    /**
//     * @brief 获取队列头部数据
//     *
//     * @return 
//     */
//    T front() const {
//        return qlist_.get(1).data;
//    }
//    /**
//     * @brief 队尾数据
//     *
//     * @return 
//     */
//    T back() const {
//        return qlist_.get(size()).data;
//    }
//
//private:
//    /* data */
//    lt::List<T> qlist_;
//};

template<class T>
class Queue : public noncopyable {
public:
    Queue ();
    virtual ~Queue ();

    bool empty() const { return front_ == rear_; }
    int  size() const { return size_; }
    void clear();

    void push(const T &elem);
    T pop();
    T &front() const;
    T &back() const;

private:
    LinkNode<T> *front_;
    LinkNode<T> *rear_;
    uint32_t    size_;
};

template<class T>
Queue<T>::Queue() 
    : size_(0) {
    // 生成头结点
    front_ = rear_ = new LinkNode<T>();
}

template<class T>
Queue<T>::~Queue() {
    while (front_ != rear_) {
        LinkNode<T> *n = front_->next;
        delete front_;
        front_ = n;
    }
    delete front_;
    front_ = rear_ = nullptr;
}

template<class T>
void Queue<T>::clear() {
    LinkNode<T> *p = front_->next;
    while (p) {
        LinkNode<T> *n = p->next;
        delete p;
        p = n;
    }
    rear_ = front_;
    size_ = 0;
}

template<class T>
void Queue<T>::push(const T &elem) {
    LinkNode<T> *s = new LinkNode<T>(elem);
    rear_->next = s;
    rear_ = s;
    ++size_;
}

template<class T>
T Queue<T>::pop() {
    if (empty()) {
        std::ostringstream s;
        s << "EmptyQueue exception" << ", size = " << size_;
        throw Exception(s.str().c_str());
 
    }
    LinkNode<T> *f = front_->next;
    front_->next = f->next;
    T elem = f->data;
    if (f == rear_) {
        rear_ = front_;
    }
    delete f;
    --size_;
    return elem;
}

template<class T>
T &Queue<T>::front() const {
    if (empty()) {
        std::ostringstream s;
        s << "EmptyQueue exception" << ", size = " << size_;
        throw Exception(s.str().c_str());
    }
    return front_->next->data;
}

template<class T>
T &Queue<T>::back() const {
    if (empty()) {
        std::ostringstream s;
        s << "EmptyQueue exception" << ", size = " << size_;
        throw Exception(s.str().c_str());
    }
    return rear_->data;
}

} // namespace lt

#endif   // ----- #ifndef LT_QUEUE_INC  -----
