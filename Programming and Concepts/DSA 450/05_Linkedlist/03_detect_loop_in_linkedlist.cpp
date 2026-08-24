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
 * Naive Solution: 
 * 
 * We use unordered set to store the already visited nodes
 * if we encounter any node which is already visited once and stored in set
 * we know there is a loop here and we return true
 * 
 * if not then we traverse and all the nodes will be unique and we return false
 * by default
 * 
 * Time : O(n)
 * Space : O(n)
 * 
 **/

bool detectLoop(Node* head) {
    // code here
    
    unordered_set<Node*> st;
    
    Node* curr = head;
    bool ans = false;
    
    while(curr != nullptr){
        
        if(st.find(curr) == st.end()){
            st.insert(curr);
        }
        else {
            ans = true;
            break;
        }
        
        curr = curr -> next;
    }
    
    return ans;
}


/**
 * Optimised solution using slow and fast pointer
 * 
 * slow moves one place ahead, fast moves 2 places ahead
 * if loop exists then the fast pointer will loop back and will meet the slow 
 * pointer in the process, when it does, we know there is a loop and we break from it 
 * 
 * if there is no loop the pointer never meets and the process ends
 * 
 * Time : O(n)
 * Space : O(1)
 * 
 **/


/*


Mathematical proof

Let the loop length be L.
Suppose at some point the distance between fast and slow is d.

After one iteration:

d′ =d+1
because fast gains one position on slow.

But because the loop is circular, positions are considered modulo L:
d′ =(d+1)modL

After k iterations:
dk =(d+k)modL

They meet when their distance becomes zero:
dk = 0

Therefore:
(d+k)modL=0

which means:
k≡−d(modL)

There always exists such a k, specifically:
k=L−d

(if d=0, they have already met).

Therefore, after at most L iterations, the fast and slow pointers must occupy the same node.


*/

bool detectLoop2(Node* head) {
    // code here
    
    // slow pointer
    Node* slow = head;

    // fast pointer
    Node* fast = head;

    // ans variable
    bool isLoopDetected = false;
    
    while(slow -> next != nullptr && fast -> next != nullptr && fast -> next -> next != nullptr){
        
        // slow pointer - moves 1 place
        slow = slow -> next;

        // fast pointer - moves 2 places
        fast = fast -> next -> next;
        
        if(slow == fast){
            isLoopDetected = true;
            break;
        }
    }
    
    return isLoopDetected;
}




int main() {


	return 0;
}