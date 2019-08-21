/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: example.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/21 11时31分16秒
 *
 **/

#ifndef  EXAMPLE_INC
#define  EXAMPLE_INC

#include <iostream>
#include <memory>

class Transform {
public:
    virtual void Move() = 0;
};


class Car : public Transform {
public:
    Car(int number) : number_(number) {}
    virtual ~Car() {}

    virtual void Move() override {
        std::cout << "Car move\n";
    }

private:
    int number_;
};


class ChangerDecorator : public Transform {
public:
    ChangerDecorator(std::unique_ptr<Transform> t) : transform_interface_(std::move(t)) {}
    virtual ~ChangerDecorator() {}

    virtual void Move() override {
        transform_interface_->Move();
    }

private:
    std::unique_ptr<Transform> transform_interface_;
};


class Airplane : public ChangerDecorator {
public:
    Airplane(std::unique_ptr<Transform> t) : ChangerDecorator(t) {}
    virtual ~Airplane() {}

    virtual void Move() override {
        ChangerDecorator::Move();
    }
};

#endif   // ----- #ifndef EXAMPLE_INC  -----

