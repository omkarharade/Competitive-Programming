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

Node *reverse(Node *head) {
  // code here

  Node *prevP = nullptr, *currP = head, *nextP = nullptr;

  while (currP != nullptr) {

    // set the next pointer to current's next
    nextP = currP->next;

    // reverse the next and prev pointers of current node
    currP->next = prevP;
    currP->prev = nextP;

    // update the prev and curr node by 1 place

    prevP = currP;
    currP = nextP;
  }

  // reassign head to new head ie. prev node
  head = prevP;

  return head;
}

int main() { return 0; }