#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


class TwoStacks {

	int* arr;
	int size;
	int top1;
	int top2;

public:

	TwoStacks(int s) {

		size = s;
		arr = new int[s];
		top1 = -1;
		top2 = (size / 2) - 1;


		/*
			in this solution we are splitting the array
			into 2 equal partition each of them taking
			exactly half of the fixed array size

			drawback: even if one of the stacks have
			less elements, they will take half of the
			space anyways
		*/
	}


	void push1(int data) {

		if (top1 == size / 2 - 1) {

			cout << "Stack Overflow on Stack 1" << nline;
			return;
		}

		arr[++top1] = data;
	}

	void push2(int data) {

		if (top2 == size - 1) {

			cout << "Stack Overflow on Stack 2" << nline;
			return;
		}

		arr[++top2] = data;
	}

	int pop1() {

		if (top1 == -1) {

			cout << "Stack Underflow on Stack 1" << nline;
			return -1;
		}

		return arr[top1--];
	}


	int pop2() {

		if (top2 == size / 2 - 1) {

			cout << "Stack Underflow on Stack 2" << nline;
			return -1;
		}

		return arr[top2--];
	}

	void printTwoStacks() {

		cout << "Stack 1 : ";
		for (int i = 0; i <= top1; i++) {

			cout << " | " <<  arr[i] << " | ";
		}

		cout << nline;


		cout << "Stack 2 : ";
		for (int i = size / 2; i <= top2; i++) {

			cout << " | " <<  arr[i] << " | ";
		}

		cout << "\n" <<  nline;
	}



};



class TwoStacks2 {


	int* arr;
	int size;
	int top1;
	int top2;

public:

	TwoStacks2(int s) {

		size = s;
		arr = new int[s];
		top1 = -1; // initialized with -1 (one value less than lowest index 0)
		top2 = size; // initialized with size (one value more than the highest index ie. fixed size)

	}

	/*
		In this optimised solution we are going to use
		space such a way that, the first stack starts filling
		from left to right and the second stack starts filling
		from right to left.

		doing so there are no unnecessary space occupancy from
		either of the stacks
	*/

	void push1(int data) {

		if (top1 + 1 == top2) {

			cout << "Stack Overflow on Stack 1" << nline;
			return;
		}

		arr[++top1] = data;

	}

	void push2(int data) {

		if (top2 - 1 == top1) {

			cout << "Stack Overflow on Stack 2" << nline;
			return;
		}

		arr[--top2] = data;

	}


	int pop1() {

		if (top1 == -1) {

			cout << "Stack Underflow on Stack 1" << nline;
			return -1;
		}

		return arr[top1--];
	}

	int pop2() {

		if (top2 == size) {

			cout << "Stack Underflow on Stack 2" << nline;
			return -1;
		}

		return arr[top2++];

	}


	void printTwoStacks() {


		cout << "Stack 1 : ";
		for (int i = 0; i <= top1; i++) {

			cout << " | " <<  arr[i] << " | ";
		}

		cout << nline;


		cout << "Stack 2 : ";
		for (int i = size - 1; i >= top2; i--) {

			cout << " | " <<  arr[i] << " | ";
		}

		cout << "\n" <<  nline;
	}

};


int main() {

	TwoStacks ts(20);

	ts.push1(5);
	ts.push1(10);
	ts.push1(15);
	ts.push1(20);
	ts.push1(25);

	ts.push2(100);
	ts.push2(95);
	ts.push2(90);


	ts.printTwoStacks();

	ts.pop1();
	ts.pop1();

	ts.pop2();

	ts.printTwoStacks();



	TwoStacks2 ts2(20);

	ts2.push1(50);
	ts2.push1(55);
	ts2.push1(60);
	ts2.push1(65);
	ts2.push1(70);

	ts2.push2(10);
	ts2.push2(20);
	ts2.push2(30);

	ts2.printTwoStacks();

	ts2.pop1();
	ts2.pop1();

	ts2.pop2();

	ts2.printTwoStacks();

	return 0;
}