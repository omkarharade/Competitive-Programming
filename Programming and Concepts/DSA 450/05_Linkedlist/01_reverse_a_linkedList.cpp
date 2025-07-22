#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

struct Node {

	int data;
	struct Node* next;

	Node(int data) {

		this -> data = data;
		this -> next = NULL;
	}
};

struct Linkedlist {

	Node* head;
	Linkedlist() { head = NULL; }

	void reverse_iter() {

		Node *curr = head;
		Node *prev = NULL, *next = NULL;

		while (curr != NULL) {

			next = curr -> next; // update next pointer
			curr -> next = prev;  // this is the reversed link


			// shifting the pointer by one place each

			prev = curr;
			curr = next;

		}

		head = prev;

	}

	void reverse_recur(Node* curr, Node* prev = NULL) {

		// base case
		if (curr == NULL) return;

		Node* next = curr -> next;
		curr -> next = prev;
		head = curr;

		reverse_recur(next, curr);
	}


	// reverse linkedlist using stack
	void reverse_stack()
	{
		// Create a stack "s" of Node type
		stack<Node*> s;
		Node* temp = head;
		while (temp->next != NULL) {
			// Push all the nodes in to stack
			s.push(temp);
			temp = temp->next;
		}

		head = temp;

		while (!s.empty()) {
			// Store the top value of stack in list
			temp->next = s.top();
			// Pop the value from stack
			s.pop();
			// update the next pointer in the list
			temp = temp->next;
		}

		temp->next = NULL;

	}



	void print() {

		struct Node* temp = head;

		while (temp != NULL ) {

			cout << (temp -> data) << " ";
			temp = temp -> next;

		}
	}

	void push(int data) {

		Node* temp = new Node(data);
		temp -> next = head;
		head = temp;
	}
};

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