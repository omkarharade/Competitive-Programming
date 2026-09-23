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

Node *reverseLL(Node *head) {

  Node *prev = nullptr;
  Node *curr = head;

  while (curr != nullptr) {

    Node *next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }

  return prev;
}

bool isPalindrome(Node *head) {
  //  code here

  if (head->next == nullptr)
    return true;

  Node *fast = head;
  Node *slow = head;

  // Step 1: find the mid element

  while (fast->next != nullptr && fast->next->next != nullptr) {

    fast = fast->next->next;
    slow = slow->next;
  }

  // middle node is shown by slow pointer

  Node *head2 = slow->next;
  slow->next = nullptr;

  // Step 2: reverse the 2nd half of the nodes
  head2 = reverseLL(head2);
  slow->next = head2;

  // Step 3: Traverse the first half and 2nd half of linked list one by one
  // check one by one, if any of them do not match return false
  // else return true

  Node *curr1 = head;
  Node *curr2 = head2;
  bool ans = true;

  while (curr1 != nullptr && curr2 != nullptr) {

    if (curr1->data != curr2->data) {
      ans = false;
      break;
    }

    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return ans;
}

int main() { return 0; }