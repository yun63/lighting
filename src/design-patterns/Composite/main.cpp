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
 * @create: 2018/03/21 15时56分40秒
 *
 **/

#include "graphic.h"

int main(int argc, char *argv[])
{
    const std::shared_ptr<Ellipse> e1(new Ellipse());
    const std::shared_ptr<Ellipse> e2(new Ellipse());
    const std::shared_ptr<Ellipse> e3(new Ellipse());
    const std::shared_ptr<Ellipse> e4(new Ellipse());

    const shared_ptr<CompositeGraphic> g0(new CompositeGraphic());
    const shared_ptr<CompositeGraphic> g1(new CompositeGraphic());
    const shared_ptr<CompositeGraphic> g2(new CompositeGraphic());
    const shared_ptr<CompositeGraphic> g3(new CompositeGraphic());

    g1->add(e1);
    g1->add(e2);
    g1->add(e3);

    g2->add(e4);

    g0->add(g1);
    g0->add(g2);

    g0->print();

    return 0;
}

