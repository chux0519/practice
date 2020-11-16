#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  enum DIR { RIGHT, DOWN, LEFT, UP };
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret;
    for (int i = 0; i < n; i++) {
      vector<int> row(n, 0);
      ret.push_back(row);
    }
    int x = 0;
    int y = 0;
    int num = 1;
    int w = n - 1;
    int h = n - 1;
    int l = 0;
    int t = 0;

    enum DIR dir = RIGHT;
    while (x >= l && x <= w && y >= t && y <= h) {
      // cout << x << ", " << y << "    num:" << num << endl;
      ret[y][x] = num;
      num++;
      if (num > n * n) break;
      switch (dir) {
        case RIGHT: {
          if (x == w) {
            dir = DOWN;
            y++;
            t++;
          } else {
            x++;
          }
          break;
        }
        case DOWN: {
          if (y == h) {
            dir = LEFT;
            x--;
            w--;
          } else {
            y++;
          }
          break;
        }
        case LEFT: {
          if (x == l) {
            dir = UP;
            y--;
            h--;
          } else {
            x--;
          }
          break;
        }
        case UP: {
          if (y == t) {
            dir = RIGHT;
            x++;
            l++;
          } else {
            y--;
          }
          break;
        }
      }
      // cout << dir << ": " << x << ", " << y << endl;
      // cout << "x range: [" << l << ", " << w << "]" << endl;
      // cout << "y range: [" << t << ", " << h << "]" << endl;
    }
    return ret;
  }
};
