#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class Node {
public:
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = nullptr;
  }
};

/**
 *
 * Basic Approach:
 *
 * Time: O(n^2)
 * Space: O(1)
 *
 * */

Node *removeDuplicates(Node *head) {
  // code here

  Node *outer = head;

  // nodes represented by outer pointer will always be unique
  // due to processing loop

  while (outer != nullptr) {

    Node *inner = outer->next;
    Node *innerPrev = outer;

    while (inner != nullptr) {

      if (outer->data == inner->data) {

        innerPrev->next = inner->next;
        delete (inner);
        inner = innerPrev->next;
      } else {

        innerPrev = inner;
        inner = inner->next;
      }
    }

    outer = outer->next;
  }

  return head;
}

/**
 *
 * Expected Approach:
 *
 * Using hash set, add unique elements to hash set
 * traverse the whole list, and update pointers if the element is already
 * traversed
 *
 * Time : O(n)
 * Space : O(n)
 *
 * */

Node *removeDuplicates2(Node *head) {
  // code here

  unordered_set<int> ust;
  Node *curr = head;
  Node *prev = nullptr;

  while (curr != nullptr) {

    if (ust.find(curr->data) == ust.end()) {
      // element is unique

      ust.insert(curr->data);
      prev = curr;
      curr = curr->next;

    } else {

      prev->next = curr->next;
      delete (curr);
      curr = prev->next;
    }
  }

  return head;
}

int main() { return 0; }