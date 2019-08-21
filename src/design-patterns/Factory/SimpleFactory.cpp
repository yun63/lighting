/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: SimpleFactory.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/07 10时20分28秒
 *
 **/

#ifndef  SIMPLEFACTORY_INC
#define  SIMPLEFACTORY_INC

#include <stdio.h>
#include <memory>
#include <map>
#include <string>

class Computer {
public:
    virtual ~Computer() { printf("~Computer\n"); }

    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class Laptop : public Computer {
public:
    void Run() override {
        hibernating_ = false;
        printf("Laptop computer running...\n");
    }
    void Stop() override {
        hibernating_ = true;
        printf("Laptop computer stopping...\n");
    }

    virtual ~Laptop() { printf("~Laptop\n"); }

private:
    bool hibernating_;
};


class Desktop : public Computer {
public:
    virtual ~Desktop() { printf("~Desktop\n"); }

    void Run() override {
        on_ = true;
        printf("Desktop computer running...\n");
    }
    void Stop() override {
        on_ = false;
        printf("Desktop computer stopping...\n");
    }

private:
    bool on_;
};


class ComputerSimpleFactory {
public:
    enum ComputerType {
        LAPTOP = 1,
        DESKTOP = 2,
        WORKSTATION = 3
    };

    typedef std::map<std::string, ComputerType> ComputerMapType;
    static const ComputerMapType kMappings;

    static Computer *CreateComputer(const std::string &description) {
        switch (kMappings.at(description)) {
            case LAPTOP:
                return new Laptop();
            case DESKTOP:
                return new Desktop();
            default:
                return NULL;
        }
    }
};


const ComputerSimpleFactory::ComputerMapType ComputerSimpleFactory::kMappings {
    {"laptop", ComputerSimpleFactory::LAPTOP},
    {"desktop", ComputerSimpleFactory::DESKTOP},
    {"workstation", ComputerSimpleFactory::WORKSTATION}
};

int main(int argc, char *argv[])
{
//    std::shared_ptr<Computer> c(ComputerSimpleFactory::CreateComputer("laptop"));
    Computer *c = ComputerSimpleFactory::CreateComputer("laptop");
    if (c) {
        c->Run();
    }
    delete c;
    return 0;
}


#endif   // ----- #ifndef SIMPLEFACTORY_INC  -----
