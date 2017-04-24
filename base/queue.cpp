/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: queue.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/03 21时18分20秒
 *
 **/


#include "lt_list.h"
#include "lt_queue.h"

#include <stdio.h>
#include <cassert>

int main(int argc, char *argv[])
{
    lt::Queue<int> que;
    assert(que.empty() == true);
    assert(que.size() == 0);
    // push
    que.push(100);
    assert(que.empty() == false);
    assert(que.size() == 1);
    // front && back
    assert(que.front() == 100);
    assert(que.back() == 100);
    // pop
    int e = que.pop();
    assert(e == 100);
    assert(que.empty() == true);
    assert(que.size() == 0);

    que.push(100);
    que.push(200);
    que.push(300);
    que.push(400);
    assert(que.front() == 100);
    assert(que.back() == 400);
    assert(que.size() == 4);
    assert(que.pop() == 100);
    assert(que.front() == 200);
    assert(que.size() == 3);
    // clear
    que.clear();
    assert(que.empty() == true);
    assert(que.size() == 0);
    try {
        que.front();
    } catch (lt::Exception &e) {
        printf("%s\n", e.what());
    }

    try {
        que.pop();
    } catch (lt::Exception &e) {
        printf("%s\n", e.what());
    }

    return 0;
}
