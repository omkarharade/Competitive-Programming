#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


class ArrayQueue {

	// array to store queue elements
	int* arr;


	// maximum number of elements the queue can hold
	int capacity;


	// current number of elements in the queue
	int size;


public:

	ArrayQueue(int cap) {

		capacity = cap;
		arr = new int[capacity];
		size = 0;
	}

	void enqueue(int data) {

		// check current size, if size is equal to capacity
		// this is OVERFLOW condition

		if (size == capacity) {

			cout << "Queue Overflow" << nline;
			return;
		}

		// add the element to the array (after the current last element)
		arr[size++] = data;
	}


	int dequeue() {

		// check if the queue is empty
		if (size == 0) {

			cout << "Queue Underflow" << nline;
			return -1;
		}

		// store the first element of the queue (this element is removed)
		int data = arr[0];


		// shift all the elements to left by 1
		for (int i = 0; i + 1 < size; i++) {

			arr[i] = arr[i + 1];
		}

		// update the size
		size--;

		// return the removed element / data
		return data;
	}


	int peek() {

		// check if the queue is empty
		if (size == 0) {

			cout << "Queue Underflow" << nline;
			return -1;
		}


		// return the first element of the queue
		return arr[0];

	}


	void print() {

		for (int i = 0; i < size; i++) {

			cout << " | " <<  arr[i] << " | ";
		}

		cout << nline;
	}
};

int main() {

	ArrayQueue queue(30);

	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);


	queue.print();

	queue.dequeue();
	queue.dequeue();

	queue.print();

	return 0;
}