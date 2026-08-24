#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

	
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};


/**
 * 
 * Traverse till the last node and move it to the front 
 * and update the head to the new head
 * 
 * Time : O(n)
 * Space : O(1)
 * 
 */


Node *moveToFront(Node *head) {
  
    // If the list is empty or has only one node,
    // no need to move
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // To keep track of the second last node
    Node *secLast = NULL;

    // To traverse to the last node
    Node *last = head;

    // Traverse the list to find the last and
    // second last nodes
    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }

    // Change the next of second last node to NULL
    secLast->next = NULL;

    // Make the last node as the new head
    last->next = head;
    head = last;

    return head;
}



int main() {


	return 0;
}