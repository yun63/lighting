/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_string.h
 *
 * @breaf: string的字符串
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/24 16时56分01秒
 *
 **/


#ifndef  LT_STRING_INC
#define  LT_STRING_INC

#include <algorithm>

namespace goost {

class String {
public:
    String()
        : data_(new char[1]) {
        *data_ = '\0';
    }

    String(const char *pstr)
        : data_(new char[strlen(pstr) + 1]) {
        strcpy(data_, pstr);
    }

    String(const String &other)
        : data_(new char[other.size()] + 1) {
            strcpy(data_, other.data_);
        }

    String &operator = (const String &other) {
        if (this == &other) {
            return *this;
        }
        String tmp(other);
        swap(tmp);
        return *this;
    }

    virtual ~String() {
        delete []data_;
        data_ = NULL;
    }

    const char *c_str() const {
        return data_;
    }

    std::size_t size() const {
        return strlen(data_);
    }

    bool empty() const {
        return this->size() == 0;
    }

private:
    void swap(String &rhs) {
        std::swap(data_, rhs.data_);
    }

    char *data_;
};


} // namespace goost 

#endif   // ----- #ifndef LT_STRING_INC  -----
