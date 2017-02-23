/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: util.h
 *
 * @breaf:  常见算法的实现
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/22 10时30分04秒
 *
 **/


#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

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
    while (isspace(*p)) ++p;
    while (!isdigit(*p) && *p != '+' && *p != '-') ++p;
    if (*p == '-') {
        sig = -1;
        ++p;
    } else if (*p == '+') {
        ++p;
    }

    while (::isdigit(*p)) {
        value = value * 10;
        value += *p - '0';
        ++p;
    }

    return sig * value;
}

const char *RemoveContinuousSpaces(char *buf, char c) {
    char *p = buf;
    char *q = p + 1;
    // skip begin
    while (*p == c && *q == c) {
        ++p;
        ++q;
    }
    while (*q != '\0') {
        if (!(*p == c && *q == c)) {
            *(++p) = *q;
        }
        ++q;
    }
    *(++p) = '\0';
    
    return buf;
}

// version 2
const char *RemoveContinuousSpaces(std::string &str, char c) {
    std::string::iterator uniq_iter = std::unique(str.begin(), str.end(),
            [c](const char &c1, const char &c2) {
            return (c1 == c && c2 == c);
            });
    str.erase(uniq_iter, str.end());

    return str.c_str();
}

std::vector<std::string> Perm(std::string &s) {
    std::vector<std::string> perms;
    std::sort(s.begin(), s.end());
    do {
        perms.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    return perms;
}

std::vector<std::string> Perm(std::string &s, std::size_t m) {
    std::vector<std::string> perms;
    if (m > s.size()) {
        return perms;
    }
    std::string substr;
    do {
        substr = s.substr(0, m);
        auto it = std::find(perms.begin(), perms.end(), substr);
        if (it == perms.end()) {
            perms.push_back(substr);
        }
    } while (std::next_permutation(s.begin(), s.end()));

    return perms;
}


