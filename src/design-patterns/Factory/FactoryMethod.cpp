/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: FactoryMethod.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/21 10时58分13秒
 *
 **/

#include <iostream>
#include <memory>
#include <string>


class Computer {
public:
    virtual ~Computer() {}

    virtual void display() = 0;

public:
    std::string uuid_;
};


class ComputerFactory {
public:
    virtual ~ComputerFactory() {}
    virtual std::shared_ptr<Computer> CreateComputer() = 0;
};


class Laptop : public Computer {
public:
    virtual void display() override {
        std::cout << "Laptop computer display()\n";
    }
};


class Desktop : public Computer {
public:
    virtual void display() override {
        std::cout << "Desktop computer display()\n";
    }
};


class LaptopFactory : public ComputerFactory {
public:
    std::shared_ptr<Computer> CreateComputer() override {
        return std::make_shared<Laptop>();
    }
};


class DesktopFactory : public ComputerFactory {
public:
    std::shared_ptr<Computer> CreateComputer() override {
        return std::make_shared<Desktop>();
    }
};


int main(int argc, char *argv[])
{
    std::shared_ptr<ComputerFactory> c = std::make_shared<LaptopFactory>();
    std::shared_ptr<Computer> pc = c->CreateComputer();

    pc->display();

    return 0;
}
