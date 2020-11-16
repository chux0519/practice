#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int zcol = 0;
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) zcol = 1;
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;  // row[0]
          matrix[0][j] = 0;  // col[0]
        }
      }
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
      }
    }

    if (matrix[0][0] == 0) {
      for (int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
    }
    if (zcol) {
      for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
  }
};

// O(1) space
