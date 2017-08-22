/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: algo.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/08/22 17时39分28秒
 *
 **/


#include "lt_algo.h"

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    int n = 0;
    input >> n;

    lt::UnionFind graph(n);
    int gi = 0;
    int bi = 0;
    for (int i = 0; i < n; i++) {
        input >> gi >> bi;
        graph.merge(gi, bi);
    }

    graph.output();

    std::map<uint32_t, std::vector<uint32_t>> groups;
    for (int i = 1; i <= n; ++i) {
        uint32_t parent = graph.find(i);
        groups[parent].push_back(i);
    }

    std::map<uint32_t, std::vector<uint32_t>>::const_iterator it = groups.cbegin();
    for (; it != groups.cend(); ++it) {
        std::cout << "group: " << it->first << ",  mermbers: [";
        for (int i = 0; i < it->second.size(); i++) {
            if (i == 0) {
                std::cout << it->second[i];
            } else {
                std::cout << "," << it->second[i];
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }

    return 0;
}
