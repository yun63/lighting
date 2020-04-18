/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_sort.h
 *
 * @breaf: 各类排序算法
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/08/23 18时48分09秒
 *
 **/


#ifndef  LT_SORT_INC
#define  LT_SORT_INC

#include <vector>
#include <algorithm>
#include <functional>

#include "noncopyable.h"

using namespace std;

namespace lt {


template <typename T>
struct Swap {
    void operator()(T &a, T &b) {
        std::swap(a, b);
    }
};

class SortWrapper {
public:
    /**
     * @brief 直接插入排序(升序排序)
     *
     * @param arraylist  待排数据列
     */
    template<typename T,
             typename Sequence = std::vector<T>>
    static void
    InsertSort(Sequence &arraylist) {
        SortWrapper::InsertSort<T>(arraylist, std::less<T>());
    }
    /**
     * @brief 直接插入排序
     *
     * @param arraylist 待排数据列
     * @param comp: 仿函数，用于待排元素的比较
     */
    template<typename T,
             typename Sequence = std::vector<T>,
             typename CompPred>
    static void
    InsertSort(Sequence &arraylist, CompPred comp) {
        for (size_t i = 1; i < arraylist.size(); ++i) {
            T key = arraylist[i];
            int j = i - 1;
            for (; j >= 0 && comp(key, arraylist[j]); j--) {
                arraylist[j+1] = arraylist[j];
            }
            arraylist[j+1] = key;
        }
    }
    /**
     * @brief 选择排序
     *
     * @param arraylist 待排数据列
     * @param comp 仿函数，用于比较两个待排元素的大小
     */
    template <typename T,
              typename Sequence = std::vector<T>,
              typename CompPred>
    static void
    SelectSort(Sequence &arraylist, CompPred comp) {
        for (size_t i = 0; i < arraylist.size(); ++i) {
            size_t k = i;
            for (size_t j = i + 1; j < arraylist.size(); ++j) {
                if (comp(arraylist[j], arraylist[k]) == true) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(arraylist[i], arraylist[k]);
            }
        }
    }
    /**
     * @brief 归并排序
     *
     * @param arraylist 待排数据列
     * @param comp 仿函数，用于比较两个待排元素的大小
     */
    template<typename T,
             typename Sequence = std::vector<int>,
             typename CompPred>
    static void
    MergeSort(Sequence &arraylist, CompPred comp) {
    }
    /**
     * @brief 希尔排序
     *
     * @param arraylist 待排数据列
     * @param comp 仿函数，用于比较两个待排元素的大小
     */
    template<typename T,
             typename Sequence = std::vector<T>,
             typename CompPred>
    static void
    ShellSort(vector<T> &arraylist, CompPred comp) {
    }
    /**
     * @brief  划分序列为两部分,返回轴枢位置,该位置前半部分均小于轴枢，后半部分均大于轴枢
     *
     * @param arraylist 序列
     * @param begin 序列的起始位置
     * @param end 序列的结束位置
     *
     * @return 轴枢位置
     *
     * Ref: std::partition(first, last, pred)
     */
    template<typename T, typename Sequence = std::vector<T> >
    static int 
    Partition(Sequence &arraylist, int begin, int end) {
        T pivot = arraylist[begin];
        while (begin <= end) {
            while (begin <= end && arraylist[end] > pivot) {
                --end;
            }
            arraylist[begin] = arraylist[end];
            while (begin < end && arraylist[begin] <= pivot) {
                ++begin;
            }
            arraylist[end] = arraylist[begin];
        }
        arraylist[begin] = pivot;
        return begin;
    }
    /**
     * @brief  快速排序
     *
     * @param arraylist 待排数据列
     * @param comp 仿函数，用于比较两个待排元素的大小
     */
    template<typename T,
             typename Sequence = std::vector<T>,
             typename CompPred>
    static void
    QuickSort(Sequence &arraylist, CompPred comp) {
    }

};


} // namespace lt

#endif   // ----- #ifndef LT_SORT_INC  -----
