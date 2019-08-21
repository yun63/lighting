/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: adapter.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/19 20时39分33秒
 *
 **/

#ifndef  ADAPTER_INC
#define  ADAPTER_INC

#include <iostream>

class Hindu {
public:
    virtual ~Hindu() = default;
    virtual void PerformsHinduRitual() const = 0;
};


class HinduFemale : public Hindu {
public:
    virtual void PerformsHinduRitual() const override {
        std::cout << "Hindu girl performs Hindu ritual." << std::endl;
    }
};


class Muslim {
public:
    virtual ~Muslim() = default;
    virtual void PerformsMuslimRitual() const = 0;
};


class MuslimFemale : public Muslim {
public:
    virtual void PerformsMuslimRitual() const override {
        std::cout << "Muslim girl performs Muslim ritual." << std::endl;
    }
};


class HinduRitual {
public:
    void CarryOutRitual(Hindu *hindu) {
        std::cout << "On with the Hindu rituals!" << std::endl;
        hindu->PerformsHinduRitual();
    }
};


class HinduAdapter : public Hindu {
public:
    HinduAdapter(Muslim *m) : muslim_(m) {}
    virtual void PerformsHinduRitual() const override {
        muslim_->PerformsMuslimRitual();
    }

private:
    Muslim *muslim_;
};

#endif   // ----- #ifndef ADAPTER_INC  -----

