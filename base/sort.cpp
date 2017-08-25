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

#include "lt_sort.h"

#include <iostream>
#include <vector>
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
//    vector<int> v = {3, 2, 9, 7, 6, 5, 8, 1};
    int array[] = {3, 2, 9, 7, 6, 5};
    vector<int> v(array, array + 6);
    lt::SortWrapper::SelectSort<int>(v, DescendingSort<int>());
    for (auto i : v) {
        std::cout << i << '\t';
    }
    cout << endl;
//    lt::SortWrapper::InsertSort<int>(v);
//    for (auto i : v) {
//        std::cout << i << '\t';
//    }
//    cout << endl;

    return 0;
}


