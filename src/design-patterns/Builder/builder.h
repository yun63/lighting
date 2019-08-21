/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: builder.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/06 14时46分53秒
 *
 **/


#ifndef  BUILDER_INC
#define  BUILDER_INC

#include "product.h"

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}

    Pizza *GetPizza() {
        return pizza_.release();
    }

    void CreateNewPizzaProduct() {
        pizza_ = std::make_unique<Pizza>();
    }

    virtual void BuildDough() = 0;
    virtual void BuildSauce() = 0;
    virtual void BuildTopping() = 0;

protected:
    std::unique_ptr<Pizza> pizza_;
};


class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    virtual ~HawaiianPizzaBuilder() {}

    virtual void BuildDough() {
        pizza_->set_dough("cross");
    }

    virtual void BuildSauce() {
        pizza_->set_sauce("mild");
    }

    virtual void BuildTopping() {
        pizza_->set_topping("ham+pineapple");
    }
};


class SpicyPizzaBuilder : public PizzaBuilder {
public:
    virtual ~SpicyPizzaBuilder() {}

    virtual void BuildDough() {
        pizza_->set_dough("pan baked");
    }

    virtual void BuildSauce() {
        pizza_->set_sauce("hot");
    }

    virtual void BuildTopping() {
        pizza_->set_topping("pepperoni+salami");
    }
};


class Cook {
public:
    void OpenPizza() {
        pizza_builder_->GetPizza()->open();
    }

    void MakePizza(PizzaBuilder *pb) {
        pizza_builder_ = pb;
        pizza_builder_->CreateNewPizzaProduct();
        pizza_builder_->BuildDough();
        pizza_builder_->BuildSauce();
        pizza_builder_->BuildTopping();
    }

private:
    PizzaBuilder *pizza_builder_;
};

#endif   // ----- #ifndef BUILDER_INC  -----
