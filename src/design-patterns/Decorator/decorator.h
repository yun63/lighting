/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: decorator.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/20 11时42分57秒
 *
 **/


#ifndef  DECORATOR_INC
#define  DECORATOR_INC

#include <iostream>
#include <string>
#include <memory>

class Interface {
public:
    virtual ~Interface() {}
    virtual void write(std::string &) = 0;
};


class Core : public Interface {
public:
    virtual ~Core() { std::cout << "Core destructor called.\n"; }
    virtual void write(std::string &text) override {}
};


class Decorator : public Interface {
public:
    Decorator(std::unique_ptr<Interface> c) {
        interface_ = std::move(c);
    }

    virtual void write(std::string &text) override {
        this->interface_->write(text);
    }

private:
    std::unique_ptr<Interface> interface_;
};


class MessengerWithSalutation : public Decorator {
public:
    MessengerWithSalutation(std::unique_ptr<Interface> c, const std::string &text)
        : Decorator(std::move(c)), salutation_(text) {}

    virtual ~MessengerWithSalutation() {
        std::cout << "MessengerWithSalutation destructor called.\n";
    }

    virtual void write(std::string &text) override {
        text = salutation_ + "\n\n" + text;
        Decorator::write(text);
    }

private:
    std::string salutation_;
};


class MessengerWithValediction : public Decorator {
public:
    MessengerWithValediction(std::unique_ptr<Interface> c, const std::string &text)
        : Decorator(std::move(c)), valediction_(text) {}

    virtual ~MessengerWithValediction() {
        std::cout << "MessengerWithValediction destructor called.\n";
    }

    virtual void write(std::string &text) override {
        Decorator::write(text);
        text += "\n\n" + valediction_;
    }

private:
    std::string valediction_;
};

#endif   // ----- #ifndef DECORATOR_INC  -----
