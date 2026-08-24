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
 * Basic Approach:
 * 
 * Time Complexity : O(m*n), as we do a nested loop check.
 * Space Complexity :O(1), as we don't use any extra space
 * 
 **/

Node* intersectPoint(Node* head1, Node* head2) {
   //  code here

   Node* curr1 = head1;
   Node* curr2 = head2;

   while(curr1 != nullptr){
      
      curr2 = head2;
      
      while(curr2 != nullptr){
          
         if(curr1 == curr2) return curr1;
         else curr2 = curr2 -> next;
      }
      
      curr1 = curr1 -> next;
   }

   return nullptr;
}

/**
 * 
 * Expected Approach
 * 
 * Time Complexity : O(n+m), as each node is visited at most once.
 * Space Complexity : O(n+m) due to the space needed for storing first linked list
 * nodes.
 * 
 **/

Node* intersectPoint2(Node* head1, Node* head2) {
   //  code here

   unordered_set<Node*> ust;
   Node* curr1 = head1;
   Node* curr2 = head2;

   while(curr1 != nullptr){
      
      ust.insert(curr1);
      curr1 = curr1 -> next;
   }

   while(curr2 != nullptr){
      
      if(ust.find(curr2) != ust.end()){
          return curr2;
      }
      
      curr2 = curr2 -> next;
   }

   return nullptr;
}


int main() {

   return 0;
}