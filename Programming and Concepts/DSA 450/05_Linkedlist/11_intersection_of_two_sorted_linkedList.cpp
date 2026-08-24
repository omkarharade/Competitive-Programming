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
 * Time Complexity : O(m+n), as each node is processed once.
 * Space Complexity :O(min(m, n)) , where m is the number of nodes in the first list and 
 * n is the number of nodes in the second list, due to the recursion stack.
 * 
 **/


Node* findIntersectionRecur(Node* node1, Node* node2) {
   // code here

   if(node1 == nullptr || node2 == nullptr) return nullptr;

   // node1 and node2 both are not null

   if(node1 -> data == node2 -> data){

      // values match 
      // we add it to ans and move forward

      Node* temp = new Node(node1 -> data);
      temp -> next = findIntersectionRecur(node1 -> next, node2 -> next);
      return temp;

   }

   else if(node1 -> data < node2 -> data){

      // first node value is lower so move it forward as list is sorted
      return findIntersectionRecur(node1 -> next, node2);
   }
   
   else if(node1 -> data < node2 -> data){

      // second node value is lower
      return findIntersectionRecur(node1, node2 -> next);
   }

}


/**
 * 
 * Expected Approach
 * 
 * Time Complexity : O(n+m), as each node is visited at most once.
 * Space Complexity : O(n+m) due to the space needed for the intersection linked list.
 * 
 **/


Node* findIntersection(Node* head1, Node* head2) {
   // code here

   Node* curr1 = head1;
   Node* curr2 = head2;

   Node* ansHead = nullptr;
   Node* ansCurr = nullptr;

   while(curr1 != nullptr && curr2 != nullptr){
      
      // matching intersection value
      // add it to ans 
      // move both pointers
      if(curr1 -> data == curr2 -> data){
          
          if(ansHead == nullptr){
              ansHead = new Node(curr1 -> data);
              ansCurr = ansHead;
          }
          else{
              ansCurr -> next = new Node(curr1 -> data);
              ansCurr = ansCurr -> next;
          }
          
          curr1 = curr1 -> next;
          curr2 = curr2 -> next;
          
      }

      // second value is smaller so move it forward as list is sorted
      else if(curr1 -> data > curr2 -> data){
          curr2 = curr2 -> next;
      }

      // first value is smaller so move it forward
      else if(curr1 -> data < curr2 -> data){
          curr1 = curr1 -> next;
      }
   }

   // return the head of the ans
   return ansHead;

}


/**
 * Alternate Approach
 * Intuition
 * We can find intersection of two linked lists using a hashmap. Create a hashmap to keep track of the elements 
 * present in the first linked list. Then, iterate through the second linked list, checking if each element is 
 * present in the hashmap. If found, it adds the element to the resulting linked list.
 * 
 **/


int main() {


   return 0;
}