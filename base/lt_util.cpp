/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_util.cpp
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
#include <cmath>
#include <string>
#include <vector>

namespace lt {

const char *itoa(char buf[], int value) {
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

int atoi(char buf[]) {
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

double atof(const char *s) {
    double value = 0.0f;
    int i = 0;
    int sign = 1;
    // skip front spaces
    for (; isspace(s[i]); ++i);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    // 整数部分
    for (; isdigit(s[i]) && s[i] != '\0'; ) {
        value = value + s[i] - '0';
        ++i;
    }
    // 跳过小数点
    if (s[i] == '.') {
        ++i;
    }
    // 小数部分
    for (double power = 10.0; isdigit(s[i]) && s[i] != '\0'; ++i) {
        value = value + (s[i]-'0')/power;
        power *= 10.0;
    }
    value *= sign;
    // 科学计数法
    if (s[i] == 'e' || s[i] == 'E') {
        double eval = 0.0;
        ++i;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') {
            ++i;
        }
        for (; isdigit(s[i]) && s[i] != '\0'; ++i) {
            eval = 10.0 * eval + s[i] - '0';
        }
        value = (sign == -1) ? value/pow(10.0, eval) : value * pow(10.0, eval);
    }

    if (s[i] != '\0') {
        return 0.0f;
    }
    
    return value;
}

char *RemoveContinuousSpaces(char *buf, char c) {
    char *p = buf;
    char *q = p + 1;
    // skip begin
    while (!(*p == c && *q == c)) {
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
char *RemoveContinuousSpaces(std::string &str, char c) {
    std::string::iterator uniq_iter = std::unique(str.begin(), str.end(),
            [c](const char &c1, const char &c2) {
            return (c1 == c && c2 == c);
            });
    str.erase(uniq_iter, str.end());

    return const_cast<char*>(str.c_str());
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
    std::sort(s.begin(), s.end());
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


char *reverse(char *str, int begin, int end) {
    char *p = str + begin;
    char *q = str + end;
    while (p < q) {
        std::swap(*p, *q);
        ++p;
        --q;
    }
    return str;
}

char *reverse(char *s) {
    char *p = s;
    char *q = s;
    while (*q != '\0') {
        if (*q == ' ') {
            reverse(s, p - s, q - s - 1);
            p = q + 1;
        }
        ++q;
    }
    reverse(s, p - s, q - s - 1);
    reverse(s, 0, strlen(s) - 1);

    return s;
}

void movn(char *str, int pos, int n) {
    int epos = strlen(str);
    for (int i = epos; i >= pos; i--) {
        str[i + n] = str[i];
    }

    for (int i = pos; i < pos + n; ++i) {
        str[i] = '_';
    }
}

char *ReplaceSpace(char *str, uint32_t len) {
    uint32_t space_count = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') ++space_count;
    }

    uint32_t new_len = len + 2 * space_count;
    int i = len - 1;
    int j = new_len - 1;
    while (i >= 0 && j >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;
        } else {
            str[j--] = str[i--];
        }
    }

    str[new_len] = '\0';

    return str;
}

} // namespace lt

