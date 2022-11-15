#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

struct Stack
{
	int data;
	Stack* next;

	Stack(int val) {

		data = val;
		next = NULL;
	}
};

void print(Stack* top) {

	Stack* temp = top;

	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << nline;
}


void push(Stack* top, int val) {
	Stack* newNode = new Stack(val);

	if (top == NULL) {
		top = newNode;
	}
	else {

		newNode -> next = top;
		top = newNode;
	}
}

void pop(Stack* top) {

	if (top == NULL) {
		cout << "stack underflow" << nline;
		return;
	}
	else {
		Stack* temp = top;
		top = top -> next;
		free(temp);
	}
}

int peek(Stack* top) {

	if (top == NULL) {
		cout << "Stack is empty" << nline;
		return -1;
	}
	else {
		return  top -> data;
	}
}

int main() {

	struct Stack* stack;

	if (stack == NULL) cout << "NULL" << nline;



	return 0;
}