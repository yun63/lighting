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

    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushFront(100);
    lst.Print();

    lst.Reverse();
    lst.Print();


    lst.Clear();
    assert(lst.size() == 0);
    lst.PushFront(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PopFront();
    lst.PopBack();
    assert(lst.size() == 1);

    lt::List<std::shared_ptr<Resource>> res_pool;
    std::shared_ptr<Resource> sa(new Resource());
    res_pool.PushBack(sa);
    lt::LinkNode<std::shared_ptr<Resource>> *sr = res_pool.Get(1);
    printf("%p\n", sr->data.get());
    assert(res_pool.size() == 1);

    lt::DList<int> dlist;
    printf("%zu\n", dlist.size());
    dlist.Append(2);
    dlist.Append(3);
    printf("%zu\n", dlist.size());
    dlist.PushFront(100);
    assert(dlist.size() == 3);
    assert(dlist.front() == 100);
    assert(dlist.back() == 3);
    dlist.Clear();
    assert(dlist.head() == dlist.tail());
    assert(dlist.empty());
    return 0;
}
