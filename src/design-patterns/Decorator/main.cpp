/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: main.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/20 21时30分22秒
 *
 **/

#include "decorator.h"
#include <string>


int main(int argc, char *argv[])
{
    const std::string salutation = "Greetings,";
    const std::string valediction = "Sincerly, Andy";
    std::string message1 = "This message is not decorated.";
    std::string message2 = "This message is decorated with a saluatation.";
    std::string message3 = "This message is decorated with a valediction.";
    std::string message4 = "This message is decorated with a salutation and a valediction.";

    std::unique_ptr<Interface> messenger1 = std::make_unique<Core>();
    std::unique_ptr<Interface> messenger2 = std::make_unique<MessengerWithSalutation>(std::make_unique<Core>(), salutation);
    std::unique_ptr<Interface> messenger3 = std::make_unique<MessengerWithValediction>(std::make_unique<Core>(), valediction);
    std::unique_ptr<Interface> messenger4 = std::make_unique<MessengerWithValediction>(std::make_unique<MessengerWithSalutation>(std::make_unique<Core>(), salutation), valediction);

    messenger1->write(message1);
    std::cout << message1 << std::endl;
    std::cout << "\n-------------------------------\n\n";

    messenger2->write(message2);
    std::cout << message2 << std::endl;
    std::cout << "\n-------------------------------\n\n";

    messenger3->write(message3);
    std::cout << message3 << std::endl;
    std::cout << "\n-------------------------------\n\n";

    messenger4->write(message4);
    std::cout << message4 << std::endl;
    std::cout << "\n-------------------------------\n\n";

    return 0;
}

