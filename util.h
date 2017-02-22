/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: util.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/22 10时30分04秒
 *
 **/


#include <algorithm>
#include <cctype>

const char *Itoa(char buf[], int value) {
    static char digits[19] = {
        '9', '8', '7', '6', '5', '4', '3', '2', '1', '0',
        '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };
    static const char *zero = digits + 9;

    char *p = buf;
    int i = value;
    do {
        int lsd = i % 10;
        i /= 10;
        *p++ = zero[lsd];
    } while (i != 0);
    if (value < 0) {
        *p++ = '-';
    }
    *p = '\0';

    std::reverse(buf, p);

    return buf;
}

int Atoi(char buf[]) {
    char *p = buf;
    int value = 0;
    int sig = 1;
    // trim whilespaces at front of string buf
    while (::isspace(*p)) ++p;
    if (*p == '-') {
        sig = -1;
        ++p;
    }
    while (::isdigit(*p)) {
        value = value * 10;
        value += *p - '0';
        ++p;
    }

    return sig * value;
}
