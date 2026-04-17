#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class MinStack {

	stack<pair<int, int>> minStack;

public:

	void push(int a) {

		if (minStack.empty()) {

			minStack.push({a, a});
		}
		else {

			pair<int, int> currTop = minStack.top();
			minStack.push({a, min(currTop.second, a)});
		}
	}

	bool isFull(int n) {
		// Your code goes here

		return (minStack.size() == n);
	}

	bool isEmpty() {
		// Your code goes here

		return (minStack.empty());
	}

	int pop() {
		// Your code goes here

		pair<int, int> currTop = minStack.top();
		minStack.pop();

		return currTop.first;
	}

	int getMin() {

		// Your code goes here

		pair<int, int> currTop = minStack.top();
		return currTop.second;
	}

};



class MinStack2 {

	stack<int> stk;
	int curr_min = INT_MAX;


public:

	void push(int a) {

		if (stk.empty()) {

			curr_min = a;
			stk.push(a);
		}
		else if (a >= curr_min) {

			// if the new element is bigger than the current minimum
			// push it directly into the stack

			// ie. If a >= curr_min, push a normally.

			stk.push(a);

		}
		else {

			// if curr_min > a
			// we need to store some value in stack so that
			// we can retrieve the previous minimum using the value in stack

			// ie. If a < curr_min, push 2*a - curr_min and update curr_min = a (this encodes the previous min).
			// (Hint: 2*a - curr_min value is smaller than a)

			stk.push(2 * a - curr_min);
			curr_min = a;
		}
	}

	bool isFull(int n) {
		// Your code goes here

		return (stk.size() == n);
	}

	bool isEmpty() {
		// Your code goes here

		return (stk.empty());
	}

	int pop() {
		// Your code goes here

		int top = stk.top();
		stk.pop();

		if (top >= curr_min) {

			// If the removed element (top) is >= curr_min, no change in curr_min.

			return top;
		}
		else {

			// according to the formula used during push operation
			// below is the formula derived from it to get the prev min value

			// If the removed element (top) is < curr_min,
			// update curr_min = 2*curr_min - top (decoding the previous min).

			int prev_min = 2 * curr_min - top;
			curr_min = prev_min;

			return prev_min;
		}
	}

	int getMin() {

		// Your code goes here
		return curr_min;
	}

};

int main() {


	MinStack minStack;

	minStack.push(20);
	minStack.push(40);
	minStack.push(100);
	minStack.push(10);

	cout << "using solution 1" << nline;
	cout << minStack.getMin() << nline;
	minStack.pop();

	cout << minStack.getMin() << nline;
	minStack.pop();

	cout << minStack.getMin() << nline;



	cout << "\n\n";

	MinStack2 minStack2;

	minStack2.push(20);
	minStack2.push(40);
	minStack2.push(100);
	minStack2.push(10);

	cout << "using solution 2" << nline;
	cout << minStack2.getMin() << nline;
	minStack2.pop();

	cout << minStack2.getMin() << nline;
	minStack2.pop();

	cout << minStack2.getMin() << nline;


	return 0;
}