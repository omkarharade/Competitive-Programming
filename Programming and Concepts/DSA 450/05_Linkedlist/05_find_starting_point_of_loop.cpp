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
 * Basic Approach:
 *
 *
 * using hashing, return the first node which is already traversed,
 * it is the starting point of the loop
 *
 * Time : O(n)
 * Space : O(n)
 *
 * */

int cycleStart(Node *head) {
  // code here

  unordered_set<Node *> ust;
  Node *curr = head;

  while (curr != nullptr) {

    if (ust.find(curr) == ust.end()) {

      ust.insert(curr);
      curr = curr->next;
    } else {
      // node already visited before, this is the first node, return it
      return curr->data;
    }
  }

  return -1;
}

int cycleStart2(Node *head) {
  // code here

  Node *slowPtr = head;
  Node *fastPtr = head;

  bool loopExists = false;

  while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {

    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if (slowPtr == fastPtr) {
      loopExists = true;
      break;
    }
  }

  if (!loopExists)
    return -1;

  // loop exists, both slow and fast pointer are at the first meeting point
  // bring one of the two pointer at the head, as both of them will now move by
  // one place

  slowPtr = head;

  while (slowPtr != fastPtr) {

    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
  }

  return slowPtr->data;
}

int main() { return 0; }