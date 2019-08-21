/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: graphic.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/21 15时31分07秒
 *
 **/

#ifndef  GRAPHIC_INC
#define  GRAPHIC_INC

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Graphic {
public:
    virtual ~Graphic() {}
    virtual void print() const = 0;
};


class Ellipse : public Graphic {
public:
    void print() const {
        cout << "Ellipse \n";
    }
};


class CompositeGraphic : public Graphic {
public:
    void add(std::shared_ptr<Graphic> g) {
        shared_graphics_.push_back(g);
    }

    void print() const {
        for (auto g : shared_graphics_) {
            g->print();
        }
    }

private:
    vector<std::shared_ptr<Graphic>> shared_graphics_;
};

#endif   // ----- #ifndef GRAPHIC_INC  -----
