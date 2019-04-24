/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_list.h
 *
 * @breaf: 单链表、双端链表及循环链表的实现
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

    LinkedPtr Get(int pos) const;

    LinkedPtr Get(bool (*SearchFunc)(LinkedPtr node, const T &value)) const;
    /**
     * @brief 获取第pos个结点, 头结点定义为第0个结点
     *
     * @param pos 位置
     *
     * @return 
     */

    /**
     * @brief 在链表头部插入新结点
     *
     * @param elem
     */
    void PushFront(const T &elem);
    /**
     * @brief 摘除链表头部结点，并返回该结点的数据域
     *
     * @return 
     */
    T PopFront();
    /**
     * @brief 从列表尾部插入结点
     *
     * @param elem
     */
    void PushBack(const T &elem);
    /**
     * @brief 摘除链表尾部结点，并返回该结点的数据域
     *
     * @return 
     */
    T PopBack();
    /**
     * @brief 在指定位置pos后插入新结点
     *
     * @param elem 新结点的数据域
     * @param pos 插入的位置
     */
    void InsertAfter(const T &elem, int pos);
    /**
     * @brief 删除指定位置pos的结点，并返回结点的数据域
     *
     * @return 
     */
    T Remove(int pos);
    /**
     * @brief 删除指定范围【begin,end】的所有结点
     *
     * @param begin
     * @param end
     */
    void Remove(int begin, int end);
    /**
     * @brief 清空链表，并释放结点占用的空间
     */
    void Clear();
    /**
     * @brief 翻转单链表
     *
     * @return 
     */
    LinkNode<T> *Reverse();

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
LinkNode<T> *List<T>::Get(int pos) const {
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
LinkNode<T> *List<T>::Get(bool (*SearchFunc)(LinkNode<T> *node, const T &data)) const {
    return NULL;
}

template<class T>
void List<T>::PushFront(const T &elem) {
    InsertAfter(elem, 0);
}

template<class T>
T List<T>::PopFront() {
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
void List<T>::PushBack(const T &elem) {
    InsertAfter(elem, size_);
}

template<class T>
T List<T>::PopBack() {
    if (empty()) {
        throw Exception("pop from empty list");
    }
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
void List<T>::InsertAfter(const T &elem, int pos) {
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
void List<T>::Clear() {
    while (head_->next) {
        LinkedPtr p = head_->next;
        head_->next = p->next;
        delete p;
    }
    size_ = 0;
}

template<class T>
LinkNode<T> *List<T>::Reverse() {
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


/// 双端链表的实现

template<class T>
class DList : public noncopyable {
private:
    struct RootNode {
        RootNode() : head(NULL), tail(NULL), size(0) {}
        RootNode(DoubleNode<T> *n) : head(n), tail(n), size(1) {}
        DoubleNode<T>   *head;
        DoubleNode<T>   *tail;
        size_t          size;
    };

public:

    DList();
    virtual ~DList();

    bool empty() const { return root_->head == root_->tail; }
    size_t size() const { return root_->size; }

    void Insert(DoubleNode<T> *t, const T &elem);
    void Insert(const T &elem);
    void Append(const T &elem);
    DoubleNode<T> *Remove(DoubleNode<T> *e);
    void Clear();

private:
    DoubleNode<T> *CreateNode(const T &elem);

    RootNode *root_;
};


template<class T>
DList<T>::DList()
    : root_(new RootNode()) {}

template<class T>
DList<T>::~DList() {
    Clear();
    delete root_;
    root_ = NULL;
}

template<class T>
DoubleNode<T> *DList<T>::CreateNode(const T &elem) {
    return new DoubleNode<T>(elem);
}

template<class T>
void DList<T>::Insert(DoubleNode<T> *t, const T &elem) {
    assert(root_ && root_->head != NULL && root_->tail != NULL);
}

template<class T>
void DList<T>::Insert(const T &elem) {
}

template<class T>
void DList<T>::Append(const T &elem) {
}

template<class T>
DoubleNode<T> *DList<T>::Remove(DoubleNode<T> *e) {
}


// 循环链表的现实
// 循环链表基于单链表实现，尾结点的next指针域指向头结点


} // namespace lt

#endif   // ----- #ifndef LT_LIST_INC  -----
