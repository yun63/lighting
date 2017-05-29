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

#include <exception>
#include <string>

namespace lt {

class Exception : public std::exception {
public:
    explicit Exception(const char *what);
    virtual ~Exception() throw();
    virtual const char *what() const throw();
    const char *StackTrace() const throw();

protected:
    std::string message_;
    std::string stack_;
};

} // namespace lt

#endif   // ----- #ifndef EXCEPTION_INC  -----
