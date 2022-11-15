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

void print(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << nline;
}

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

	while (temp -> next  != NULL and temp ->  data != nodeVal) {

		temp = temp -> next;
	}

	Node* newNode = new Node(newVal);
	newNode -> next = temp -> next;
	temp -> next = newNode;

	return head;

}

Node* insert_node_before_given_node(Node* head, int newVal, int nodeVal) {

	Node* temp = head;

	while (temp -> next  != NULL and temp -> next -> data != newVal) {

		temp = temp -> next;
	}

	Node* newNode = new Node(newVal);
	newNode -> next = temp -> next;
	temp -> next = newNode;
	return head;
}

Node* delete_begin(Node* head) {

	Node* temp = head;
	head = head -> next;

	free(temp);
	cout << "delete operation completed \nupdated list : " << nline;
	print(head);
	return head;

}

Node* delete_end(Node* head) {

	Node* temp = head;

	if (temp -> next == NULL) {
		free(temp);
		return NULL;
	}

	while (temp -> next != NULL) {
		temp = temp -> next;
	}

	temp = NULL;
	free(temp);
	return head;
}

Node* deleting_node_after_given_node(Node* head, int givenVal) {

	Node* temp = head;

	while (temp -> data != givenVal) {
		temp = temp -> next;
	}

	// now temp is pointing to the given value;

	if (temp -> next != NULL) {

		// if there is a node present after given value;

		Node* delNode = temp -> next;

		if (delNode -> next != NULL) {

			// connecting the linklist chain if next node is present after deleteNode;

			temp -> next = delNode -> next;
		}
		delNode = NULL;
		free(delNode);
	}

	return head;
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


	head = deleting_node_after_given_node(head, 13);
	print(head);



	return 0;
}