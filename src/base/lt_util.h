/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_util.h
 *
 * @breaf: 常见小算法的声明
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/22 10时30分04秒
 *
 **/


#ifndef  LT_UTIL_INC
#define  LT_UTIL_INC

#include <cstdlib>
#include <cassert>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>


#include "lt_types.h"

namespace lt {

// int类型的数转换为C风格的字符串
// 1234 -> "1234"
// -1234 -> "-1234"
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

// 将c风格字符串尽可能多的转换为数字
// [1] "1234" -> 1234
// [2] "+1234" -> 1234
// [3] "-1234" -> -1234
// [4] "    1234" -> 1234 
// [5] "   -1234" -> 1234 
// [6] " ab cd 1234def a" -> 1234 
//
// 注意:算法不支持八进制和十六进制的问题
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


// 字符串转换成浮点数
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

// 移除字符串中连续的指定的字符(默认是空格' ')
// 只保留一个空格
// 例如 world   world! -> hello world!
char *RemoveContinuousSpaces(char *buf, char c='') {
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
// 生成全排列的算法
std::vector<std::string> Perm(std::string &s) {
    std::vector<std::string> perms;
    std::sort(s.begin(), s.end());
    do {
        perms.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    return perms;
}

// 字符串s中长度为m的子串的全排列
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

// 逆序字符串中的单词
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

// 生成[0, range)之间的随机数
int random(int range) {
    assert(range > 0);
    return std::rand() % range;
}

int random(int low, int high) {
    if (low > high) std::swap(low, high);
    return low + random(high - low);
}

template <class T>
void random_shuffle(std::vector<T> &array) {
    typedef typename std::vector<T>::size_type size_type;
    size_type n = array.size();
    for (size_type i = 0; i < n; ++i) {
        size_type index = lt::random(i, n);
        std::swap(array[i], array[index]);
    }
}

std::string toupper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::toupper(c);
            });
    return s;
}

std::string tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
            });
    return s;
}


#include <string>
#include <iomanip>

template <typename T, unsigned width, unsigned precision>
void print_array(T *array,              // array to print_array
                 int n,                 // number of elements to precision
                 int row,               // number of elements per row
                 std::string array_name // array namespace
                 ) {
    using std::cout;
    using std::endl;
    std::string line(" index | content\n ------+-");
    cout << "\n\n array \"" << array_name << "\", length " << n << endl << endl;
    cout << line.append(width * row, '-');

    for (int i = 0; i < n; i++) {
        if (i % row == 0) {
            cout << endl << std::setw(6) << i << " | ";
        }
        cout << std::setw(width) << std::fixed << std::setprecision(precision) << array[i];
    }
    cout << endl << endl;
}

} // namespace lt

#endif   // ----- #ifndef LT_UTIL_INC  -----
