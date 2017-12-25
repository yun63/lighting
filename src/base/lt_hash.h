/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_hash.h
 *
 * @breaf: 哈希
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016-10-21 17:12
 *
 **/
 
#ifndef  HASH_INC
#define  HASH_INC

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#include <limits>
#include <string>
#include <utility>

extern "C" {
    uint32_t SuperFastHash(const char *data, int len);
}

namespace base {

// WARNING: 不能用于加密目的
//
uint32_t SuperFastHash(const char *data, size_t length) {
    if (length > static_cast<size_t>(std::numeric_limits<int>::max())) {
        return 0;
    }
    return ::SuperFastHash(data, static_cast<int>(length));
}

// 计算给定长度的内存buffer的hash值
inline uint32_t Hash(const char *data, size_t length) {
    return SuperFastHash(data, length);
}

// 计算std::string 字符串的hash值
inline uint32_t Hash(const std::string &str) {
    return Hash(str.data(), str.size());
}

// 参考：Theorem 4.3.3 of the thesis "Über die Komplexität der Multiplikation in
// "eingeschränkten Branchingprogrammmodellen" by Woelfel, is:"
// h32(x32, y32) = (h64(x32, y32) * rand_odd64 + rand16 * 2^16) % 2^64 / 2^32
inline size_t HashInts32(uint32_t value1, u_int32_t value2) {
    uint64_t value1_64 = value1;
    uint64_t hash64 = (value1_64 << 32) | value2;

    if (sizeof(size_t) >= sizeof(uint64_t)) {
        return static_cast<size_t>(hash64);
    }

    uint64_t odd_random = 481046412LL << 32 | 1025306955LL;
    uint32_t shift_random = 10121U << 16;

    hash64 = hash64 * odd_random + shift_random;
    size_t high_bits = static_cast<size_t>(hash64 >> (8 * (sizeof(uint64_t) - sizeof(size_t))));

    return high_bits;
}

inline size_t HashInts64(uint64_t value1, uint64_t value2) {
    uint32_t short_random1 = 842304669U;
    uint32_t short_random2 = 619063811U;
    uint32_t short_random3 = 937041849U;
    uint32_t short_random4 = 3309708029U;

    uint32_t value1a = static_cast<uint32_t>(value1 & 0xffffffff);
    uint32_t value1b = static_cast<uint32_t>((value1 >> 32) & 0xffffffff);
    uint32_t value2a = static_cast<uint32_t>(value2 & 0xffffffff);
    uint32_t value2b = static_cast<uint32_t>((value2 >> 32) & 0xffffffff);

    uint64_t product1 = static_cast<uint64_t>(value1a) * short_random1;
    uint64_t product2 = static_cast<uint64_t>(value1b) * short_random2;
    uint64_t product3 = static_cast<uint64_t>(value2a) * short_random3;
    uint64_t product4 = static_cast<uint64_t>(value2b) * short_random4;

    uint64_t hash64 = product1 + product2 + product3 + product4;

    if (sizeof(size_t) >= sizeof(uint64_t)) {
        return static_cast<size_t>(hash64);
    }

    uint64_t odd_random = 1578233944LL << 32 | 194370989LL;
    uint32_t shift_random = 20591U << 16;

    hash64 = hash64 * odd_random + shift_random;
    size_t high_bits = static_cast<size_t>(hash64 >> (8 * (sizeof(uint64_t) - sizeof(size_t))));

    return high_bits;
}

template <typename T1, typename T2>
inline size_t HashInts(T1 value1, T2 value2) {
    if (sizeof(T1) > sizeof(uint32_t) || sizeof(T2) > sizeof(uint32_t)) {
        return HashInts64(value1, value2);
    }

    return HashInts32(value1, value2);
}

template <typename T>
struct IntParisHash;

template <typename Type1, typename Type2>
struct IntParisHash<std::pair<Type1, Type2>> {
    size_t operator()(std::pair<Type1, Type2> value) const {
        return HashInts(value.first, value.second);
    }
};


} // namespace base

#endif   // ----- #ifndef HASH_INC  -----
