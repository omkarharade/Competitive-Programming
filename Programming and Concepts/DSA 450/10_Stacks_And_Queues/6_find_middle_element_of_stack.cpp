#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



/*
	Question: Design a stack with operations on middle element
	link: https://www.geeksforgeeks.org/dsa/design-a-stack-with-find-middle-operation/


	Design a stack data structure that supports the following four operations, each in constant time complexity, i.e., O(1):

	push(x): Insert an element x onto the top of the stack.
	pop(): Remove and return the element at the top of the stack.
	findMiddle(): Retrieve the middle element of the stack without removing it.
	deleteMiddle(): Remove the middle element from the stack.
*/


class Node {

public:

	int data;
	Node* prev;
	Node* next;

	Node(int d) {

		data = d;
		prev = nullptr;
		next = nullptr;
	}
};


class MyStack {

	Node* top;
	Node* mid;
	int size;
	int capacity;


public:

	MyStack(int c) {

		top = nullptr;
		mid = nullptr;
		size = 0;
		capacity = c;
	}

	bool isFull() {

		return size == capacity;
	}



	void push(int new_data) {

		if (isFull()) {

			cout << "Stack Overflow" << nline;
			return;
		}


		Node* newData = new Node(new_data);


		if (top == nullptr) {

			top = mid = newData;
		}
		else {

			newData -> next = top;
			top -> prev = newData;
			top = newData;

			if (size % 2 == 0) {

				mid = mid -> prev;
			}
		}

		size++;
	}


	int pop() {

		if (top == nullptr) {

			cout << "Stack Underflow" << nline;
			return -1;
		}

		if (size == 1) {

			Node* temp = top;
			int popped_data = temp -> data;

			top = mid = nullptr;
			delete(temp);
			size--;
			return popped_data;
		}

		else {

			Node* temp = top;
			int popped_data = temp -> data;

			top = top -> next;
			delete(temp);


			if (size % 2 != 0) {
				mid = mid -> next;
			}
			size--;
			return popped_data;
		}
	}

	int findMiddle() {

		if (top == nullptr) {
			return -1;
		}

		return mid -> data;
	}


	void print() {

		cout << " NULL <-";

		Node* temp = top;

		while (temp != nullptr) {

			cout << "-> | " << temp -> data << " | <-";
			temp = temp -> next;
		}

		cout << "-> NULL " << nline;
	}

};

int main() {


	MyStack ms(30);

	ms.push(20);
	ms.push(30);
	ms.push(40);
	ms.push(50);
	ms.push(60);

	cout << "mid of the stack is " << ms.findMiddle() << nline;

	ms.print();

	return 0;
}


