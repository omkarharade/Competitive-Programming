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
 * Basic Approach
 *
 * Traverse the circular linked list, keep adding the newly traversed nodes
 * to the set, if the node is traversed twice, we know it is circular linked
 * list
 *
 * if we traversed a node which is already present in set - return true
 * if we come out of while loop, we know the linked list is not circular - hence
 * return false
 *
 *
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 *
 * */
bool isCircular(Node *head) {
  // code here

  unordered_set<Node *> ust;
  Node *curr = head;

  while (curr->next != nullptr) {

    if (ust.find(curr) == ust.end()) {
      ust.insert(curr);
    } else {
      return true;
    }

    curr = curr->next;
  }

  return false;
}

/**
 * Efficient Approach 1
 *
 * If we reach node which is head again we return true,
 * If we exit loop before reaching head we return false
 *
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 *
 * */
bool isCircular2(Node *head) {

  // If the head is null, the linked list is empty,
  // so it is circular
  if (!head)
    return true;

  // Traverse the linked list until either the end
  // is reached or the next node is equal to the head
  Node *curr = head;
  while (curr && curr->next != head)
    curr = curr->next;

  // If the end is reached before finding
  // the head again, the linked list is not circular
  if (!curr)
    return false;

  // If the head is found again before reaching
  // the end, the linked list is circular
  return true;
}

/**
 * Efficient Approach 2
 *
 * Use slow and fast pointer, if fast matches with slow, we know it's a circular
 * linked list - return true
 *
 * if we come out of loop we return false as it is not circular linked list.
 *
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 *
 * */

bool isCircular3(Node *head) {
  // code here

  Node *slow = head;
  Node *fast = head;

  while (fast->next != nullptr and fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }

  return false;
}

int main() { return 0; }