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




Node* reverseLL(Node* head){
    
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


Node* addOne(Node* head) {
    // code here
    
    head = reverseLL(head);
    Node* curr = head;
    bool isCarryUpHandled = false;


    // we have already reversed the linked list in order to ease the process
    // we process till the 2nd last digit and reach the last digit (reversed order)

    while(!isCarryUpHandled && curr -> next != nullptr){
        
        if(curr -> data == 9){
            curr -> data = 0;
        }
        else {
            curr -> data = curr -> data + 1;
            isCarryUpHandled = true;
        }
        
        curr = curr -> next;
    }
    
    
    // till the 2nd last digit if carry is not yet handled
    // and if the last digit is 9 then we need to make it 10
    // ie. the last element will become 0 and we add one more node '1'
    //(reversed order)


    if(!isCarryUpHandled){
        
        if(curr -> data == 9){
            Node* node = new Node(1);
            curr -> data = 0;
            curr -> next = node;
        }
        else{
            curr -> data = curr -> data + 1;
        }
    }


    // after all the processing, again reverse the list to
    // make it like the original order
    
    head = reverseLL(head);
    return head;
}





int main() {


    return 0;
}