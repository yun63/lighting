/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: facade.cpp
 *
 * @breaf: 外观模式
 *
 * 需求：设计一个傻瓜照相机，只要选好拍照模式（白天或者夜间模式）即可自动完成各种参数设定
 * 
 * 1. 针对问题：某个系统过于复杂，使用者需要详细了解内部细节才懂得使用
 * 2. 解决方法：
 *
 *    –––––––       –––––––       ––––––– 
 *   |client1|     |client2|     |client3|
 *    –––––––       –––––––       ––––––– 
 *      \              |             /
 *        \            |           /
 *          \          |         /
 *            \        |       /
 *              \      |     /
 *            |––––––––––––––––|
 *            |    Facade类    |
 *            |––––––––––––––––|
 *
 * 3. 优点: 降低用户使用系统的难度
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/01/25 19时35分24秒
 *
 **/

#include <iostream>

class FlashLight {
public:
    FlashLight(bool is_open_in=false) {
        is_opened_ = is_open_in;
    }

    void open() {
        this->is_opened_ = true;
    }

    void close() {
        this->is_opened_ = false;
    }

private:
    /* data */
    bool is_opened_;
};

class Shutter {
public:
    virtual void action() {
        std::cout << "action!" << std::endl;
    }
};


class Focus {
public:
    void set_focus_value(int value) {
        focus_value_ = value;
    }

private:
    int focus_value_;
};


class Aperture {
public:
    Aperture(int value=0) {
        this->aperture_value_ = value;
    }

    void set_aperture_value(int value) {
        aperture_value_ = value;
    }

private:
    int aperture_value_;
};


/*
 * Facade
 */
class Camero {
public:
    Camero() :
        flash_light_(new FlashLight())
        , shutter_(new Shutter())
        , focus_(new Focus())
        , aperture_(new Aperture()) {
            std::cout << "create a camero successfully!" << std::endl;
        }

    void set_day_mode() {
        this->flash_light_->close();
        focus_->set_focus_value(50);
        aperture_->set_aperture_value(10);
        std::cout << "set to day mode!\n";
    }

    void set_night_mode() {
        flash_light_->open();
        focus_->set_focus_value(80);
        aperture_->set_aperture_value(90);
        std::cout << "set to night mode!\n";
    }

    void action() {
        this->shutter_->action();
    }

private:
    FlashLight  *flash_light_;
    Shutter     *shutter_;
    Focus       *focus_;
    Aperture    *aperture_;
};

int main(int argc, char *argv[])
{
    Camero *c = new Camero();
    c->set_day_mode();
    c->action();
    c->set_night_mode();
    c->action();
    return 0;
}
