#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class Node {
public:
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = nullptr;
	}
};

class LinkedStack {

	Node* top;
	int size;
	int currentSize;

public:

	LinkedStack() {

		top = nullptr;
		size = 1000;
		currentSize = 0;

	}

	void push(int data) {

		if (currentSize == size) {

			cout << "Stack Overflow" << nline;
			return;
		}

		Node* temp = new Node(data);
		temp -> next = top;
		top = temp;

		currentSize++;
	}


	int pop() {

		if (top == nullptr) {

			cout << "Stack Underflow" << nline;
			return -1;
		}

		Node* temp = top;
		top  = top -> next;
		int val = temp -> data;

		delete(temp);
		currentSize--;

		return val;
	}

	int peek() {

		if (top == nullptr) {
			cout << "Stack is empty" << nline;
			return -1;
		}

		return top -> data;
	}

	bool isEmpty() {

		return top == nullptr;
	}


	void print() {

		Node* temp = top;

		while (temp != nullptr) {

			cout << "| " <<  temp -> data << " | --> ";
			temp = temp -> next;
		}

		cout << " NULL " nline;
	}
};

int main() {

	LinkedStack linkedStack;

	// Adding elements to the stack

	linkedStack.push(12);
	linkedStack.push(15);
	linkedStack.push(20);


	// print the stack

	linkedStack.print();


	// remove a element from the stack
	linkedStack.pop();


	// again print the stack
	linkedStack.print();

	return 0;
}