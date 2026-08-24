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
 * Add unique values in hash set and add them in new list
 * traverse the whole list
 * if the value is unique add it to new list
 * if not then do nothing, move forward
 *
 * Time : O(n)
 * Space : O(n)
 *
 *
 * */

Node *removeDuplicates(Node *head) {
  // code here

  Node *curr = head;
  Node *newHead = nullptr;
  Node *currNew = nullptr;

  unordered_set<int> ust;

  while (curr != nullptr) {

    if (ust.find(curr->data) == ust.end()) {

      ust.insert(curr->data);

      if (newHead == nullptr) {

        newHead = new Node(curr->data);
        currNew = newHead;
      } else {

        currNew->next = new Node(curr->data);
        currNew = currNew->next;
      }
    }

    curr = curr->next;
  }

  return newHead;
}

/**
 *
 * Expected Approach:
 *
 * Traverse the whole array
 * update the next pointer if the next element is duplicate
 * keep updating next pointer until the next pointer is not same as
 * new pointer
 *
 *
 * Time : O(n)
 * Space : O(1)
 *
 *
 * */
Node *removeDuplicates(Node *head) {
  // code here

  Node *curr = head;

  while (curr->next != nullptr) {

    if (curr->data == curr->next->data) {

      // duplicates available

      Node *dNode = curr->next;
      curr->next = curr->next->next;
      delete (dNode);
    } else {
      curr = curr->next;
    }
  }

  return head;
}

int main() { return 0; }