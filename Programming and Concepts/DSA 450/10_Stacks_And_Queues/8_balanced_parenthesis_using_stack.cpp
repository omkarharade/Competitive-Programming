#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

	basic solution:
	--------------------
	time: O(n)
	auxiliary space: O(n) --- (using stack)

*/

class Solution {
public:

	bool isOpenBracket(char ch) {

		return ch == '{' || ch == '[' || ch == '(';
	}

	bool isCloseBracket(char ch) {

		return ch == '}' || ch == ']' || ch == ')';
	}

	bool isCurl(char ch) {

		return ch == '}' || ch == '{';
	}

	bool isRound(char ch) {

		return ch == '(' || ch == ')';
	}

	bool isSquare(char ch) {

		return ch == '[' || ch == ']';
	}


	bool isBalanced(string& s) {
		// code here
		char randomCh = '?';

		int strLength = s.length();

		// this is my array as stack
		char* arr = new char[strLength + 10];


		int topIndex = -1;

		for (int i = 0; i < strLength; i++) {

			char currentBracket = s[i];


			if (isOpenBracket(currentBracket)) {

				arr[++topIndex] = currentBracket;
			}

			else {

				char currStackCh = arr[topIndex];

				// if no opening bracket present
				if (topIndex == -1) return false;


				if (isCurl(currentBracket) && isCurl(currStackCh)) {
					arr[topIndex--] = randomCh;
				}
				else if (isSquare(currentBracket) && isSquare(currStackCh)) {
					arr[topIndex--] = randomCh;
				}
				else if (isRound(currentBracket) && isRound(currStackCh)) {
					arr[topIndex--] = randomCh;
				}
				else {
					return false;
				}

			}
		}


		return (topIndex == -1);
	}
};



// optimised solution with time: O(n) | space: O(1)

class Solution2 {
public:

	bool isOpenBracket(char ch) {

		return ch == '{' || ch == '[' || ch == '(';
	}

	bool isCloseBracket(char ch) {

		return ch == '}' || ch == ']' || ch == ')';
	}

	bool isCurl(char ch) {

		return ch == '}' || ch == '{';
	}

	bool isRound(char ch) {

		return ch == '(' || ch == ')';
	}

	bool isSquare(char ch) {

		return ch == '[' || ch == ']';
	}


	bool isBalanced(string& s) {
		// code here
		char randomCh = '?';

		int strLength = s.length();

		int topIndex = -1;


		for (int i = 0; i < strLength; i++) {

			char currentBracket = s[i];


			if (isOpenBracket(currentBracket)) {

				s[++topIndex] = currentBracket;
			}

			else {

				// if no opening bracket present
				if (topIndex == -1) return false;


				char currStackCh = s[topIndex];

				if (isCurl(currentBracket) && isCurl(currStackCh)) {
					topIndex--;
				}
				else if (isSquare(currentBracket) && isSquare(currStackCh)) {
					topIndex--;
				}
				else if (isRound(currentBracket) && isRound(currStackCh)) {
					topIndex--;
				}
				else {
					return false;
				}

			}
		}


		return (topIndex == -1);
	}
};

int main() {


	return 0;
}