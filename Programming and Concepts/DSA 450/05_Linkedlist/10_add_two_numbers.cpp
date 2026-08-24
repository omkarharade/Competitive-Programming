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


Node* addTwoLists(Node* head1, Node* head2) {
	
        // remove leading zeroes in first linked list
        
        while(head1 -> next != nullptr && head1 -> data == 0){
            head1 = head1 -> next;
        }
        
        // remove leading zeroes in second linked list 
        
        while(head2 -> next != nullptr && head2 -> data == 0){
            head2 = head2 -> next;
        }
        
        
        int carryValue = 0;
        head1 = reverseListIter(head1);
        head2 = reverseListIter(head2);
        Node* first = head1;
        Node* second = head2;
        Node* ansHead = new Node(10);
        Node* ansLL = ansHead;
        
        while(first != nullptr && second != nullptr){
            
            // calculate result of the addition and calculate
            // carryValue and unit data to add to node data
            
            int currValue = first -> data + second -> data + carryValue;
            carryValue = currValue / 10;
            currValue = currValue % 10;
            
            // add the result of the addition to a new node and add it to the ans linked list
            Node* newNode = new Node(currValue);
            ansLL -> next = newNode;
            ansLL = ansLL -> next;
            
            // update the first and second pointer 
            first = first -> next;
            second = second -> next;
        }
        
        while(first != nullptr){
            
            // calculate result of the addition and calculate
            // carryValue and unit data to add to node data
            
            int currValue = first -> data + carryValue;
            carryValue = currValue / 10;
            currValue = currValue % 10;
            
            // add the result of the addition to a new node and add it to the ans linked list
            Node* newNode = new Node(currValue);
            ansLL -> next = newNode;
            ansLL = ansLL -> next;
            
            // update the first pointer
            first = first -> next;
        }
        
        while(second != nullptr){
            
            // calculate result of the addition and calculate
            // carryValue and unit data to add to node data
            
            int currValue = second -> data + carryValue;
            carryValue = currValue / 10;
            currValue = currValue % 10;
            
            // add the result of the addition to a new node and add it to the ans linked list
            Node* newNode = new Node(currValue);
            ansLL -> next = newNode;
            ansLL = ansLL -> next;
            
            // update the first pointer
            second = second -> next;
        }
        
        // after processing everything, if carry is still present 
        // add it to the ans linked list 
        
        if(carryValue){
            
            Node* node = new Node(carryValue);
            ansLL -> next = node;
            ansLL = ansLL -> next;
        }
        
        // delete the dummy ans head which we added initially
        Node* tempHead = ansHead;
        ansHead = ansHead -> next;
        delete(tempHead);
        
        // reverse the ans sequence as we calculated in reverse order initially
        ansHead = reverseListIter(ansHead);
        
        // return the head of the ans linked list
        return ansHead;
    }