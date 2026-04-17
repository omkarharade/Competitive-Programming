#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class Node {
public:
	int data;

	Node* next;

	Node(int new_data) {
		data = new_data;
		next = nullptr;
	}

};


class LinkedQueue {

	int capacity;
	int size;
	Node* front;
	Node* rear;

public:

	LinkedQueue(int cap) {
		capacity = cap;
		front = rear = nullptr;
		size = 0;

	}

	bool isEmpty() {

		return (front == nullptr && rear == nullptr);
	}

	bool isFull() {

		return (size == capacity);
	}

	void enqueue(int new_data) {

		// check if capacity is full
		if (isFull()) {

			cout << "Queue Overflow" << nline;
			return;
		}


		// create a new node with the new_data
		Node* newData = new Node(new_data);


		// check if queue is empty
		if (isEmpty()) {

			// initialize front and rear with the newData node
			front = rear = newData;
		}
		else {

			// put newData node to next of rear and update the rear
			rear -> next = newData;
			rear = rear -> next;
		}

		size++;
	}


	int dequeue() {

		// check if queue is empty
		if (isEmpty()) {

			cout << "Queue Underflow" << nline;
			return -1;
		}

		// get the first element from the queue
		int data = front -> data;

		// we need to remove the first element from queue
		// so store the node in temp node
		Node* temp = front;

		// shift the front node to the next node
		// (as the current front node will be removed)
		front = front -> next;


		// delete the former front node
		delete temp;

		// reduce the size count
		size--;


		// return the data / value inside the removed node
		return data;
	}


	int peek() {

		// check if queue is empty

		if (isEmpty()) {

			cout << "Queue Is Empty" << nline;
			return -1;
		}

		return front -> data;
	}


	void print() {

		if (front == nullptr) {
			cout << "Queue is empty" << nline;
			return;
		}

		Node* temp = front;

		while (temp != nullptr) {

			cout << " | " << temp -> data << " | --> ";
			temp = temp -> next;
		}

		cout << " NULL " << nline;

	}

};

int main() {

	LinkedQueue linkedQueue(30);

	linkedQueue.enqueue(10);
	linkedQueue.enqueue(20);
	linkedQueue.enqueue(30);
	linkedQueue.enqueue(40);
	linkedQueue.enqueue(50);


	linkedQueue.print();

	linkedQueue.dequeue();
	linkedQueue.dequeue();

	linkedQueue.print();

	return 0;
}