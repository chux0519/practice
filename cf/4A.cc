#include <bits/stdc++.h>
using namespace std;

int main() {
  int i;
  cin >> i;
  string output = (i > 2 && (i - 2) % 2 == 0) ? "YES" : "NO";
  cout << output;
  return 0;
}
