#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

// lets define MAX (max size of stack) to be 1000

const int MAX = 1000;
int TOP = -1; // -1 == NULL



void print(int stack[]) {

	for (int i = TOP; i >= 0; i--) {
		cout << stack[i] << " ";
	}
	cout << nline;
}

void push(int stack[], int val) {

	if (TOP == MAX - 1) {
		cout << "Stack Overflow : Max Stack size reached" << nline;
		return;
	}

	TOP++;
	stack[TOP] = val;
}

void pop(int stack[]) {

	if (TOP == -1) {
		cout << "Stack Underflow" << nline;
		return;
	}

	TOP--;
}

int peek(int stack[]) {
	if (TOP == -1) {
		cout << "Stack is empty" << nline;
		return -1;
	}
	else {

		return stack[TOP];
	}
}

int main() {

	int stack[MAX];
	push(stack, 0);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);

	print(stack);
	pop(stack);
	pop(stack);
	push(stack, 1000);
	print(stack);
	cout << peek(stack) << nline;


	return 0;
}