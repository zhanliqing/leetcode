/***************************************************************************
 *
 * Copyright (c) 2024 xx.com All Rights Reserved
 * @File:  Solution.cpp
 * @author zhanliqing@xx.com
 * @date   2024/7/4 19:15:56
 *
 **************************************************************************/
#include <iostream>
#include <vector>
#include <random>
#include "../util.h"
#include <algorithm>

using namespace std;

static int get_top_k(vector<int> &nums, int k) {

    return 0;
}

int main(int argc, char **argv) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1024);

    vector<int> nums;
    for (int i = 0; i < 50; i++) {
        nums.push_back(dis(gen));
    }
    string prefix = "v";
    print_vector(prefix, nums);

    int k = 10;
    cout << "top k is :" << get_top_k(nums, k) << endl;
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    cout << "real top k is :" << nums.at(k) << endl;
    return 0;
}