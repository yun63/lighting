/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: list.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/03/20 21时42分21秒
 *
 **/


#include <stdio.h>
#include <cassert>
#include <memory>

#include <base/lt_list.h>

class Resource : public noncopyable
{
public:
    Resource () { printf("Resource constructor called!\n"); }
    virtual ~Resource () { printf("Resource destructor called\n"); }

private:
    /* data */
};


int main(int argc, char *argv[])
{
    lt::List<int> lst;
    /*
    assert(lst.size() == 0);
    assert(lst.empty() == true);
    lst.push_back(1);
    assert(lst.size() == 1);
    assert(lst.empty() == false);

    lst.push_back(11);
    assert(lst.size() == 2);

    assert(lst.get(0)->data == 0);
    assert(lst.get(1)->data == 1);
    assert(lst.get(2)->data == 11);

    int d = lst.pop_front();
    assert(d == 1);
    assert(lst.size() == 1);

    assert(lst.get(1)->data == 11);
    lst.clear();
    assert(lst.size() == 0);
    */

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(100);
    lst.Print();

    lst.reverse();
    lst.Print();


    lst.clear();
    assert(lst.size() == 0);
    lst.push_front(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.pop_front();
    lst.pop_back();
    assert(lst.size() == 1);

    lt::List<std::shared_ptr<Resource>> res_pool;
    std::shared_ptr<Resource> sa(new Resource());
    res_pool.push_back(sa);
//  typedef typename std::shared_ptr<Resource> * SmartResType;
    lt::LinkNode<std::shared_ptr<Resource>> *sr = res_pool.get(1);
    printf("%p\n", sr->data.get());
    assert(res_pool.size() == 1);

    lt::CircularList<int> clist;
    printf("%d\n", clist.size());
    return 0;
}
