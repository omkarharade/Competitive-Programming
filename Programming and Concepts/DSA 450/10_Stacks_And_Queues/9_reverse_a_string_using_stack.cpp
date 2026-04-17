#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*
	basic solution:
	--------------------
	time: O(n) Only one traversal to push and one to pop so O(n)+O(n) = O(n).
	auxiliary space: O(n) Due to the stack
*/


class Solution {

public:
	string reverse(const string& S) {
		// code here

		int strLen = S.length();

		char* stack = new char[strLen + 10];
		int topIndex = 0;

		// storing the string contents in the stack
		for (int i = 0; i < strLen; i++) {
			stack[i] = S[i];
		}

		string returnStr;

		// appending the stack data back to new string variable
		// the smaller the stack array index the lower is the element in the stack
		// the element with the higher array index is the top element in the stack

		for (int i = strLen - 1; i >= 0; i--) {

			returnStr.push_back(stack[i]);
		}

		return returnStr;
	}
};


int main() {


	return 0;
}