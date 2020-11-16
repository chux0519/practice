#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(m, 0);
    dp[m - 1] = grid[m - 1][n - 1];

    for (int y = m - 2; y >= 0; y--) dp[y] = dp[y + 1] + grid[y][n - 1];

    for (int x = n - 2; x >= 0; x--) {
      dp[m - 1] += grid[m - 1][x];
      for (int y = m - 2; y >= 0; y--) {
        dp[y] = min(dp[y], dp[y + 1]) + grid[y][x];
      }
    }

    return dp[0];
  }
};

// 这里 dp 优化成了存储单列，可以降低空间复杂度
