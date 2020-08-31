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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode();
    ListNode *p = ret;
    int c = 0;
    int cur = 0;
    while (l1 || l2) {
      cur = 0;
      if (l1)
        cur += l1->val;
      if (l2)
        cur += l2->val;
      cur += c;
      if (cur >= 10) {
        c = 1;
        cur -= 10;
      } else {
        c = 0;
      }
      ListNode *node = new ListNode(cur);
      p->next = node;
      p = p->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    if (c)
      p->next = new ListNode(c);
    return ret->next;
  }
};

int main() { return 0; }
