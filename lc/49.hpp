#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret;
    unordered_map<string, vector<string>> m;

    for (int i = 0; i < strs.size(); i++) {
      char hash[26] = {'a'};
      for (auto c : strs[i]) {
        hash[c - 'a']++;
      }
      string s(hash, hash + 26);
      m[s].push_back(strs[i]);
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      ret.push_back(it->second);
    }
    return ret;
  }
};
