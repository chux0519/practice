#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  unordered_map<Node*, Node*> origin_to_copy;
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    if (origin_to_copy.find(head) != origin_to_copy.end()) {
      return origin_to_copy[head];
    }
    // create a new node
    Node* c = new Node(head->val);
    origin_to_copy[head] = c;
    c->next = copyRandomList(head->next);
    c->random = copyRandomList(head->random);
    return c;
  }
};

/*
 * 这一题有很多解法，上面是我最喜欢的一种。比较巧妙。另外比较常见的解法有：
 * 1. 使用 map，进行两次遍历。
 * 2. 改变原来传入的参数，三次遍历，第一次将 copy 挂到 next，第二次更新
 * random，第三次分离 copy 的数据
 * 3. 我最喜欢的解法，利用 map，存储 origin->copy
 * 然后进行递归进行处理，一次遍历，我觉得比较优雅
 * */
