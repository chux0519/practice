#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp;
    for (int i = 0; i < m; i++) {
      vector<int> v(n, 0);
      dp.push_back(v);
    }

    for (int x = 0; x < n; x++) dp[m - 1][x] = 1;
    for (int y = 0; y < m; y++) dp[y][n - 1] = 1;

    for (int dx = 1; dx < n; dx++) {
      for (int dy = 1; dy < m; dy++) {
        dp[m - dy - 1][n - 1 - dx] =
            dp[m - dy - 1][n - dx] + dp[m - dy][n - dx - 1];
      }
    }
    return dp[0][0];
  }
};

int main() { return 0; }
