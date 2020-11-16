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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return head;
    ListNode *tail = head;
    ListNode *cur = head;
    int len = 0;
    while (cur) {
      tail = cur;
      cur = cur->next;
      len += 1;
    }
    k %= len;
    if (k == 0) return head;
    k = len - k;
    cur = head;
    while (--k) {
      cur = cur->next;
    }
    ListNode *new_tail = cur;
    ListNode *new_head = cur->next;

    tail->next = head;
    new_tail->next = nullptr;

    return new_head;
  }
};
