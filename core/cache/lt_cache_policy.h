/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_cache_policy.h
 *
 * @breaf: cache抽象接口
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/20 09时36分03秒
 *
 **/



#ifndef  LT_CACHE_POLICY_INC
#define  LT_CACHE_POLICY_INC

#include <unordered_set>

namespace lt {


template<class Key>
class CachePolicy {
public:
    virtual void insert(const Key &key) = 0;
    virtual void touch(const Key &key) = 0;
    virtual void erase(const Key &key) = 0;
    virtual const Key &candidate() const = 0;
};

template<class Key>
class NoChaPolicy : public CachePolicy<Key> {
public:
    NoChaPolicy() = default;
    ~NoChaPolicy () override = default;

    void insert(const Key &key) override { key_storage_.emplace(key); }
    void touch(const Key &key) override {}
    void erase(const Key &key) override { key_storage_.erase(key); }
    const Key &candidate() const override { return *(key_storage_.cbegin()); }

private:
    std::unordered_set<Key> key_storage_;
};

} // namespace lt

#endif   // ----- #ifndef LT_CACHE_POLICY_INC  -----
