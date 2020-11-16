#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> v(k, 0);
    int i = 0;
    while (i >= 0) {
      v[i]++;
      if (v[i] > n)
        i--;
      else {
        if (i == k - 1)
          ret.push_back(v);
        else {
          i++;
          v[i] = v[i - 1];
        }
      }
    }
    return ret;
  }
};

/*
 * 类似进制转换，组合过程可以总结为
 * 1. 初始化 v[0,0,..0] 长度为 k
 * 2. 从左到右初始化 v 为 [1,2,3..k]
 * 3. 从右往左进行增加，进位
 *    3.1 把 [1,2,3,..k] 到 [1,2,3,..n] 都放到结果里面
 *    3.2 继续单增，[1,2,3,..n+1] 不符合要求，这时进行进位操作
 *    [1,2,3,..k-2, k, k+1]，此时 3 开始循环，直到进到最高位
 * */
