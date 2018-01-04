/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_bytes.h
 *
 * @breaf: 比特类
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/01/04 20时20分08秒
 *
 **/


#ifndef  LT_BYTES_INC
#define  LT_BYTES_INC

namespace lt {


template<class T>
class ArrayByte {
public:
    ArrayByte() = default;

    ArrayByte(const T &type) {
        u_.value = type;
    }

    ArrayByte(const ArrayByte<T> &a) {
        u_ = a.u_;
    }

    ArrayByte(ArrayByte<T> &&) = delete;

    ArrayByte<T> &operator=(const ArrayByte<T> &a) {
        u_ = a.u_;
        return *this;
    }

    ArrayByte<T> &operator=(const T &type) {
        u_.value = type;
        return *this;
    }

    ArrayByte<T> &operator=(ArrayByte<T> &&) = delete;

    unsigned char &operator[](unsigned int pos) {
        return u_.bytes[pos];
    }

    unsigned int size() const {
        return sizeof(T);
    }

protected:
    union {
        T value;
        unsigned char bytes[sizeof(T)];
    } u_;
};

} // namespace lt

#endif   // ----- #ifndef LT_BYTES_INC  -----
