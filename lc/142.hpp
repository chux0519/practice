#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    bool has_cycle = false;
    while (fast && slow) {
      // cout << fast->val << ", " << slow->val << endl;
      if (!fast->next) return nullptr;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        has_cycle = true;
        break;
      }
    }
    if (!has_cycle) {
      return nullptr;
    }
    ListNode *ptr = head;
    while (slow != ptr) {
      ptr = ptr->next;
      slow = slow->next;
    }
    return ptr;
  }
};
