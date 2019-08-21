/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: draw.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/19 21时03分52秒
 *
 **/


#ifndef  DRAW_INC
#define  DRAW_INC

#include <iostream>

using namespace std;

class DrawingAPI {
public:
    virtual ~DrawingAPI() {}
    virtual void DrawCircle(double x, double  y, double radius) = 0;
};


class DrawingAAPI : public DrawingAPI {
public:
    void DrawCircle(double x, double y, double radius) {
        cout << "AAPI.circle at " << x << ':' << y << ' ' << radius << endl;
    }
};


class DrawingBAPI : public DrawingAPI {
public:
    void DrawCircle(double x, double y, double radius) {
        cout << "BAPI.circle at " << x << ':' << y << ' ' << radius << endl;
    }
};


class Shape {
public:
    virtual ~Shape() {}
    virtual void Draw() = 0;
    virtual void ResizeByPercentage(double pct) = 0;
};


class CircleShape : public Shape {
public:
    CircleShape(double x, double y, double radius, DrawingAPI *API)
        : x_(x), y_(y), radius_(radius), drawing_api_(API) {}

    void Draw() {
        drawing_api_->DrawCircle(x_, y_, radius_);
    }

    void ResizeByPercentage(double pct) {
        radius_ *= pct;
    }

private:
    double x_;
    double y_;
    double radius_;
    DrawingAPI *drawing_api_;
};

#endif   // ----- #ifndef DRAW_INC  -----
