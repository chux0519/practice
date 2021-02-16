#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>{});

    for (int num : nums) {
      vector<vector<int>> newSubsets;
      for (auto item : ret) {
        vector<int> newItem(item);
        newItem.push_back(num);
        newSubsets.push_back(newItem);
      }

      for (auto item : newSubsets) {
        ret.push_back(item);
      }
    }

    return ret;
  }
};

/*
 * subsets 类题目复杂度： 2^N
 * 1. 结果添加空集
 * 2. 结果每个元素新增加某个元素，形成新的 subsets
 * 3. 添加新的 subsets 到结果
 */
