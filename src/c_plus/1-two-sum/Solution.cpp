/*
 * =====================================================================================
 *
 *       Filename:  Solution.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2019/6/11 11:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhanliqing(zhanliqing@xx.com)
 *        Company:  xx
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (tmp.find(target - nums[i]) != tmp.end() && i != tmp[target - nums[i]]) {
                return vector < int > {i, tmp[target - nums[i]]};
            }
        }
        return vector < int > {0, 0};
    }

    vector<int> twoSum1(vector<int> &nums, int target) {
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (tmp.find(target - nums[i]) != tmp.end()) {
                return vector < int > {i, tmp[target - nums[i]]};
            } else {
                tmp[nums[i]] = i;
            }
        }
        return vector < int > {0, 0};
    }

    int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
        int bucket_size = (int) (numsSize * 1.75);
        int bucket[bucket_size];
        for (int i = 0; i < bucket_size; i++) {
            bucket[i] = -1;
        }
        for (int i = 0; i < numsSize; i++) {
            int idx = nums[i] > 0 ? nums[i] % bucket_size : -1 * nums[i] % bucket_size;
            while (bucket[idx] != -1) {
                if (idx >= bucket_size - 1) {
                    idx = 0;
                } else {
                    idx += 1;
                }
            }
            bucket[idx] = i;
        }

        for (int i = 0; i < numsSize; i++) {
            int check = target - nums[i];
            int idx = check > 0 ? check % bucket_size : -1 * check % bucket_size;
            while (bucket[idx] != -1 && nums[bucket[idx]] != check) {
                if (idx >= bucket_size - 1) {
                    idx = 0;
                } else {
                    idx += 1;
                }
            }
            if (i == bucket[idx]) {
                continue;
            }
            if (bucket[idx] != -1) {
                int *data = (int *) malloc(sizeof(int) * 2);
                data[0] = i;
                data[1] = bucket[idx];
                *returnSize = 2;
                return data;
            }
        }
        return NULL;
    }
};

int main() {
    //    vector<int> nums{3, 2, 4};
    int nums[] = {-10, -1, -18, -19};
    int target = -19;
    Solution s;
    //    vector<int> rst = s.twoSum1(nums, target);
    //    cout << rst[0] << "," << rst[1];
    int resultSize = -1;
    int *data = s.twoSum(nums, 4, target, &resultSize);
    cout << "return_size[" << resultSize << "]" << endl;
    stringstream ss;
    ss << "result[";
    if (resultSize > 0) {
        for (int i = 0; i < resultSize; i++) {
            ss << data[i] << ",";
        }
    }
    ss << "]";
    cout << ss.str();
}