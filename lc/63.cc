#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void print(vector<vector<int>>& dp) {
    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < dp[0].size(); j++) {
        cout << dp[i][j] << ", ";
      }
      cout << endl;
    }
  }
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
    if (obstacleGrid[m - 1][n - 1]) return 0;

    dp[m - 1][n - 1] = 1;
    int blocked = 0;
    for (int dy = 1; dy < m; dy++) {
      if (blocked) {
        dp[m - 1 - dy][n - 1] = 0;
        continue;
      }
      if (!obstacleGrid[m - 1 - dy][n - 1])
        dp[m - 1 - dy][n - 1] = 1;
      else {
        blocked = 1;
        dp[m - 1 - dy][n - 1] = 0;
      }
    }

    blocked = 0;
    for (int dx = 1; dx < n; dx++) {
      if (blocked) {
        dp[m - 1][n - 1 - dx] = 0;
        continue;
      }
      if (!obstacleGrid[m - 1][n - 1 - dx])
        dp[m - 1][n - 1 - dx] = 1;
      else {
        blocked = 1;
        dp[m - 1][n - 1 - dx] = 0;
      }
    }

    // print(dp);
    for (int dy = 1; dy < m; dy++) {
      for (int dx = 1; dx < n; dx++) {
        if (!obstacleGrid[m - 1 - dy][n - 1 - dx])
          dp[m - 1 - dy][n - 1 - dx] =
              dp[m - 1 - dy][n - dx] + dp[m - dy][n - 1 - dx];
      }
    }
    // print(dp);

    return dp[0][0];
  }
};

int main() { return 0; }
