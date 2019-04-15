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

#include "lt_types.h"
#include "noncopyable.h"

#include <vector>

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


/**
 * Return a float random inside the internal [0, mod]
 */
inline float frand(float mod) {
    double r = static_cast<double>(rand());
    r /= static_cast<double>(RAND_MAX);
    return static_cast<float>(r * mod);
}

/**
 * Return a random between [0, 10000)
 *
 */
uint32_t rand() {
    Random rand(10000);
    return rand.Generate();
}

/**
 * @brief Return a random between [0, limit)
 *
 * @param limit
 *
 * @return  random number
 */
uint32_t rand(uint32_t limit) {
    if (limit == 0) {
        return 0;
    }

    Random rand(limit);
    return rand.Generate();
}

/**
 * @brief Return a number between[a, b) if a < b or between [b, a) if a > b
 *
 * @param a
 * @param b
 *
 * @return random number between a and b
 */
uint32_t rand(uint32_t a, uint32_t b) {
    if (a == b) {
        return a;
    }

    Random rand(::abs(a - b));
    return std::min(a, b) + rand.Generate();
}

/**
 * @brief Set random seed
 *
 * @param seed
 */
void srand(uint32_t seed) {
    Random rand;
    rand.set_seed(seed);
}

int weighted_random(std::vector<std::pair<int, int>> pool) {
    int sum = 0;
    for (size_t i = 0; i < pool.size(); i++) {
        sum += pool[i].second;
    }

    int rbase = base::rand(sum);
    int cur = 0;

    for (auto it = pool.begin(); it != pool.end(); it++) {
        if (rbase > cur && rbase <= cur + it->second) {
            return it->first;
        }
        cur += it->second;
    }

    return 0;
}


} // namespace lt

#endif   // ----- #ifndef LT_RANDOM_INC  -----
