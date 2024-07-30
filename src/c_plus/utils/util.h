/***************************************************************************
 *
 * Copyright (c) 2024 xx.com All Rights Reserved
 * @File:  util.h
 * @author zhanliqing@xx.com
 * @date   2024/7/4 19:27:08
 *
 **************************************************************************/
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

static void print_vector(string &prefix, vector<int> &v) {
    stringstream ss;
    ss << prefix << "[";
    for (auto i: v) {
        ss << i << " ";
    }
    ss << "]";
    cout << ss.str() << endl;
}
