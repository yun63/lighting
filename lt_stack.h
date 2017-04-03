/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_stack.h
 *
 * @breaf: 栈的实现
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/03 23时39分11秒
 *
 **/


#ifndef  LT_STACK_INC
#define  LT_STACK_INC

#include <sstream>

#include "lt_node.h"
#include "basic_types.h"
#include "lt_exception.h"

namespace lt {

/*

#include "lt_list.h"

template<class T>
class Stack {
public:
    Stack() : slist_() {}
    ~Stack() {}

    bool empty() const { return slist_.empty(); }
    uint32_t size() const { return slist_.size(); }
    void clear() { slist_.clear(); }

    void push(const T &elem) { slist_.push_back(elem); }
    T &top() const { return slist.get(slist_.size()); }
    T pop() { return slist_.pop_back(); }
};

 */

template<class T>
class Stack {
public:
    Stack () : top_(nullptr), size_(0) {}
    virtual ~Stack ();
    /**
     * @brief 判空
     *
     * @return 
     */
    bool empty() const { return top_ == NULL; }
    /**
     * @brief 栈长
     *
     * @return 
     */
    uint32_t size() const { return size_; }
    /**
     * @brief 入栈
     *
     * @param elem
     */
    void push(const T &elem);
    /**
     * @brief 获取栈顶数据
     *
     * @return 
     */
    T &top() const;
    /**
     * @brief 出栈
     *
     * @return 
     */
    T pop();
    /**
     * @brief 清空栈
     */
    void clear();

private:
    lt::LinkNode<T> *top_;
    uint32_t    size_;
};


template<class T>
Stack<T>::~Stack() {
    clear();
}

template<class T>
void Stack<T>::push(const T &elem) {
    top_ = new LinkNode<T>(elem, top_);
    ++size_;
}

template<class T>
T &Stack<T>::top() const {
    if (empty()) {
        std::ostringstream s;
        s << "EmptyStack exception, size = " << size_;
        throw Exception(s.str().c_str());
    }
    return top_->data;
}

template<class T>
T Stack<T>::pop() {
    if (empty()) {
        std::ostringstream s;
        s << "EmptyStack exception, size = " << size_;
        throw Exception(s.str().c_str());
    }
    LinkNode<T> *pn = top_->next;
    T elem = top_->data;
    delete top_;
    top_ = pn;
    --size_;
    return elem;
}

template<class T>
void Stack<T>::clear() {
    while (top_) {
        LinkNode<T> *p = top_->next;
        delete top_;
        top_ = p;
    }
    size_ = 0;
}


} // namespace lt

#endif   // ----- #ifndef LT_STACK_INC  -----
