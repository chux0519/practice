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
  ListNode *partition(ListNode *head, int x) {
    ListNode l(-1), r(-1);
    ListNode *lp = &l, *rp = &r;
    while (head) {
      if (head->val < x)
        lp = lp->next = head;
      else
        rp = rp->next = head;
      head = head->next;
    }
    rp->next = nullptr;
    lp->next = r.next;
    return l.next;
  }
};
