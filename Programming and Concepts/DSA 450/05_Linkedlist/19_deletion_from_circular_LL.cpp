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

Node *deleteNode(Node *head, int key) {
  // code here

  // For Circular Linked list with one node
  if (head->next == head) {

    if (head->data == key) {
      delete (head);
      return nullptr;
    } else
      return head;
  }

  // For circular linked list with two nodes
  else if (head->next != nullptr && head->next->next == head) {

    if (head->data == key) {
      Node *node = head;
      head = head->next;
      head->next = head;
      delete (node);
      return head;
    } else if (head->next->data == key) {
      Node *node = head->next;
      head->next = head;
      delete (node);
      return head;
    } else
      return head;
  }

  // For circular linked list with more than two nodes
  else {

    Node *prev = head;
    Node *curr = head->next;
    Node *nextP = head->next->next;

    bool cycleTraversed = false;

    while (!cycleTraversed) {

      if (curr->data == key) {

        // if the curr node with the key is a head, update the head to next node
        if (curr == head) {
          head = head->next;
        }

        prev->next = nextP;
        delete (curr);
        break;
      }

      if (curr == head)
        cycleTraversed = true;
      prev = curr;
      curr = nextP;
      nextP = nextP->next;
    }

    return head;
  }
}

int main() { return 0; }