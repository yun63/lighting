/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_random.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/30 17时57分04秒
 *
 **/


#ifndef  LT_RANDOM_INC
#define  LT_RANDOM_INC

#include "basic_types.h"
#include "noncopyable.h"

namespace lt {

class Random : public noncopyable {
public:
    explicit Random(uint32_t upper = kint32max) {
        upper_limit_ = upper;
    }

    /**
     * @brief 生成随机数
     *
     * @return 
     */
    uint32_t Generate() const;

    /**
     * @brief 设置随机数种子
     *
     * @param seed
     */
    static void set_seed(uint32_t seed) {
        seed_ = seed;
    }

    void set_upper_limit(uint32_t max) {
        upper_limit_ = max;
    }

private:
    /* data */
    static uint32_t seed_;
    static const uint32_t A = 48271;
    static const uint32_t M = 2147483647;
    static uint32_t upper_limit_;
};

const uint32_t Random::A;
const uint32_t Random::M;

uint32_t Random::seed_ = 1;
uint32_t Random::upper_limit_ = Random::M;

uint32_t Random::Generate() const {
    int Q = static_cast<int>(M / A);
    int R = static_cast<int>(M % A);
    int T = static_cast<int>(A * (Random::seed_ % Q) - R * (Random::seed_ / Q));
    if (T >= 0) {
        Random::seed_ = static_cast<uint32_t>(T);
    } else {
        Random::seed_ = static_cast<uint32_t>(T + M);
    }

    return Random::seed_ % Random::upper_limit_;
}


} // namespace lt

#endif   // ----- #ifndef LT_RANDOM_INC  -----
