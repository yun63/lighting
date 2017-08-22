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

#include "basic_types.h"
#include "noncopyable.h"


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
    uint32_t *sets_;
    uint32_t *rank_;
    uint32_t size_;
};


} // namespace lt

#endif   // ----- #ifndef LT_ALGO_INC  -----
