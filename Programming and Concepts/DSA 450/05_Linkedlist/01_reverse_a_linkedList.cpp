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
 * Iterative traversal of Linked List
 * Time : O(n)
 * Space : O(1)
 * 
 **/


Node* reverseListIter(Node* head) {

	Node* prevNode = nullptr;
	Node* currNode = head;
	Node* nextNode;

	if(head == nullptr) return head;

	while(currNode != nullptr){

	    // save the current node's next node
	    nextNode = currNode -> next;

	    // reverse the current node's connection
	    currNode -> next = prevNode;

	    // update the prev node and current node
	    prevNode = currNode;
	    currNode = nextNode;
	}

	return prevNode;
}


/**
 * 
 * Recursive traversal of Linked List
 * Time : O(n)
 * Space : O(n)
 * 
 **/

Node* reverseListRecur(Node* currNode, Node* prevNode, Node* nextNode){
    
    // return the prev node which now points to head of this reversed linked list 
	if(currNode == nullptr) return prevNode;

	// update the next pointer to current's next pointer
	nextNode = currNode -> next;

	// reverse the current node's connection to its previous node
	currNode -> next = prevNode;

	// repeat the same process with nextNode as currNode, currNode as prevNode
	reverseListRecur(nextNode, currNode, nextNode);

}

Node* reverseList(Node* head) {
    // code here
    
    Node* currNode = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    
    return reverseListRecur(currNode, prevNode, nextNode);
    
}


/**
 * 
 * Iterative traversal of Linked List using Stack
 * Time : O(n)
 * Space : O(n)
 * 
 * */



Node* reverseList2(Node* head) {
    // code here
    
    stack<Node*> st;
    Node* curr = head;
    

    // add all nodes except the last node to the stack so 
    // the last node of list comes at top of stack
    while(curr -> next != nullptr){
        
        st.push(curr);
        curr = curr -> next;
    }
    
    // make the last node as new head of the linked list
	head = curr;
    
    // reverse all the connections
    while(!st.empty()){
        
        curr -> next = st.top();
        st.pop();

        // update the curr node
        curr = curr -> next;
    }
    
    // the last node's next pointer is not reversed, 
    // we need to do it outside the loop 
    curr -> next = nullptr;

    return updatedHead;
}




int main() {

	Linkedlist ll;

	ll.push(10);
	ll.push(20);
	ll.push(30);
	ll.push(40);
	ll.push(50);
	ll.push(60);

	cout << "original linkedlist is :" << nline;
	ll.print();
	cout << nline;

	// ll.reverse_iter();
	ll.reverse_recur(ll.head);

	cout << "reversed linkedlist is :" << nline;
	ll.print();
	cout << nline;


	return 0;
}