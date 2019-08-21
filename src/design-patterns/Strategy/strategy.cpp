/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: strategy.cpp
 *
 * @breaf: 策略模式
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/01/25 20时08分46秒
 *
 **/


#include <iostream>

class Tax {
public:
    virtual void CalcTax() = 0;
};


class USTax : public Tax {
public:
    virtual void CalcTax() {
        std::cout << "Calculate tax in US!\n";
    }
};


class CanTax : public Tax {
public:
    virtual void CalcTax() {
        std::cout << "Calculate tax in Canada\n";
    }
};


class PayMethod {
public:
    virtual void Pay() = 0;
};


class WeXinPay : public PayMethod {
public:
    virtual void Pay() {
        std::cout << "Pay money by WeXinPay\n";
    }
};

class AliPay : public PayMethod {
public:
    virtual void Pay() {
        std::cout << "Pay money by AliPay\n";
    }
};


class SalesOrder {
public:
    SalesOrder(Tax *calc_tax, PayMethod *pay_way) : tax_(calc_tax), pay_(pay_way) {}

    void CalcTax() {
        tax_->CalcTax();
    }

    void Pay() {
        pay_->Pay();
    }

private:
    Tax         *tax_;
    PayMethod   *pay_;
};


int main(int argc, char *argv[])
{
    SalesOrder *order = new SalesOrder(new USTax(), new AliPay());
    order->CalcTax();
    order->Pay();

    return 0;
}
