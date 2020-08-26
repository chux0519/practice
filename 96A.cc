#include <bits/stdc++.h>
using namespace std;

int main() {
  string in;
  cin >> in;
  int count_0 = 0;
  int count_1 = 0;
  for (auto c : in) {
    if (c == '1') {
      count_1++;
      count_0 = 0;
    }
    if (c == '0') {
      count_0++;
      count_1 = 0;
    }
    if (count_0 >= 7 || count_1 >= 7) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
