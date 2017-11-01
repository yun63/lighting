/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: sort.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/08/24 11时41分56秒
 *
 **/

#include "base/lt_sort.h"

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <functional>

using namespace std;

template<class T>
struct AscendingSort {
    bool operator()(const T &a, const T &b) {
        return a < b;
    }
};


template<class T>
struct DescendingSort {
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};

bool less(int a, int b) {
    return a < b;
}

bool greater(int a, int b) {
    return a > b;
}

int main(int argc, char *argv[])
{
    std::deque<int> dq = {3, 2, 9, 7, 6, 5, 8, 1};
    std::list<int> lst;
    lt::SortWrapper::SelectSort<int, std::deque<int>>(dq, DescendingSort<int>());
    for (auto i : dq) {
        std::cout << i << '\t';
    }
    std::cout << endl;
    vector<int> v = {5, 9, 4, 7, 6, 2, 3, 8};
    int pivot = lt::SortWrapper::Partition<int>(v, 0, v.size() - 1);
    std::cout << pivot << std::endl;
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << endl;
    pivot = v.at(0);
    std::vector<int>::iterator it = std::partition(v.begin(), v.end(), [pivot](int x) {
            return x <= pivot;
            });

    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << endl;

    std::cout << *it << std::endl;

    return 0;
}


