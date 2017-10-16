/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_algo.h
 *
 * @breaf: 算法
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/08/22 16时43分44秒
 *
 **/


#ifndef  LT_ALGO_INC
#define  LT_ALGO_INC

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

#include "lt_list.h"
#include "basic_types.h"


namespace lt {


/// 并查集
class UnionFind : public noncopyable {
public:
    UnionFind(uint32_t size)
        : size_(size)
        , sets_(new uint32_t[size + 1])
        , rank_(new uint32_t[size + 1]) {
        for (uint32_t i = 0; i <= size; i++) {
            sets_[i] = i;
            rank_[i] = 0;
        }
    }

    virtual ~UnionFind() {
        delete []sets_;
        delete []rank_;
    }

    uint32_t find(uint32_t s) {
        assert(s >= 0);
        std::vector<uint32_t> path;
        while (s != this->sets_[s]) {
            path.push_back(s);
            s = this->sets_[s];
        }

        // 路径压缩
        for (uint32_t i = 0; i < path.size(); i++) {
            this->sets_[path[i]] = s;
        }

        return s;
    }

    bool merge(uint32_t s1, uint32_t s2) {
        assert(s1 >= 0);
        assert(s2 >= 0);

        uint32_t r1 = this->find(s1);
        uint32_t r2 = this->find(s2);

        if (r1 == r2) {
            return false;
        }
        // 根据rank合并
        if (this->rank_[r1] > this->rank_[r2]) {
            this->sets_[r2] = r1;
        } else if (this->rank_[r1] < this->rank_[r2]) {
            this->sets_[r1] = r2;
        } else {
            this->sets_[r2] = r1;
            this->rank_[r1] += 1;
        }

        return true;
    }

    bool connected(uint32_t s1, uint32_t s2) {
        return find(s1) == find(s2);
    }

    void output() {
        for (uint32_t i = 1; i <= this->size_; i++) {
            std::cout << this->find(i) << '\t';
        }
        std::cout << std::endl;
    }

private:
    uint32_t size_;
    uint32_t *sets_;
    uint32_t *rank_;
};


/**
 * @brief 合并两个已排好序列的链表到第三个链表
 *
 * @param l1 已排序链表
 * @param l2 已排序链表
 * @param l 待合并链表
 *
 * @return 合并好的链表
 */
template<class T>
List<T> *MergeLinkList(const List<T> *l1, const List<T> *l2, List<T> *l) {
    uint32_t i = 1;
    uint32_t j = 1;
    LinkNode<T> *p, *q;
    while (i <= l1->size() && j <= l2->size()) {
        p = l1->get(i);
        q = l2->get(j);
        if (p->data <= q->data) {
            l->push_back(p->data);
            ++i;
        } else {
            l->push_back(q->data);
            ++j;
        }
    }
    
    while (i <= l1->size()) {
        p = l1->get(i);
        l->push_back(p->data);
        ++i;
    }
    while (j <= l2->size()) {
        q = l2->get(j);
        l->push_back(q->data);
        ++j;
    }

    return l;
}

/**
 * @brief 计算KMP算法nextval数组
 *
 * @param p 模式匹配串
 * @param next[]
 *
 * http://v.atob.site/kmp-next.html
 */
void compute_nextval(const char *p, int next[]) {
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < strlen(p) - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

/**
 * @brief KMP模式匹配算法
 *
 * @param s 目标串
 * @param p 模式子串
 *
 * @return 模式子串在目标串s中的配置位置 -1表示p不是s的子串
 *
 * http://blog.csdn.net/v_july_v/article/details/7041827
 *
 */
int KMP_search(const char *s, const char *p) {
    int i = 0;
    int j = 0;
    int n = strlen(s);
    int m = strlen(p);
    int next[m];
    compute_nextval(p, next);
    while (i < n && j < m) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == m) {
        return i - j;
    }
    return -1;
}


} // namespace lt

#endif   // ----- #ifndef LT_ALGO_INC  -----
