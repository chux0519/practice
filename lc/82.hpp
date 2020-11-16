#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy = ListNode(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *cur = prev->next;
    while (cur) {
      while (cur->next && prev->next->val == cur->next->val) cur = cur->next;
      if (prev->next == cur)
        prev = prev->next;
      else
        prev->next = cur->next;
      cur = cur->next;
    }
    return dummy.next;
  }
};
