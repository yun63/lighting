/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: traits.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/12/27 15时10分32秒
 *
 **/

#include <iostream>

template<typename T>
class AccumulateTraits;

template<>
class AccumulateTraits<char> {
public:
    typedef int AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulateTraits<short> {
public:
    typedef int AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulateTraits<int> {
public:
    typedef long AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulateTraits<unsigned int> {
public:
    typedef unsigned long AccT;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulateTraits<float> {
public:
    typedef double AccT;
    static AccT zero() {
        return 0;
    }
};

template<typename T>
typename AccumulateTraits<T>::AccT accum(T const *begin, T const *end) {
    typedef typename AccumulateTraits<T>::AccT AccT;
    AccT total = AccumulateTraits<T>::zero();
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

template<typename T,
         typename AT = AccumulateTraits<T> >
class Accum {
public:
    static typename AT::AccT accum(T const *begin, T const *end) {
        typename AT::AccT total = AT::zero();
        for (; begin != end; ) {
            total += *begin;
            ++begin;
        }
        return total;
    }
};


int main(int argc, char *argv[])
{
    int num[] = {1, 2, 3, 4, 5};
    std::cout << "the average value of the integer values is "
        << accum(&num[0], &num[5]) / 5 << std::endl;

    char name[] = "templates";
    int len = sizeof(name) - 1;
    std::cout << "the average value of the characters in \""
        << name << "\" is "
        << accum(&name[0], &name[len]) / len << std::endl;

    Accum<int> intAccum;
    int num2[] = {1, 2, 3, 4, 5};
    std::cout << "the average value of the integer values is "
        << intAccum.accum(&num2[0], &num2[5]) / 5 << std::endl;

    Accum<char> charAccum;
    char name2[] =  "templates";
    std::cout << "the average value of the characters in \""
        << name << "\" is "
        << charAccum.accum(&name2[0], &name2[len]) / len << std::endl;
    
    return 0;
}
