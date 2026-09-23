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

pair<Node *, Node *> splitList(struct Node *head) {
  // code here

  Node *slow = head;
  Node *fast = head;

  while (fast->next != head && fast->next->next != head) {

    slow = slow->next;
    fast = fast->next->next;
  }

  // If there are even nodes in the list
  // them move fast
  if (fast->next->next == head) {
    fast = fast->next;
  }

  // set the header pointer of second half
  Node *head2 = slow->next;

  // Make the second half circular
  fast->next = head2;
  // Make the first half circular
  slow->next = head;

  return {head, head2};
}

int main() { return 0; }