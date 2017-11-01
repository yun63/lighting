/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: exception.h
 *
 * @breaf: 通用异常
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/13 18时32分01秒
 *
 **/


#ifndef  EXCEPTION_INC
#define  EXCEPTION_INC

#include <stdlib.h>
#include <execinfo.h>
#include <exception>
#include <string>

namespace lt {

class Exception : public std::exception {
public:
    explicit Exception(const char *what) : message_(what) {
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

    virtual ~Exception() throw() {}

    virtual const char *what() const throw() { return message_.c_str(); }

    const char *StackTrace() const throw() { return stack_.c_str(); }

protected:
    std::string message_;
    std::string stack_;
};

} // namespace lt

#endif   // ----- #ifndef EXCEPTION_INC  -----
