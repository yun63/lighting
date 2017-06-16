/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_list.h
 *
 * @breaf: 单链表及循环链表的实现
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/03/11 00时21分09秒
 *
 * @modify: 
 *
 *  1. 循环链表的实现
 *
 *  @author: Lei Yunfei(towardstheway@gmail.com)
 *
 *  @date: 2017/06/16 15时25分58秒
 *
 *  2. 双端链表的实现
 *
 *  @author: Lei Yunfei(towardstheway@gmail.com)
 *
 **/


#ifndef  LT_LIST_INC
#define  LT_LIST_INC

#include <cstdint>
#include <sstream>

#ifdef TEST
#include <iostream>
#endif

#include "lt_node.h"
#include "noncopyable.h"
#include "lt_exception.h"

namespace lt {

template<class T>
class List : public noncopyable {
    typedef LinkNode<T>* LinkedPtr;
public:
    List();
    virtual ~List();
    /**
     * @brief 判空
     *
     * @return 
     */
    bool empty() const {
        return size_ == 0;
    }
    /**
     * @brief 获得链表长度(只有头结点，链表长度定义为0)
     *
     * @return 
     */
    int size() const {
        return size_;
    }
    /**
     * @brief 获取第pos个结点, 头结点定义为第0个结点
     *
     * @param pos 位置
     *
     * @return 
     */
    LinkedPtr get(int pos) const;
    /**
     * @brief 在链表头部插入新结点
     *
     * @param elem
     */
    void push_front(const T &elem);
    /**
     * @brief 摘除链表头部结点，并返回该结点的数据域
     *
     * @return 
     */
    T pop_front();
    /**
     * @brief 从列表尾部插入结点
     *
     * @param elem
     */
    void push_back(const T &elem);
    /**
     * @brief 摘除链表尾部结点，并返回该结点的数据域
     *
     * @return 
     */
    T pop_back();
    /**
     * @brief 在指定位置pos后插入新结点
     *
     * @param elem 新结点的数据域
     * @param pos 插入的位置
     */
    void insert_after(const T &elem, int pos);
    /**
     * @brief 删除指定位置pos的结点，并返回结点的数据域
     *
     * @return 
     */
    T erase(int pos);
    /**
     * @brief 删除指定范围【begin,end】的所有结点
     *
     * @param begin
     * @param end
     */
    void erase(int begin, int end);
    /**
     * @brief 清空链表，并释放结点占用的空间
     */
    void clear();
    /**
     * @brief 翻转单链表
     *
     * @return 
     */
    LinkNode<T> *reverse();

    /**
     * @brief 按格式打印单链表
     */
    void Print() const;

private:
    void valid_index_check(int index) const;

    LinkNode<T> *head_;
    uint32_t size_;
};

template<class T>
List<T>::List()
    : head_(new LinkNode<T>()), size_(0) {}

template<class T>
List<T>::~List() {
    while (head_->next) {
        LinkedPtr n = head_->next;
        head_->next = n->next;
        delete n;
    }
    delete head_; // 释放头结点 
}

template<class T>
void List<T>::valid_index_check(int index) const {
    if (index < 0 || index > size_) {
        std::ostringstream s;
        s << "out of range: index = " <<  index << ", size = " << size_;
        throw Exception(s.str().c_str());
    }
}

template<class T>
LinkNode<T> *List<T>::get(int pos) const {
    valid_index_check(pos);
    int i = 0;
    LinkedPtr p = head_;
    while (i != pos && p != NULL) {
        p = p->next;
        ++i;
    }
    return p;
}

template<class T>
void List<T>::push_front(const T &elem) {
    insert_after(elem, 0);
}

template<class T>
T List<T>::pop_front() {
    if (empty()) {
        throw Exception("pop from empty list");
    }
    LinkedPtr p = head_->next;
    head_->next = p->next;
    T elem = p->data;
    delete p;
    --size_;
    return elem;
}

template<class T>
void List<T>::push_back(const T &elem) {
    insert_after(elem, size_);
}

template<class T>
T List<T>::pop_back() {
    if (empty()) {
        throw Exception("pop from empty list");
    }
    /*
    LinkedPtr p = head_;
    while (p->next) {
        p = p->next;
    }
    T elem = p->data;
    delete p;
    */
    LinkedPtr p = head_;
    LinkedPtr prev = NULL;
    int i = 0;
    while (i != size_) {
        prev = p;
        p = p->next;
        ++i;
    }
    T elem = p->data;
    prev->next = p->next;
    delete p;
    --size_;
    return elem;
}

template<class T>
void List<T>::insert_after(const T &elem, int pos) {
    valid_index_check(pos);
    LinkedPtr p = head_;
    int i = 0;
    while (i != pos && p != NULL) {
        p = p->next;
        ++i;
    }
    LinkedPtr n = p->next;
    LinkedPtr s = new LinkNode<T>(elem);
    p->next = s;
    s->next = n;
    ++size_;
}

template<class T>
void List<T>::clear() {
//    LinkedPtr p = head_->next;
//    while (p != NULL) {
//        LinkedPtr n = p->next;
//        delete p;
//        p = n;
//    }
//    head_->next = NULL;
    while (head_->next) {
        LinkedPtr p = head_->next;
        head_->next = p->next;
        delete p;
    }
    size_ = 0;
}

template<class T>
LinkNode<T> *List<T>::reverse() {
    LinkedPtr prev = NULL;
    LinkedPtr cur = head_->next;
    while (cur != NULL) {
        LinkedPtr n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    head_->next = prev;
    return head_;
}

template<class T>
void List<T>::Print() const {
    LinkedPtr p = head_->next;
    printf("HEAD");
    while (p != NULL) {
        printf(" -> %d", p->data);
        p = p->next;
    }
    printf("\n");
}

#ifdef TEST
template<class T>
std::ostream &operator << (std::ostream &os, const List<T> &list) {
    list.Print();
    return os;
}
#endif


/// ---------------------------

template<class T>
class CircularList : public noncopyable {
    typedef LinkNode<T>* LinkedPtr;
public:
    CircularList();
    virtual ~CircularList();

    int size() const { return size_; }

private:
    LinkNode<T> *head_;
    uint32_t size_;
};


template<class T>
CircularList<T>::CircularList()
    : head_(new LinkNode<T>()) , size_(0) {
    head_->next = head_;
}

template<class T>
CircularList<T>::~CircularList() {
    while (head_->next != head_) {
        LinkedPtr n = head_->next;
        head_->next = n->next;
        delete n;
    }
    delete head_;
    head_ = NULL;
}


} // namespace lt

#endif   // ----- #ifndef LT_LIST_INC  -----
