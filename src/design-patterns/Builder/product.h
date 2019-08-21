/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: product.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/06 14时42分51秒
 *
 **/


#ifndef  PRODUCT_INC
#define  PRODUCT_INC

#include <stdio.h>
#include <string>
#include <memory>

class Pizza {
public:
    void set_dough(const std::string &dough) {
        this->dough_ = dough;
    }

    void set_sauce(const std::string &sauce) {
        this->sauce_ = sauce;
    }

    void set_topping(const std::string &topping) {
        this->topping_ = topping;
    }

    void open() const {
        printf("Pizza with %s dought, %s sauce and %s topping. Mmm.\n",
                dough_.c_str(),
                sauce_.c_str(),
                topping_.c_str()
              );
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

#endif   // ----- #ifndef PRODUCT_INC  -----
