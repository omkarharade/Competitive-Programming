#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


struct Node {

	int data;
	Node* next;

	Node(int val) {

		data = val;
		next = NULL;
	}
};

Node* insert_begin(Node* head, int val) {

	Node* newNode = new Node(val);

	newNode -> next = head;
	head = newNode;

	cout << "insert at Begin Process Completed" << nline;

	return head;
}


Node* insert_end(Node* head, int val) {

	Node* temp = head;
	Node* newNode = new Node(val);

	while (temp -> next != NULL)
		temp = temp -> next;

	temp -> next = newNode;

	cout << "insert at End Process Completed" << nline;
	return head;
}



Node* insert_node_after_given_node(Node* head, int newVal, int nodeVal ) {

	Node* temp = head;

	while (temp -> next  != NULL and temp -> next -> data != nodeVal) {

		temp = temp -> next;
	}

	Node* newNode = new Node(newVal);
	newNode -> next = temp -> next;
	temp -> next = newNode;

	return head;

}

void print(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << nline;
}

int main() {

	// ............creating a linkedList........................

	Node* head = new Node(12);
	Node* currNode = head;

	Node* node2 = new Node(13);
	currNode -> next = node2;
	currNode = currNode -> next;

	Node* node3 = new Node(14);
	currNode -> next = node3;
	currNode = currNode -> next;

	Node* node4 = new Node(15);
	currNode -> next = node4;
	currNode = currNode -> next;

	Node* node5 = new Node(16);
	currNode -> next = node5;
	print(head);

	//................................................................

	head = insert_end(head, 100);
	head = insert_end(head, 200);
	print(head);

	head = insert_begin(head, 300);
	head = insert_begin(head, 600);
	head = insert_begin(head, 10);
	print(head);


	head = insert_node_after_given_node(head, 1000000, 15);
	print(head);



	return 0;
}