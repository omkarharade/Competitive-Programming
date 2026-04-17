#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


class Stack {

	int top;
	int size;
	int *arr;


public:
	Stack() {

		cout << "stack constructor invoked" << nline;
		top = -1;
		size = 1000;
		arr = new int[size];
	}

	void push(int data) {

		// check if the stack is full
		// if it is full, print 'Stack Overflow'

		if (top + 1 >= size) {

			cout << "Stack Overflow" << nline;
			return;
		}

		// add element to the top of the stack
		// increment the top

		arr[++top] = data;
		cout << "Pushed " << data << " to Stack" << nline;



	}

	int pop() {

		// check if the stack is empty
		// if empty, print 'Stack Underflow'

		if (isEmpty()) {
			cout << "Stack Underflow" << nline;
			return -1;
		}


		// if stack not empty
		// remove an element from the top
		// decrement the top

		return arr[top--];
	}


	int peek() {

		// if stack is empty
		// print 'Stack is empty'

		if (isEmpty()) {

			cout << "Stack is empty" << nline;
			return -1;
		}

		// return the top element of the stack
		return arr[top];
	}


	int getSize() {

		// as array is zero indexed
		return top + 1;
	}


	bool isEmpty()
	{
		// Return true if the stack is empty (i.e., top is
		// -1)
		return (top < 0);
	}
};

int main() {

	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.pop() << nline;
	cout << s.pop() << nline;
	cout << s.pop() << nline;
	cout << s.pop() << nline;

	cout << "stack current size is : " << s.getSize() << nline;



	return 0;
}