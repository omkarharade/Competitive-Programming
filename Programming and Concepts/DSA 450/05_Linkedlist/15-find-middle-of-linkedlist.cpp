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
 * Brute Force Approach
 * 
 * Calculate the length of Linked List first
 * then calculate middle element position
 * and return it
 * 
 * Time : O(n)
 * Space : O(1)
 * 
 */

Node* middleNode(ListNode* head) {

   Node* temp = head;
   int sizeOfLL = 0;
   while(temp != nullptr){
      sizeOfLL++;
      temp = temp -> next;
   }

   int mid = sizeOfLL/2 + 1;
   temp = head;

   for(int i = 1; i <= mid-1; i++){
      temp = temp -> next;
   }

   return temp;
}


/**
 * Optimal Approach
 * 
 * Use slow and fast pointers
 * 
 * Time : O(n)
 * Space : O(1)
 * 
 */ 

 ListNode* middleNode2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }



int main() {


   return 0;
}