/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: exception.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/13 18时35分48秒
 *
 **/

#include "lt_exception.h"

#include <execinfo.h>
#include <stdlib.h>

using namespace lt;

Exception::Exception(const char *what) : message_(what) {
    const int len = 100;
    void *buffer[len];
    // 打印调用栈信息
    int nptrs = ::backtrace(buffer, len);
    char **strings = ::backtrace_symbols(buffer, nptrs);
    if (strings) {
        for (int i = 0; i < nptrs; ++i) {
            stack_.append(strings[i]);
            stack_.push_back('\n');
        }
        free(strings);
    }
}

Exception::~Exception() throw() {

}

const char *Exception::what() const throw() {
    return message_.c_str();
}

const char *Exception::StackTrace() const throw() {
    return stack_.c_str();
}

