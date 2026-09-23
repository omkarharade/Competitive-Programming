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
 * Using hash set for storing previously visited nodes,
 * if a node's next node is already visited, the next node is the starting point
 * of the loop,
 *
 * so set current node's next as null, thus removing the loop
 *
 * Time : O(n)
 * Space : O(n)
 *
 * */

void removeLoop(Node *head) {
  // code here

  unordered_set<Node *> ust;
  Node *currNode = head;
  ust.insert(currNode);

  while (currNode->next != nullptr) {

    if (ust.find(currNode->next) == ust.end()) {
      ust.insert(currNode->next);
      currNode = currNode->next;
    } else {

      // the next node is already present, ie. the next node is the starting
      // point of the loop then to remove the loop we need to point the current
      // node's next pointer to null to remove the link which is forming loop

      currNode->next = nullptr;
      break;
    }
  }
}

/**
 *
 * Expected Approach:
 *
 * Using slow and fast pointers
 * (Floyd's cycle detection algorithm)
 *
 * Time: O(n)
 * Space: O(1)
 *
 * */

void removeLoop2(Node *head) {
  // code here

  if (head == nullptr || head->next == nullptr)
    return;

  Node *slow = head;
  Node *fast = head;

  slow = slow->next;
  fast = fast->next->next;

  while (fast && fast->next) {

    if (slow == fast)
      break;

    slow = slow->next;
    fast = fast->next->next;
  }

  if (slow != fast)
    return;

  // loop exists

  // as loop exists and if the starting point of the loop is head itself
  // then the slow and fast pointer will first meet at the head only

  slow = head;

  // this check is needed when slow and fast both meet
  // at the head of the LL
  if (slow == fast) {

    while (fast->next != head) {
      fast = fast->next;
    }

  } else {

    while (slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  // now we have reached to one node before the start node of the loop
  // so we remove the loop by pointing its next pointer to null, thus removing
  // the loop

  fast->next = nullptr;
}

int main() { return 0; }