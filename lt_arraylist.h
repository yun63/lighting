/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_arraylist.h
 *
 * @breaf: 二维array
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/14 23时30分53秒
 *
 **/


#ifndef  LT_ARRAYLIST_INC
#define  LT_ARRAYLIST_INC

#include <cstdint>
#include <cstdlib>

#include "noncopyable.h"

namespace lt {


template<class T=char>
class Array2D : public noncopyable {
public:
    Array2D(uint32_t row, uint32_t col)
    : num_of_rows_(row)
    , num_of_cols_(col)
    , data_(new T[row*col]) {}

    virtual ~Array2D () {
        delete []data_;
    }

    /**
     * @brief return number of rows of this array
     *
     * @return 
     */
    inline const uint32_t row() const { return num_of_rows_; }
    /**
     * @brief return number of columns of this array
     *
     * @return 
     */
    inline const uint32_t col() const { return num_of_cols_; }

    /**
     * @brief return the value by the given(row, col);
     *
     */
    inline T &operator()(int row, int col) { return data_[row*num_of_rows_+col]; }
    inline const T&operator()(int row, int col) const { return data_[row*num_of_cols_+col]; }

    inline T *operator[](int row) { return &(data_[row*num_of_cols_]); }
    inline const T *operator[](int row) const { return &(data_[row*num_of_cols_]); }
    /**
     * @brief clear the array by a given value
     *
     * @param value
     */
    void clear(const T &value) {
        for (uint32_t i = 0; i < num_of_cols_*num_of_cols_; i++) {
            data_[i] = value;
        }
    }

private:
    uint32_t num_of_rows_;
    uint32_t num_of_cols_;
    T *data_;
};

} // namespace lt

#endif   // ----- #ifndef LT_ARRAYLIST_INC  -----
