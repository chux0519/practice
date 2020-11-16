#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* left;
  bool stop = false;
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr) return nullptr;
    ListNode* right = head;
    left = head;
    recursive(right, m, n);
    return head;
  }

  void recursive(ListNode* right, int m, int n) {
    if (n == 1) return;

    // keep moving this, util n == 1
    right = right->next;

    // keep moving this when m > 1 (m < n)
    if (m > 1) left = left->next;

    // recursive, position the left and right ptr
    // to the proper position
    recursive(right, m - 1, n - 1);

    cout << "m, n, left, right" << endl;
    cout << m << ", " << n << ", " << left->val << ", " << right->val << endl;

    if (left == right || right->next == left) stop = true;

    if (stop) return;

    std::swap(left->val, right->val);

    left = left->next;  // move left forward
    // call stack will move right backwrd
  }
};
